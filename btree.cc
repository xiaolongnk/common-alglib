#include <iostream>

#include <cstdlib>
using namespace std;


#define N 3

typedef int elem;

struct node {
    elem data[N];
    node *child[N+1];
    int cnt;
    
    node(){
        for(int i=0; i<N; i++){
            data[i] = 0;
            child[i] = NULL;
        }
        child[N] = NULL;
        cnt = 0;
    }
};

// insert key in the tree;

// delete key in tree;

// print tree

// search key in tree

//          

int main(){
    
    return 0;
}

