#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define N 100105
#define INF 0xfffffff

char s[N],st[12][12];
int mat[12][N];

inline int mmn(int x, int y){
    return x<y?x:y;
}
int dp(char *s1, char *s2, int x1, int x2){
    int ret = INF;
    for(int i=1; i<=x1; i++){
        mat[i][0] = i; 
        for(int j=1; j<=x2; j++){
            mat[i][j] = mmn(mat[i-1][j-1]+(s1[i-1]!=s2[j-1]),
                   mmn(mat[i-1][j],mat[i][j-1])+1);
           if(i==x1) ret = mmn(ret,mat[i][j]);
        }
    }
    return ret;
}

int main(){
    int n,x1,x2,tmp,ans,ansid;
    freopen("in","r",stdin);
    while(scanf("%s",s)!=EOF){
        x1 = strlen(s);
        scanf("%d",&n);
        ans = INF;
        ansid = -1;
        for(int i=0; i<n; i++){
            scanf("%s",st[i]);
            x2 = strlen(st[i]);
            tmp = INF;
            if(x1<20){
                for(int j = 0; j<x1; j++){
                    tmp = mmn(tmp,dp(st[i],s+j,x2,x1));
                    s[x1+j] = s[j];
                }
            }else{
                for(int j=0; j<20; j++) s[x1++] = s[j];
                tmp = dp(st[i],s,x2,x1); 
            }
            if(tmp<ans||tmp==ans && strcmp(st[i],st[ansid])<0){
                ansid = i;
                ans = tmp;
            }
        }
        printf("%s %d\n",st[ansid],ans);
    }
    return 0;
}
