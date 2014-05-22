/*
 * generate the permutation of a array!
 * 2013-08-05 11:06:53
 * xiaolongou
 *
 */
#include <cstdio>
#include <iostream>
using namespace std;
#define M 100
int a[M];
void permutation(int *a, int n, int cur){
    if(cur==n) {
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else for(int i=1;i<=n;i++){
        int ok=1;
        for(int j=0;j<cur;j++) if(a[j]==i) ok=0;
        if(ok){
            a[cur]=i;
            permutation(a,n,cur+1);
        }
    }
}
int main(){
    int n;
    cout<<"Please input your number:";
    scanf("%d",&n);
    permutation(a,n,0);
    return 0;
}
