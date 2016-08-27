#include <iostream>

#include <stdio.h>
#define N 101
int data[N][N];
int dp[N][N];

using namespace std;

int mx(int a, int b){
    return a>b?a:b;
}

int solve(int height){
    for(int i = 0; i<height; i++){
        dp[height-1][i] = data[height-1][i];
    }
    for(int i = height-2; i>=0; i--){
        for(int j = 0; j<i+1; j++){
            dp[i][j] = mx(dp[i+1][j],dp[i+1][j+1])+data[i][j]; 
        }
    }
    return dp[0][0];
}

int main(){
    int t,h;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&h);
        for(int i=0; i<h; i++){
            for(int j=0; j<=i; j++){
                scanf("%d",&data[i][j]);
            }
        }
        printf("%d\n",solve(h));
    }
    return 0;
}
