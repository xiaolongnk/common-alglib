/*
 * Dynamic programming
 */

#include <stdio.h>
//#include <cstdlib>
#include <algorithm>


using namespace std;

int cas,demand,total;
#define N 10000
float greedy[N];
int pos[N];
int main()
{
	int i,j;
	float temp;
	while(scanf("%d%d%d",&cas,&total,&demand)!=EOF)
	{
		for(i=0; i<total; i++) greedy[i]=0,pos[i]=i;
		for(i=0; i<cas; i++)
		{
			for(j=0; j<total; j++)
			{
				scanf("%f",&temp);
				greedy[j] += temp;
			}
		}

		for(i=0; i<total; i++)
			for(j=i+1; j<total; j++)
			{
				if(greedy[pos[i]] < greedy[pos[j]])
				{
					swap(pos[i],pos[j]);
				}
				else if(greedy[pos[i]]==greedy[pos[j]])
				{
					if (pos[i] > pos[j]){
						swap(pos[i],pos[j]);
					}
				}
			}
		sort(pos,pos+demand);

		for(i=demand-1; i>0; i--)
		   printf("%d ",pos[i]+1);
		printf("%d\n",pos[0]+1);
	}	
	return 0;
}

