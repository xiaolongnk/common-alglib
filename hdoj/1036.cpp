#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;

#define N 21

char str[N];

int main(){
    int n;
    float dist;
    int i=0;
    int t;
    int h,m,s;
    bool finish;
    int ans;
    scanf("%d%f",&n,&dist);
    while(scanf("%d",&t)!=EOF){
        int sec = 0;
        finish = true;
        for(i=0; i<n; i++){
            scanf("%s",str);
            if(strcmp(str,"-:--:--")){
                sscanf(str,"%d:%d:%d",&h,&m,&s);
                sec+=h*3600+m*60+s;
            }
            else{
                finish = false;
            }
        }
        ans = round(sec/dist);
        if(finish){
            printf("%3d: %d:%02d min/km\n",t,ans/60,ans%60);
        }else{
            printf("%3d: -\n",t);
        }

    }
    return 0;
}
