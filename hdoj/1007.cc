#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;


#define N 100001

int t,i;
int a,b;
struct point {
    double x;
    double y;
};

point data[N];
int temp[N];

bool cmp(const point a, const point b){
    if(a.x < b.x ) return true;
    else if(a.x - b.x < 1e-10) return a.y < b.y;
    else return false;
}

double dist(int idx1, int idx2){
    return sqrt((data[idx1].x-data[idx2].x)*(data[idx1].x-data[idx2].x)+
            (data[idx1].y - data[idx2].y)*(data[idx1].y - data[idx2].y));
}

double mm(double a, double b){
    return a<b?a:b;
}


double find(const int left, const int right){
    if(right==left) return 0xffffff;
    if(right==left+1) return dist(left,right);
    int mid = (left+right)/2;
    double delta1 = find(left,mid);
    double delta2 = find(mid+1,right);
    double delta = mm(delta1, delta2);
    int k=0;
    for(int i=left; i<=right; i++){
        if(fabs(data[mid].x - data[i].x)<delta) temp[k++] = i;
    }
    if(k>12) k = 12;
    for(int i=0; i<k;i++){
        for(int j=i+1; j<k; j++){
            delta = mm(dist(temp[i],temp[j]),delta);
        }
    }
    return delta;
}

int main(){
    while(true){
        scanf("%d",&t);
        if(t==0) break;
        i = 0;
        while(i<t){
            scanf("%lf%lf",&data[i].x,&data[i].y);
            i++;
        }
        sort(data,data+t,cmp);
        //for(int i=0; i<t; i++){
        //    printf("%lf  %lf\n",data[i].x, data[i].y);
        //}
        printf("%.2lf\n",find(0,t-1)/2);
    }
    return 0;
}
