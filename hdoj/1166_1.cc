#include <iostream>
#include <string.h>
#include <stdio.h>


#define MAX 500010

using namespace std;

int ps[MAX];
int a,b;
char command[20];

int lowbit( int m ){
    return m&(-m);
}

int sum( int n){
    int sum = 0;
    while(n){
        sum+=ps[n];
        n-= lowbit(n);
    }
    return sum;
}

void update(int a, int b, int n){
    while(a<=n){
        ps[a]+=b;
        a+=lowbit(a);
    }
}


int main(){
    int t, n;
    scanf("%d",&t);
    int cnt = 1;
    int tmp;
    while(t--){
        memset(ps,0,sizeof(ps));
        scanf("%d",&n);
        for(int i=1; i<=n; i++){
            scanf("%d",&tmp);
            update(i,tmp,n);
        }
        printf("Case %d:\n",cnt++);
        while(true){
            scanf("%s",command);
            if(!strcmp(command,"End")){
                break;
            }else scanf("%d%d",&a,&b);
            if(!strcmp(command,"Add")){
                update(a,b,n);
            }else if(!strcmp(command,"Sub")){
                update(a,-b,n);
            }else if(!strcmp(command,"Query")){
                printf("%d\n",sum(b)-sum(a-1));
            }
        }
    }
    return 0;
}
