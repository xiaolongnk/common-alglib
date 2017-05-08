/**********************************************************
> File Name: mergesort.cpp
> Author: xiaolongou
> Mail: xiaolongnk@126.com 
> Created Time: 2013年12月10日 星期二 22时44分30秒
 **********************************************************/
#include "comm.h"

void merge(int*,int,int,int);

void mergeSort(int *p, int left, int right)
{
	if( left < right )
	{
		int mid = (left + right)>>1;
		mergeSort(p,left,mid);
		mergeSort(p,mid+1,right);
		merge(p,left,right,mid);
	}
}

void merge(int *p, int left, int right, int pos)
{
	int temp[N];
	int cntt=0;
	int i=left,j=pos+1;
	while(true)
	{
		if(i <= pos && j<=right)
		{
			if(p[i]<p[j])
				temp[cntt++] = p[i++];
			else
				temp[cntt++] = p[j++];
		}
		else if( i<=pos && j>right )
		{
			temp[cntt++] = p[i++];
		}
		else if( j<=right && i>pos)
		{
			temp[cntt++] = p[j++];
		}
		else break;
	}
	for(int i=0; i<cntt; i++)
		p[left+i] = temp[i];
}

int main()
{
	int test[N];
	for(int i=0; i<N; i++) test[i]=i;
	randomShuffle(test);
	mergeSort(test,0,N-1);
	if(check(test)) cout<<"AC"<<endl;
	else cout<<"WA"<<endl;
	return 0;
}

