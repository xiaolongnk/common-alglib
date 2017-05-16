#include <stdio.h>
#include <malloc.h>

typedef struct link_node * l_n_ptr;
typedef struct link_node l_n;

struct link_node {
    int num;
    l_n_ptr next;
};

l_n_ptr init_node(int cnt)
{
    l_n_ptr head = NULL , current = NULL;
    int i = 1;
    while(i <= cnt) {
        if(head == NULL) {
            head = (l_n_ptr) malloc(sizeof(l_n));
            current = head;
            current->num  = i;
        } else {
            l_n_ptr tmp = (l_n_ptr) malloc(sizeof(l_n));
            tmp->num = i;
            tmp->next = NULL;
            current->next = tmp;
            current = current->next;
        }
        ++i;
    }
    // make this link_list to be a circle;
    current->next = head;
    return head;
}



void print_link_list(const l_n_ptr head) 
{
    return;
    l_n_ptr m = head;
    while(m)  {
        printf("%d  " , m->num);
        m = m->next;
    }
    printf("\n");
}

void process(const l_n_ptr head , const int start_pos , const int total , const int kill_number) 
{
    int i = 0;
    l_n_ptr tmp = head;
    while(i < start_pos) tmp = tmp->next;

    int m_killed = 0;
    int m_kill_number = 1;
    l_n_ptr last_node = NULL;
    while(killed < total - 1) {
        if(m_kill_number == kill_number) {
            // remove this node
            last_node->next = tmp->next;
            printf("tmp as killed %d\n" , tmp->num);
            tmp->next = null;
            free(tmp); // it's very important.
            ++m_killed;
        } else {
            last_node = tmp;
            tmp = tmp->next;

        }
        ++m_kill_number;
    }
}

int main()
{
    int start_pos , total , kill_number;
    printf("please input your start position and number of people and kill number:");
    scanf("%d%d%d" , start_pos , total , kill_number);
    l_n_ptr head = init_node(10);
    process(head , start_pos , total , kill_number);
    return 0;
}
