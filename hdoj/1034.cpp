#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1000000

int num[N];
int cpnum[N];

int main() {
    int n;
    int cnt;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(int i=0; i<n; i++){
            scanf("%d",&num[i]);
        }
        cnt = 0;
        bool end ;
        while(true){
            cpnum[0] = num[0]/2+num[n-1]/2;
            for(int i=1; i<n; i++){
                cpnum[i] = num[i]/2 + num[i-1]/2;
            }
            for(int i=0; i<n; i++){
                num[i] = cpnum[i];
                if(num[i] %2){
                    num[i]+=1;
                }

            }
            cnt++;
            end = true;
            for(int i=1; i<n; i++){
                if(num[i]!=num[0]){
                    end = false;
                    break;
                }
            }
            if(end) {
                printf("%d %d\n",cnt,num[0]);
                break;
            }

        }
    }
}
