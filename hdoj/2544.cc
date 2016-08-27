#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>

using namespace std;

#define MX 0xfffffff

int mp[101][101];
int dset[102];
bool vis[102];

int dijkstra(int n){
    for(int i=1; i<n; i++){
        dset[i] = mp[0][i];
        vis[i] = false;
    }
    dset[0] = 0;
    vis[0] = true;

    for(int i=1; i<n; i++){
        int tmp = MX,key;
        for(int j =1; j<n; j++){
            if(!vis[j] && dset[j]<tmp){
                tmp = dset[j];
                key = j;
            }
        }
        vis[key] = true;
        for(int j=1;j<n;j++){
            if(!vis[j] && dset[j]>dset[key]+mp[key][j]){
                dset[j] = dset[key]+mp[key][j];
            }
        }
    }
    return dset[n-1];
}

int main(){
    int n,m;
    int a,b,c;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0 && m==0) break;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[i][j] = MX;
            }
        }
        for(int i=0; i<m; i++){
            scanf("%d%d",&a,&b);
            scanf("%d",&mp[a-1][b-1]);
            mp[b-1][a-1] = mp[a-1][b-1];
        }
        printf("%d\n",dijkstra(n));
    }
    return 0;
}
