#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;


#define N 10001

struct node {
    int a,b;
    double ratial;
};
node data[N];

bool cmp(const node &a, const node &b){
    return a.ratial > b.ratial;
}

int main(){
    int m,n,i;
    while(true){
        scanf("%d%d",&m,&n);
        if(m==-1 && n==-1) break;
        for(i=0; i<n; i++){
            scanf("%d%d",&data[i].a,&data[i].b);
            data[i].ratial = float(data[i].a)/float(data[i].b);
        }
        sort(data,data+n,cmp);
        double sum = 0;
        i = 0;
        while(m && i < n){
            if(m >= data[i].b){
                sum += data[i].a;
                m-=data[i].b;
                i++;
            }
            else {
                sum+=m*data[i].ratial;
                break;
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
