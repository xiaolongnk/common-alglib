#include <iostream>
#include <map>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;
#define N 160
#define MX 0xfffffff

int mp[N][N];
int dset[N];
char tmp[32],tmpp[32],start[32],end[32];
int hour;
bool vis[N];
map<string,int> table;
int dijkstra(int s, int d, int n){
    for(int i=0;i<n; i++){
        dset[i] = mp[s][i];
        vis[i] = false;
    }
    dset[s] = 0; vis[s] = true;
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
    if(dset[d]>=MX) return -1;
    return dset[d];
}


int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==-1) break;
        table.clear();
        int cnt = 3;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++){
                mp[i][j] = MX;
            }
        scanf("%s%s",start,end);
        table[start] = 1;
        table[end] = 2;
        for(int i=0; i<n; i++){
            scanf("%s%s%d",tmp,tmpp,&hour);
            if(table[tmp]==0) table[tmp] = cnt++;
            if(table[tmpp]==0) table[tmpp] = cnt++;
            if(mp[table[tmp]-1][table[tmpp]-1]>hour){
                mp[table[tmp]-1][table[tmpp]-1] = hour;
                mp[table[tmpp]-1][table[tmp]-1] = hour;
            }
        }
        if(strcmp(start,end)==0) {
            puts("0");
            continue;
        }
        printf("%d\n",dijkstra(0,1,cnt));
    }
    return 0;
}
