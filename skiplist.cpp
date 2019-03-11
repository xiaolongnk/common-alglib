#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_LEVEL 20

typedef struct node {
    node * right;
    node * down;
    int key;
} data_node ;

struct skip_list {
    data_node ** header;
    int current_level;
};

node * height[MAX_LEVEL];

int get_current_level()
{
    int k = 0;
    while(rand()%2) ++k;
    return k;
}

skip_list * skip_list_init()
{
    srand((unsigned)time(NULL));
    skip_list * sl;
    sl = new skip_list();
    sl->current_level = 0;
    sl->header = new data_node* [MAX_LEVEL];
    for(int i = 0; i< MAX_LEVEL; ++i) {
        sl->header[i] = NULL; 
    }
    return sl;
}

node * find_x_from_skip_list(skip_list * sl, int x)
{
    node *h = sl->header[sl->current_level];
    while(h) {
        if (x > h->key) {
            h = h->right;
        } else {
            if (h->down) {
                h = h->down;
            } else {
                return h; 
            }     
        }
    }
    return NULL;
}

node * insert_x_into_list(node * head, int x)
{
    while(head && x > head->key) {
        head = head->right; 
    }
    node * n = new node;
    n->key = x;
    n->right = NULL;
    n->down = NULL;
    head->right = n;
    return n;
}

int insert_x_into_skip_list(skip_list * sl, int x)
{
    int level = get_current_level();
    if (level > sl->current_level) {
        ++sl->current_level; 
    }
    for(int i =sl->current_level ; i>= 0; --i) {
        // insert x into single link list
        height[i] = insert_x_into_list(sl->header[i], x);
    }
    for(int i = sl->current_level; i ; --i) {
        height[i]->down = height[i-1];
    }
    return 0;
}


int remove_data_from_list(node *head, int x)
{
    node * prev = NULL, * true_head = head;
    while(head) {
        if (head->key == x) {
            if (prev) {
                prev->right = head->right;
            }
            delete head;
        } else {
            prev = head;
            head = head->right;
        }
    }
    return 0;
}

int remove_x_from_skip_list (skip_list * sl, int x)
{
    for(int i =0; i<=sl->current_level; ++i) {
        remove_data_from_list(sl->header[i], x);
    }
    return 0;
}

int print_list(skip_list *sl)
{
    if (sl->current_level) {
        node * current = sl->header[0];
        while(current) {
            cout<<current->key<<"  "; 
            current = current->right;
        }
        cout<<endl;
    }
    return 0;
}

int main()
{
    skip_list * sl = skip_list_init();
    print_list(sl);
    return 0;
}
