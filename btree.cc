#include <iostream>
#include <stdio.h>
#include <cstdlib>


using namespace std;

// T order of  btree;

const int T = 3;
const int maxc = T + T;
const int maxd = T + T - 1;

enum  status { OK,FAILED,REPEAT };
typedef int elem;


struct node {
    elem data[T + T - 1];
    node *child[T+T];
    int cnt;   // number of keys, max value is 2*T-1
    bool leaf; // whether it is a leaf node
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

//create btree

void BtreeSplitChild(node *&, int , node *&);
status BtreeInsertNotFull(node *x, int i);

status BtreeAlloc(node* &root){
    status ret = OK;
    root = new node();
    if(root==NULL) return FAILED;
    return ret;
}

// insert key in the tree;
status Insert(int key, node* &root){
    status ret = FAILED;
    node * cpy = root;
    if(cpy->cnt == 2*T-1) {
        node * tmp = new node();
        tmp->leaf = false;
        tmp->cnt = 0;
        tmp->child[0] =cpy;
        root = tmp;
        BtreeSplitChild(root,0,cpy);
        BtreeInsertNotFull(root,key);
    } else {
        BtreeInsertNotFull(cpy,key);
    }
    return ret;
}


status BtreeInsertNotFull(node * x, int key)
{
    int cnt = x->cnt;
    if(x->leaf){
        while(cnt >=0 && key < x->data[cnt-1])
        {
            x->data[cnt] = x->data[cnt-1];
            cnt--;
        }
        x->data[cnt] = key;
        x->cnt++;
    }else {
        while(cnt>=0 && key < x->data[cnt-1]) cnt--;
        if(x->child[cnt]->cnt == 2*T-1){
            BtreeSplitChild(x,cnt,x->child[cnt]);
            if(key > x->data[cnt]) cnt++;
        }
        BtreeInsertNotFull(x->child[cnt],key);
    }
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

// 将x 节点的第 i 个孩子节点 y 将被分裂两个节点
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
    x->data[i] = y->data[T-1];
    x->cnt++;
}

// delete key in tree;

status Drop(int key, node* &root){
    status ret = FAILED;
    if(root){
        bool in_node = false;
        for(int i=0; i< root->cnt; i++){
            if(root->data[i] == key){
                in_node = true;
                break;
            }
        }
        if(in_node) {
            if(root->leaf){

            }else {

            }
        }else {

        }
    }
    return ret;
}

// print tree
void treePrint(node * root, int width)
{
    if(root){
        for(int i=0; i<root->cnt; i++){
            treePrint(root->child[i],width + 5);
            for(int j=0; j<width; j++) cout<<" ";
            cout<<root->data[i]<<endl;
        }
        treePrint(root->child[root->cnt],width + 5);
    }
}
// search key in tree

//          

int main(){
    node * root;
    BtreeAlloc(root);
    for(int i=0; i<28; i++){
        Insert(i,root);
    }
    treePrint(root,0);
    return 0;
}
