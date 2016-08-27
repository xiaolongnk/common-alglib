#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

#define N 1000001
#define M 10001

int datan[N];
int datam[M];
int next[M];

void init_next(int mlen){
    int a=0, b=-1;
    next[0] = -1;
    while(a<mlen){
        if(b == -1 || datam[a] == datam[b]){
            next[++a] =++b;
        }else b=next[b];
    }
}

int KmpSolve(int nlen,int mlen){
    init_next(mlen);
    int i=0,j=0;
    while(i<nlen){
        if(j==-1 || datan[i]==datam[j]){
            i++;
            j++;
        }else j = next[j];
        if(j==mlen) return i-mlen+1;
    }
    return -1;
}

int main(){
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++){
            scanf("%d",&datan[i]);
        }
        for(int i=0; i<m; i++){
            scanf("%d",&datam[i]);
        }
        printf("%d\n",KmpSolve(n,m));
    }
    return 0;
}
