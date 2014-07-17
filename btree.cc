#include <iostream>
#include <stdio.h>
#include <cstdlib>


using namespace std;


#define N 3

typedef int elem;

struct node {
    elem data[N];
    node *child[N+1];
    int cnt;
    bool leaf;
    node(){
        for(int i=0; i<N; i++){
            data[i] = 0;
            child[i] = NULL;
        }
        child[N] = NULL;
        cnt = 0;
        leaf = true;
    }
};

enum  status { OK,FAILED,REPEAT };
// create btree

status BtreeAlloc(node* &root){
    status ret = OK;
    root = new node();
    if(root==NULL) return FAILED;
    root->cnt = 10;
    return ret;
}

// insert key in the tree;
status Insert(int key, node* &root){
    status ret = FAILED;

    return ret;
}

void BtreeSplitChild(node *&x, int i, node *&y){
    node *tmp = new node();
    tmp->leaf = true;
    int t = N/2 - 1;
    tmp->cnt = t;
    for(int j = 0; j<t; j++){
        tmp->data[j] = x->data[j+t];
    }


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

