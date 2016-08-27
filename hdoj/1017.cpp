/*
 *	 xiaolongnk
 *	 2013-10-07 12:30:38
 *
 *
 */

#include <stdio.h>


using namespace std;


void solve(int n,int m,int aa)
{
	int cnt=0;
	for(int a=1;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			if(((a*a+b*b+m)%(a*b))==0) cnt++;
		}
	printf("Case %d: %d\n",aa,cnt);
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0; i<N; i++)
	{
		int n,m;
		int aa=1;
		while(scanf("%d%d",&n,&m)!=EOF)
		{
			if(n==0 && m==0) break;
			solve(n,m,aa++);
		}
		if(i<N-1) printf("\n");
	}
}

