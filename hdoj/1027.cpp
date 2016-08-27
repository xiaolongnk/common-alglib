#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 1002

int num[N];

int main(){
    int n,m;
    int cnt=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0; i<n; i++){
            num[i] = i+1;
        } 
        cnt = 0;
        do{
            cnt++;
            if(cnt==m) { 
                for(int i=0; i<n-1;i++){
                    printf("%d ",num[i]);
                }
                printf("%d\n",num[n-1]);
                break;
            }
        }while(next_permutation(num,num+n));
    }
    return 0;
}
