#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_LEVEL 30

#define DEBUG 1

typedef struct node {
    node * right;
    node * down;
    int key;
} data_node ;

struct skip_list {
    data_node ** header;
    int max_level;
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
    sl->max_level = 0;
    sl->header = new data_node* [MAX_LEVEL];
    for(int i = 0; i< MAX_LEVEL; ++i) {
        data_node * t = new data_node();
        t->key = -1;
        t->right = NULL;
        sl->header[i] = t;
    }
    for(int i = MAX_LEVEL -1; i; --i) {
        sl->header[i]->down = sl->header[i-1]; 
    }
    return sl;
}

data_node * find_x_from_skip_list(skip_list * sl, int x)
{
    data_node *h = sl->header[sl->max_level];
    while(h) {
        if (h->right && x > h->right->key) {
            h = h->right;
        } else {
            if (h->down) {
                h = h->down;
            } else {
                if (x == h->key) {
                    return h; 
                }
                h = h->right;
            }
        }
    }
    return h;
}

data_node * insert_x_into_list(node * head, int x)
{

    node * prev = NULL;
    while(head && x > head->key) {
        prev = head;
        head = head->right; 
    }
    node * n = new node;
    n->key = x;
    n->right = NULL;
    n->down = NULL;
    if (prev == NULL) {
        if (head) {
            n->right = head->right;
        } else {
            head = n;
        }
    } else {
        prev->right = n;
        n->right = head;
    }
    return n;
}

int insert_x_into_skip_list(skip_list * sl, int x)
{
    int current_level = get_current_level();
    if (current_level > sl->max_level) {
        sl->max_level = current_level;
    }
#ifdef DEBUG
    cout<<"current_level "<<current_level<<" insert "<<x<<endl;
#endif
    for(int i = current_level; i>= 0; --i) {
        // insert x into single link list
        height[i] = insert_x_into_list(sl->header[i], x);
    }
    for(int i = sl->max_level; i ; --i) {
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
    for(int i =0; i<=sl->max_level; ++i) {
        remove_data_from_list(sl->header[i], x);
    }
    return 0;
}

int print_list(skip_list *sl)
{
    for(int i = sl->max_level; i>=0 ; i--) {
        data_node * current = sl->header[i];
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
    for(int i = 0; i< 15; i++) {
        insert_x_into_skip_list(sl, i);
        print_list(sl);
    }
    for(int i = 0; i< 10; i++) {
        node * p = find_x_from_skip_list(sl, i);
        cout<<" find key "<<i<<endl;
    }
    return 0;
}
