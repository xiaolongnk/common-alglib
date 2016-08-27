/*
 *	prime circle 
 *	xiaolongnk
 *	2013-10-07 11:55:38
 *	tags: dfs
 *
 */

#include <stdio.h>
#include <algorithm>

using namespace std;

#define N 22

int a[N];

bool prime[10*N];
bool visit[N];


void fillprime()
{
	for(int i=0; i<10*N; i++) prime[i]=true;
	for(int i=2; i*i<10*N; i++)
	{
		for(int j=2;i*j<10*N;j++)
		{
			prime[i*j]=false;
		}
	}
}

int ans[N];
int c_ans;
void solve(int step, int n)
{
	if(step == n )
	{
		for(int i=0; i<c_ans; i++) printf("%d ",ans[i]);
		printf("%d\n",ans[c_ans]);
	}
	else
	{
		if(step == n-1)
		{
			for(int i=0; i<n; i++)
			{
				if((!visit[a[i]]) && prime[a[i]+1] && prime[a[i]+ans[c_ans]])
				{
					ans[++c_ans]=a[i];
					visit[a[i]]=true;
					solve(step+1,n);
					ans[c_ans--]=0;
					visit[a[i]]=false;
				}
			}
		}
		else
		{
			for(int i=0; i<n; i++)
			{
				if((!visit[a[i]]) && (prime[a[i]+ans[c_ans]]))
				{
					ans[++c_ans]=a[i];
					visit[a[i]]=true;
					solve(step+1,n);
					ans[c_ans--]=0;
					visit[a[i]]=false;
				}
			}
		}
	}
}

int main()
{
	int n;
	int cnt=1;
	fillprime();
	while(scanf("%d",&n)!=EOF)
	{
		// fill all the prime;
		for(int i=0; i<N; i++) visit[i]=false;
		for(int i=0; i<n;i++) a[i]=i+1;
		visit[1]=true;
		visit[0]=true;
		ans[0]=1;
		c_ans=0;
		printf("Case %d:\n",cnt++);
		solve(1,n);
		printf("\n");
	}
	return 0;
}
