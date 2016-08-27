#include <stdio.h>
#include <iostream>

using namespace std;

int solve(int a)
{
    int cnt=1;
L:  if(a==1) return cnt;
    else
    {
        if(a%2) a=3*a+1;
        else a/=2;
    }
    cnt++;
    goto L;
}
int main()
{
    int a,b,num;
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("%d %d ",a,b);
        if( a>b) {
            int k = a;
            a = b;
            b = k;
        }
        int max = 0;
        for(int i=a; i<=b;i++){
            num = solve(i);
            if(max<num) max=num;
        }
        printf("%d\n",max);
    }
    return 0;
}
