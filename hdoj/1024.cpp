#include <iostream>
#include <stdio.h>

using namespace std;
#define N 1000001
#define INT_MIN -0xffffffe
int a[N],b[N],dp[N];

int bmax(int a, int b)
{
	return a>b?a:b;
}

int main()
{
    int max,m,n;
    while(cin>>m>>n)
    {
        int i,j;
		a[0]=b[0]=dp[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            b[i]=dp[i]=0;
        } 
		for(i=1;i<=m;i++)
        {
            max=INT_MIN;
            for(j=i;j<=n;j++)
            {
                dp[j]=bmax(dp[j-1],b[j-1])+a[j];
				b[j-1]=max;
                if(dp[j]>max) max=dp[j];
            }
            b[j-1]=max;
        }
        cout<<max<<endl;
    }
    return 0;
}
