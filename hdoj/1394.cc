#include <iostream>
#include <stdio.h>

#define N 5010
using namespace std;
int ps[N];

int  main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<n; i++){
            scanf("%d",&ps[i]);
        }
        int tmp, sum = 0;
        for(int i=0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(ps[i] > ps[j]){
                    sum++;
                }
            }
        }
        tmp = sum;
        for(int i=0; i<n; i++){
            sum= sum-ps[i]-ps[i]+n-1;
            if(tmp >sum) tmp  =sum;
        }
        printf("%d\n",tmp);
    }
    return 0;
}
