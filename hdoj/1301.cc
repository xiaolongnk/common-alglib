#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int p[30], r[200];
int start[200],end[200],w[200];

int cmp(const int &a, const int &b){
    return w[a] < w[b];
}


int find(int x){
    if(x==p[x]) return x;
    else return p[x]=find(p[x]);
}

int kruskra(int n){
    int ans = 0;
    for(int i=0; i<30; i++) p[i] = i;
    for(int i=0; i<n; i++) r[i] = i;
    sort(r,r+n,cmp);   
    for(int i=0; i<n; i++){
        int e = r[i];
        int x = find(start[e]);
        int y = find(end[e]);
        if(x!=y){
            ans+=w[e];
            p[x] = y;
        }
    }
    return ans;
}


int main(){
    int n,tmp,cnt,tt;
    char ch;
//    freopen("in","r",stdin);
    while(scanf("%d",&n)!=EOF && n){
        cnt = 0;
        for(int i=0; i<n-1; i++){
            //scanf("%c %d",&ch,&tmp);
            cin>>ch>>tmp;
            int idx = ch-'A';
            for(int j=0; j<tmp; j++){
                cin>>ch>>tt;
                start[cnt] = idx;
                end[cnt] = ch - 'A';
                w[cnt] = tt;
                cnt++;
            }
        }
        printf("%d\n",kruskra(cnt));
    }
    return 0;
}
