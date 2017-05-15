#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_NUMBER 1000
const char data_file_path[64] = "phone_book.txt";

void safe_flush()
{
    char ch;
    while(( ch = getchar()) != '\n' && ch!=EOF);
}

typedef struct phone_book_item {
    int id;
    char name[128];
    char number[64];
} pb_item;

typedef pb_item * pb_item_ptr;
typedef struct phone_book * pb_ptr;

struct phone_book {
    pb_item content[MAX_NUMBER];
    int current_number;
    char book_name[64];
    char data_file_path[64];
    int (*add_new_record)(pb_ptr , pb_item);
    int (*list_phones)(const pb_ptr);
    int (*search_by_keywords)(const pb_ptr , char *);
    int (*save_to_file_db)(const pb_ptr pbook);
    int (*read_from_file_db)(pb_ptr pbook);
    void (*show_usage)();
} m_p_book;

int add_new_record(pb_ptr pbook , pb_item item)
{
    item.id = pbook->current_number + 1;
    pbook->content[pbook->current_number++] = item;
    return 0;
}

void print_item(pb_item_ptr pbi)
{
    printf("id : %-10d\tname: %-20s\tnumber: %-20s\n" , 
            pbi->id , pbi->name , pbi->number);
}

int list_phones(const pb_ptr pbook)
{
    for(int i = 0 ; i < pbook->current_number ; ++i) {
        print_item(&pbook->content[i]);
    }
    return 0;
}

int search_by_keywords(const pb_ptr pbook , char *key)
{
    for(int i = 0 ; i < pbook->current_number ; ++i) {
        if(strstr(pbook->content[i].name , key) !=NULL) {
            printf("id : %d\t\tname:  %s\t\tnumber:  %s\n" , 
                    pbook->content[i].id , 
                    pbook->content[i].name , 
                    pbook->content[i].number);
        }
    }
    return 0;
}

int save_to_file_db(const pb_ptr pbook)
{
    FILE * fp = fopen(pbook->data_file_path , "wb");
    if(fp) { 
        for(int i = 0 ; i < pbook->current_number ; ++i) {
            if(i == pbook->current_number - 1) {
                fprintf(fp , "%d %s %s", pbook->content[i].id , 
                    pbook->content[i].name , pbook->content[i].number);
            } else {
                fprintf(fp , "%d %s %s\n", pbook->content[i].id , 
                    pbook->content[i].name , pbook->content[i].number);
            
            }
        }
        fclose(fp);
    } else {
        printf("file open failed\n");
    }
    return 0;
}

int read_from_file_db(pb_ptr pbook)
{
    FILE * fp = fopen(pbook->data_file_path , "rb");
    if(fp) {
        int cnt = 0;
        int tmp_id;
        while(!feof(fp)) {
            fscanf(fp , "%d%s%s" , &tmp_id,
                    pbook->content[cnt].name,
                    pbook->content[cnt].number);
            if(tmp_id == 0) break;
            pbook->content[cnt].id = tmp_id;
            print_item(&pbook->content[cnt]);
//            printf("%-5d %-20s\t%-20s\n" , pbook->content[cnt].id , pbook->content[cnt].name , pbook->content[cnt].number);
            pbook->current_number++;
            cnt++;
        }
    } else {
        printf("file oopen failed\n");
        return -1;
    }
    return 0;
}

void show_usage()
{
    printf("1: add record\n");
    printf("2: list all records\n");
    printf("3: search by name or number\n");
    printf("4: save\n");
    printf("5: show usage\n");
    printf("6: exit\n");
}

void interactive_loop(pb_ptr pbook)
{
    printf("Welcome to use phone book v1.0\n");
    pbook->show_usage();
    char op;
    while(1) {
        printf("please input [ 1-6 , 5 to help ] :->");
        scanf("%c",&op);
        safe_flush();
        switch(op) {
            case '1':
                {
                    pb_item pb;
                    printf("Please input name and number (seperate with blank space) :->");
                    scanf("%s%s",pb.name , pb.number);
                    safe_flush();
                    pbook->add_new_record(pbook , pb);
                    pbook->save_to_file_db(pbook);
                }
                break;
            case '2':
                pbook->list_phones(pbook);
                break;
            case '3':
                {
                    char keywords[128];
                    printf("Please input your keywords:");
                    scanf("%s",keywords);
                    safe_flush();
                    pbook->search_by_keywords(pbook , keywords);
                }
                break;
            case '4':
                pbook->save_to_file_db(pbook);
                break;
            case '5':
                pbook->show_usage();
                break;
            case '6':
                printf("thanks to use . Have a nice day!\n");
                return ;
                break;
            default:
                pbook->show_usage();
                break;
        }
    }
    return;
}


void init_phone_book(pb_ptr pbook)
{
    pbook->add_new_record     = add_new_record;
    pbook->list_phones        = list_phones;
    pbook->search_by_keywords = search_by_keywords;
    pbook->save_to_file_db    = save_to_file_db;
    pbook->read_from_file_db  = read_from_file_db;
    pbook->show_usage         = show_usage;

    pbook->current_number     = 0;
    strncpy(pbook->data_file_path,data_file_path,64);
    pbook->read_from_file_db(pbook);
}

int main()
{
    init_phone_book(&m_p_book);
    interactive_loop(&m_p_book);
    return 0;
}
