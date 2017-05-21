/***
 * link list circle
 * link list reverse.
 * 2017-05-21 08:46
 */

#include <stdio.h>
#include <string.h>
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
    while( cnt < total )  {
        if( m == NULL) break;
        printf("%d  " , m->num);
        m = m->next;
        ++cnt;
    }
    printf("\n");
}



void p1 (const l_n_ptr head) 
{
    int cnt = 0;
    l_n_ptr m = head;
    while( m )  {
        printf("%d  " , m->num);
        m = m->next;
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
    return head;
}

/***
 * reverse the link list .
 */
int reverse_node( l_n_ptr *_head) {
    if((*_head) == NULL) return 0;
    l_n_ptr current = (*_head), prev = NULL , next = NULL;
    while( (current) != NULL) {
        (next) = (current)->next;
        (current)->next = (prev);
        (prev) = (current);
        (current) = (next);
    }
    *_head = prev;
    return 0;
}

int m_swap(int *a , int *b) {
    int *tmp = a;
    a = b;
    b = tmp;
}


int main()
{
    int n = 10;
    l_n_ptr head = init_node(10);
    print_link_list(head , 10);
    reverse_node(&head);
    print_link_list(head , 10);
    return 0;
}
