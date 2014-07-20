#include <iostream>
#include <stdio.h>
#include <cstdlib>


using namespace std;

// T order of  btree;

const int T = 3;
const int maxc = T + T;
const int maxd = T + T - 1;

typedef int elem;

struct node {
    elem data[T + T - 1];
    node *child[T+T];
    int cnt;
    bool leaf;
    node(){
        for(int i=0; i<T; i++){
            data[i] = 0;
            child[i] = NULL;
        }
        child[T] = NULL;
        cnt = 0;
        leaf = true;
    }
};

enum  status { OK,FAILED,REPEAT };
//create btree

status BtreeAlloc(node* &root){
    status ret = OK;
    root = new node();
    if(root==NULL) return FAILED;
    return ret;
}

// insert key in the tree;
status Insert(int key, node* &root){
    status ret = FAILED;

    return ret;
}

int bsearch(int key, int *a, int len){
    int ll = 0;
    int rr = len;
    int m = 0;
    if( key > a[len-1] ) return len;
    if( key < a[0] ) return 0;
    while(ll <= rr){
        m = (ll + rr)>>1;
        if(key == a[m]) return m;
        else if(key < a[m]) rr = m - 1;
        else ll = m + 1;
    }
    return ll;
}

void BtreeSplitChild(node *&x, int i, node *&y){
    node *tmp = new node();
    tmp->leaf = y->leaf;
    tmp->cnt = T - 1;
    for(int j = 0; j<T-1; j++){
        tmp->data[j] = y->data[j+T];
    }
    if(!y->leaf){
        for(int j = 0; j<T; j++){
            tmp->child[j] = y->child[j+T];
        }
    }
    y->cnt = T -1;
    for(int j = x->cnt+1; j > i+1; j--){
        x->child[j] = x->child[j-1];
    }
    x->child[i+1] = tmp;
    for( int j = x->cnt; j>i; j--){
        x->data[j] = x->data[j-1];
    }
    x->data[i] = y->data[T];
}

// delete key in tree;

status Drop(int key, node* &root){
    status ret = FAILED;
    return ret;
}

// print tree

// search key in tree

//          

int main(){
    node * root;
    BtreeAlloc(root);
    printf("root->cnt %d\n",root->cnt);
    return 0;
}
