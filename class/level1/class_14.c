#include <stdio.h>
#include <malloc.h>

typedef struct link_node * l_n_ptr;
typedef struct link_node l_n;

struct link_node {
    int num;
    l_n_ptr next;
};

void print_link_list(const l_n_ptr head , int total) 
{
    int cnt = 0;
    l_n_ptr m = head;
    while(m)  {
        printf("%d  " , m->num);
        m = m->next;
        ++cnt;
        if(cnt >=total )  break;
    }
    printf("\n");
}

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

void process(const l_n_ptr head , const int start_pos , const int total , const int kill_number) 
{
    int i = 1;
    l_n_ptr tmp = head;
    while(i < start_pos) {
        tmp = tmp->next;
        ++i;
    }
    l_n_ptr start_node = tmp;

    // find the previous node 
    i = 0;
    while(i < total -1) {
        tmp = tmp->next;
        ++i;
    }
    l_n_ptr last_node = tmp;
    // length of the list should be 2 at least.
    if(last_node == head) {
        printf("this list contain only one element , no man would left!\n");
        return;
    }

    l_n_ptr junk = NULL;
    int m_killed   = 0;
    int m_kill_ptr = 0;
    while(m_killed < total - 1) {
        ++m_kill_ptr;
        if(m_kill_ptr == kill_number) {
            // remove this node
            printf("person [ %d ] was killed\n" ,start_node->num);
            last_node->next =start_node->next;
            start_node->next = NULL;
            free(start_node); // it's very important.
            ++m_killed;
            m_kill_ptr = 0;
            start_node =last_node->next;
        } else {
            last_node  = start_node;
            start_node = start_node->next;
        }
    }
    printf("only leaft person is %d\n" , start_node->num);
}

int main()
{
    int start_pos , total , kill_number;
    printf("please input your start position and number of people and kill number:");
    scanf("%d%d%d" , &start_pos , &total , &kill_number);
    l_n_ptr head = init_node(total);
    process(head , start_pos , total , kill_number);
    return 0;
}
