/*
 * @author: xiaolongou
 * 2014-12-17 03:05
 */

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
void treePrint(node *, int );
void BtreeSplitChild(node *&, int , node *&);
void BtreeInsertNotFull(node *&x, int i);
void dropFromLeaf(node *&, int);
void combineTwoNode(node *&root, int pl);
void borrowFromLeft(node*&, int );
void borrowFromRight(node*&, int );
void deleteKey(node *&root, int key);
node * successor(node *);
node * precessor(node *);
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


void BtreeInsertNotFull(node * &x, int key)
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

// delete key in tree; 从以root为根的子树中删除关键字key.
void deleteKey(node* &root, int key){
    if(root){
        cout<<"--------------------------"<<endl;
        treePrint(root,0);
        cout<<"--------------------------"<<endl;
        bool in_node = false;
        int pos = root->cnt - 1;
        node * child = root->child[pos+1];
        for(int i=0; i< root->cnt; i++){
            if(root->data[i] == key){
                in_node = true;
                child = root->child[pos];
                pos = i;
                break;
            }
            if(root->data[i] > key ){
                pos = i;
                child = root->child[pos];
                break;
            }
        }
        if(in_node) {
            if(root->leaf){
                // 如果是叶子节点，直接从这个叶子节点删除
                dropFromLeaf(root,key);
            }else {
                // 如果不是叶子节点，需要做一些处理
                if(root->child[pos]->cnt > T - 1){
                    node * pre = precessor(root->child[pos]);
                    int pre_key = pre->data[pre->cnt-1];
                    root->data[pos] = pre_key;
                    deleteKey(root->child[pos], pre_key);
                }else if(pos + 1 <=root->cnt && root->child[pos + 1]->cnt > T -1){
                    node * succ = successor(root->child[pos + 1]);
                    int suc_key = succ->data[0];
                    root->data[pos] = suc_key;
                    deleteKey(root->child[pos+1], suc_key); 
                }else {
                // 合并两个节点
                    combineTwoNode(root, pos);
                    deleteKey(root->child[pos],key);
                }
            }
        }else {
            // here must have a child node. do something on this node.
            if(child->cnt == T-1){
                // 看左边的兄弟节点
                if(pos - 1 >=0 && root->child[pos-1]->cnt > T-1){
                    borrowFromLeft(root, pos - 1);
                    deleteKey(child, key);
                }else if( pos + 1 <= root->cnt && root->child[pos+1]->cnt > T-1){
                //可以和右边的兄弟节点
                    borrowFromRight(root, pos);
                    deleteKey(child, key);
                }else {
                // 需要合并两个孩子
                    combineTwoNode(root,pos);
                    deleteKey(root->child[pos],key);
                }
            }else {
                deleteKey(child, key);
            }
        }
    }
}

// 从叶节点删除一个关键字
void dropFromLeaf(node *& root, int key)
{
    cout<<"here delete from leaf"<<endl;
    int len = root->cnt;
    int pos = 0;
    for(int i=0 ; i<root->cnt; i++){
        if(key == root->data[i]){
            for(int j = i; j < root->cnt-1; j++){
                root->data[j] = root->data[j+1];
            }
            root->cnt--;
            break;
        }
    }
}

/*
 * left = root->child[p_key]
 * right = root->child[p_key + 1]
 */ 
void combineTwoNode(node *&root, int p_key)
{
    node * left = root->child[p_key];
    node * right = root->child[p_key+1];

    left->data[T-1] = root->data[p_key];

    for(int i=0; i<right->cnt; i++){
        left->data[T+i] = right->data[i];
        left->child[T+i] = right->child[i];
    }
    left->child[left->cnt+right->cnt] = right->child[right->cnt];
    left->cnt = T+T-1;
    left->leaf = right->leaf;
    delete right;

    for(int i=p_key; i < root->cnt - 1; i++){
        root->data[i] = root->data[i+1];
        if(i+2 <= root->cnt) root->child[i+1] = root->child[i+2];
    }
    root->cnt--;
    cout<<"combine finished"<<endl;
}

// 前驱节点 前驱节点中最大的 data 就是需要的值。
node * precessor(node * root)
{
    while(1){
        if(NULL == root->child[root->cnt]){
            break;   
        }
        root = root->child[root->cnt];
    }
    return root;
}
// 后继节点 后继节点中最小的 data 就是需要的值
node * successor(node * root)
{
    while(1){
        if(NULL == root->child[0]){
            break;
        }
        root = root->child[0];
    }
    return root;
}

void borrowFromLeft(node *&root, int pos)
{
    cout<<"borrow from left"<<endl;
    node * left = root->child[pos];
    node * right = root->child[pos + 1];
    for(int i = right->cnt ; i>0; i--){
        right->data[i] = right->data[i-1];
        right->child[i+1] = right->child[i];
    }
    right->child[1] = right->child[0];
    right->data[0] = root->data[pos];
    right->cnt++;
    right->child[0] = left->child[left->cnt];
    root->data[pos] = left->data[left->cnt-1];
    left->cnt--;
}
/*
 * left = root->child[pos]
 * right = root->child[pos + 1]
 */
void borrowFromRight(node *&root, int pos)
{
    cout<<"borrow from right"<<endl;
    node * left = root->child[pos];
    node * right = root->child[pos + 1];
    left->data[left->cnt] = root->data[pos];
    left->child[left->cnt+1] = right->child[0];
    root->data[pos] = right->data[0];
    for(int i = 0; i<right->cnt-1; i++){
        right->data[i] = right->data[i+1];
        right->child[i] = right->child[i+1];
    }
    right->child[right->cnt-1] = right->child[right->cnt];
    right->cnt --;
    left->cnt++;
}

int leafcount = 0;
// print tree
void treePrint(node * root, int width)
{
    if(root){
        for(int i=0; i<root->cnt; i++){
            treePrint(root->child[i],width + 5);
            for(int j=0; j<width; j++) cout<<" ";
            cout<<root->data[i]<<endl;
            if(root->leaf) leafcount++;
        }
        treePrint(root->child[root->cnt],width + 5);
    }
}

int main(){
    node * root;
    BtreeAlloc(root);
    for(int i=0; i<28; i++){
        Insert(i,root);
    }
    treePrint(root,0);
    int p;
    while(cin>>p){
        if(p == -1) break;
        deleteKey(root,p);
        treePrint(root,0);
    }
    return 0;
}
