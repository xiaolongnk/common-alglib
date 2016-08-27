#include <stdio.h>
#include <iostream>


using namespace std;

#define N 1001
int data[N];
int dp[N];

int solve(int len){
    for(int i=0; i<len;i++){
        dp[i] = data[i];
        for(int j=0; j<i; j++){
            if(data[i]>data[j] && dp[i]<dp[j]+data[i]){
                dp[i] = dp[j]+data[i];
            }
        }
    }
    int mx = -1000;
    for(int i = 0; i<len; i++){
        if(mx < dp[i]){
            mx = dp[i];
        }
    }
    return mx;
}

int main(){
    int t;
    while(scanf("%d",&t)!=EOF){
        if(t==0) break;
        for(int i=0; i<t; i++){
            scanf("%d",&data[i]);
        }
        printf("%d\n",solve(t));
    }
    return 0;
}
