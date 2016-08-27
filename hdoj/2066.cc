#include <iostream>
#include <stdio.h>

using namespace std;


#define MX  0xffffff
#define N 1020

int mp[N][N];


int t,s,d;

int home[N];
int target[N];

int dset[N];
bool vis[N];

int dijkstra(int s, int n){
    for(int i=0;i<n; i++){
        dset[i] = mp[s][i];
        vis[i] = false;
    }
    dset[s] = 0;
    vis[s] = true;
    
    for(int i=0; i<n; i++){
        if(i==s) continue;
        int inf = MX,key;
        for(int j=0; j<n; j++){
            if(!vis[j] && inf>dset[j]){
                inf = dset[j];
                key = j;
            }
        }
        vis[key] = true;
        for(int j=0; j<n; j++){
            if(!vis[j] && dset[j]>dset[key] + mp[key][j]){
                dset[j] = dset[key] + mp[key][j];
            }
        }
    }
    int inf = 0xffffff;
    for(int i=0; i<d; i++){
        if(inf > dset[target[i]-1]) 
            inf = dset[target[i]-1];
    }
    return inf;
}

int main(){
    int a,b,c;
    while(scanf("%d%d%d",&t,&s,&d)!=EOF){
        
        for(int i=0; i<N; i++){
            for(int j=0;j<N;j++){
                mp[i][j] = MX;
            }
        }
        int mmm = -MX;
        int tmp; 
        for(int i=0; i<t; i++){ 
            scanf("%d%d%d",&a,&b,&c);
            tmp = a>b?a:b;
            if(mmm < tmp) mmm = tmp;
            // 可能含重边
            if(c<mp[a-1][b-1]){
                mp[a-1][b-1] = c;
                mp[b-1][a-1] = c;
            }
        }
        for(int i=0; i<s; i++){
            scanf("%d",&home[i]);
        }
        for(int i=0; i<d; i++){
            scanf("%d",&target[i]);
        }
        int mn = MX;
        for(int i=0; i<s; i++){
            tmp = dijkstra(home[i]-1,mmm);
            if(tmp < mn){
                mn = tmp;
            }
        }
        printf("%d\n",mn);
    }
    return 0;
}

