#include <iostream>
#include <stdio.h>
#include <string.h>


#define N 1000001

using namespace std;

char s[N];
int next[N];

void solve(char *s,int len){
    int a=0,b=-1;
    next[0] = -1;
    while(a<len){
        if(b==-1 || s[a]==s[b]){
            next[++a]=++b;
        }else b=next[b];
    }

    for(int i=1; i<len; i++){
        if(next[i+1] && (i+1)%(i+1-next[i+1])==0){
            printf("%d %d\n",i+1,(i+1)/(i+1-next[i+1]));
        }
    }
}

int main(){
    int len;
    int cnt = 0;
    while(scanf("%d",&len)!=EOF){
        if(len==0) break;
        cnt++;
        scanf("%s",s);
        printf("Test case #%d\n",cnt);
        solve(s,len);
        puts("");
    }
    return 0;
}
