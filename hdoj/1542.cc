#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 5000

double yy[N];

struct line{
    int cover;
    double x,y1,y2;
}ll[N];

struct treeNode{
    int cover;
    double l,r,len;
}tree[N];


bool cmp(line a, line b){
    return a.x < b.x;
}

void buildTree(int l, int r, int v){
    tree[v].l = yy[l];
    tree[v].r = yy[r];
    tree[v].len = tree[v].cover = 0;
    if(l+1==r) return;
    int mid = (l+r)>>1;
    buildTree(l,mid,v+v);
    buildTree(mid,r,v+v+1);
}

void len(int v){
    if(tree[v].cover>0)
        tree[v].len = tree[v].r - tree[v].l;
    else 
        tree[v].len = tree[v+v+1].len + tree[v+v].len;
}

void update(line n, int v){
    if(tree[v].l==n.y1 && tree[v].r==n.y2){
        tree[v].cover+=n.cover;
        len(v);
        return;
    }
    if(n.y1>=tree[v+v].r) update(n,v+v+1);
    else if(n.y2<=tree[v+v+1].l) update(n,v+v);
    else{
        line tmp = n;
        tmp.y2 = tree[v+v].r;
        update(tmp,v+v);
        tmp = n;
        tmp.y1 = tree[v+v+1].l;
        update(tmp,v+v+1);
    }
    len(v);
}



int main(){
    int t,cnt=1,m;
    double x1,x2,y1,y2,ans;
//    freopen("in","r",stdin);
    while(scanf("%d",&t) && t){
        m = 0;
        for(int i=0; i<t; i++){
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            yy[m]=y1;
            ll[m].x = x1;
            ll[m].y1 = y1;
            ll[m].y2 = y2;
            ll[m++].cover = 1;

            yy[m] = y2;
            ll[m].x = x2;
            ll[m].y1 = y1;
            ll[m].y2 = y2;
            ll[m++].cover = -1;
        }
        sort(yy,yy+m);
        sort(ll,ll+m,cmp);
        buildTree(0,m-1,1);
        ans = 0;
        for(int i=0; i<m-1; i++){
            update(ll[i],1);
            ans+=tree[1].len*(ll[i+1].x - ll[i].x);
        }
        printf("Test case #%d\n",cnt++);
        printf("Total explored area: %.2lf\n\n",ans);
    }
    return 0;
}

