#include <stdio.h>

using namespace std;

#define N  500001

int bsearch(int *a, int key, int len)
{
	int left = 0;
	int right = len-1;
	int m;
	bool flag = false;
	while(left <= right)
	{
		m = (left + right)>>1;
		if (key==a[m]) {
			flag = true;
			break;
		}
		else if (key>a[m] ) left = m + 1;
		else right = m - 1;
	}
	if (flag == false) 
	{
		a[left] = key;
	}
}

int da[N];
int ppp[N];
int len;

int main()
{
	int t;
	int test=1;
	int g,gg;
	while(scanf("%d",&t)!=EOF)
	{
		for(int i=0; i<t; i++)
		{
			scanf("%d%d",&g,&gg);
			ppp[g-1] = gg;
		}
		len = 1;
		da[0] = ppp[0];
		for (int i=1; i<t; i++)
		{
			if (ppp[i] > da[len-1]) da[len++] = ppp[i];
			else bsearch(da,ppp[i],len);
		}
		if (len == 1)
		{
			printf("Case %d:\nMy king, at most "
				   "%d road can be built.\n\n",test,len);
		}
		else 
		{
			printf("Case %d:\nMy king, at most "
			       "%d roads can be built.\n\n",test,len);
		}
		test++;
	}
	return 0;
}
