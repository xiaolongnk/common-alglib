#include <stdio.h>


#define MAX_NUMBER 1000

typedef struct phone_book_item {
    int id;
    char name[128];
    char number[64];
} pb_item;

typedef pb_item * pb_item_ptr;

struct phone_book {
    pb_item content[MAX_NUMBER];
    int current_number;
    char book_name[64];
    int (*list_phones)();
    int (*search_by_keywords)(char *);
    int (*save_to_file_db)();
    int (*read_from_file_db)();
    void (*show_usage)();
    int (*add_new_record)(pb_item_ptr);
} m_p_book;

typedef struct phone_book * pb_ptr;

int gen_pb_item(pb_item_ptr item)
{
    printf("a pb_item generated\n");
    return 0;
}

int list_phones()
{
    printf("Hi , nothing here\n");
    return 0;
}

int search_by_keywords(char *key)
{
    printf("here , in search by keywords\n");
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


int save_to_file_db()
{
    printf("save to file finished\n");
    return 0;
}

int read_from_file_db()
{
    printf("read from file finished\n");
    return 0;
}

int add_new_record(pb_item_ptr item)
{
    printf("add record finished\n");
    return 0;
}

void init_phone_book(pb_ptr pbook)
{
    (*pbook).add_new_record     = add_new_record;
    (*pbook).list_phones        = list_phones;
    (*pbook).search_by_keywords = search_by_keywords;
    (*pbook).save_to_file_db    = save_to_file_db;
    (*pbook).read_from_file_db  = read_from_file_db;
    (*pbook).show_usage         = show_usage;

    (*pbook).read_from_file_db();
}

void interactive_loop(pb_ptr pbook)
{
    printf("Welcome to use phone book v1.0\n");
    (*pbook).show_usage();
    char op;
    while(1) {
        scanf("%c",&op);
        switch(op) {
            case '1':
                {
                    pb_item_ptr pb;
                    (*pbook).add_new_record(pb);
                }
                break;
            case '2':
                (*pbook).list_phones();
                break;
            case '3':
                {
                    char * keywords;
                    (*pbook).search_by_keywords(keywords);
                }
                break;
            case '4':
                (*pbook).save_to_file_db();
                break;
            case '5':
                (*pbook).show_usage();
                break;
            case '6':
                printf("thanks to use . Have a nice day!\n");
                return ;
                break;
        }

    }
    return;
}

int main()
{
    init_phone_book(&m_p_book);
    interactive_loop(&m_p_book);
    return 0;
}
