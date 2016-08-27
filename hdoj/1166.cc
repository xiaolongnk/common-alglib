#include <iostream>
#include <string.h>
#include <stdio.h>


#define MAX 500010

using namespace std;

int ps[MAX];
int a,b;
char command[20];

struct node{
    int l,r;
    int n;
}tree[3*MAX];

void build(int l, int r, int v){
    tree[v].l = l;
    tree[v].r = r;
    if( l==r ){
        tree[v].n = ps[l];
        return ;
    }
    int mid = (l+r)/2;
    build(l,mid,v*2);
    build(mid+1,r,v*2+1);
    tree[v].n = tree[v*2].n + tree[2*v+1].n;
}

int query(int a, int b, int v){
    if(tree[v].l == a && tree[v].r == b){
        return tree[v].n;
    }
    int mid=(tree[v].l+tree[v].r)>>1;
    if(b<=mid) return query(a,b,v+v);
    else if(a>mid) return query(a,b,2*v+1);
    else return query(a,mid,v*2) + query(mid+1,b,v*2+1);
}

void update(int a, int b, int v){
    tree[v].n+=b;
    if(tree[v].l == tree[v].r ){
        return ;
    }
    int mid = (tree[v].l + tree[v].r)>>1;
    if(a<=mid) update(a,b,2*v);
    else update(a,b,2*v+1);
}

int main(){
    int t, n;
    scanf("%d",&t);
    int cnt = 1;
    while(t--){
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&ps[i]);
        }
        build(1,n,1);
        printf("Case %d:\n",cnt++);
        while(true){
            scanf("%s",command);
            if(!strcmp(command,"End")){
                break;
            }else scanf("%d%d",&a,&b);
            if(!strcmp(command,"Add")){
                update(a,b,1);
            }else if(!strcmp(command,"Sub")){
                update(a,-b,1);
            }else if(!strcmp(command,"Query")){
                printf("%d\n",query(a,b,1));
            }
        }
    }
    return 0;
}
