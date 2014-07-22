/**********************************************************
> File Name: heapSort.cpp
> Author: xiaolongou
> Mail: xiaolongnk@126.com 
> Created Time: 2013年12月11日 星期三 19时40分59秒
 **********************************************************/
#include "comm.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define LEFT(i) (i<<1)+1

void heapfy(int*,int,int);

void heapSort(int *p,int size)
{
	for(int i=size/2; i>=0; i--)
	{
		heapfy(p,i,size);
	}
	for(int i=0; i<size; i++)
	{
		swap(p[0],p[size-i]);
		heapfy(p,0,size-i-1);
	}
}

// create a max-heap first element is max element;
void heapfy(int *p, int pos,int size)
{
	int l = LEFT(pos);
	int r = l+1;
	if( l <= size)
	{
		if(r <=size )
		{
			if(p[l] < p[r])
			{
				if(p[pos] < p[r])
				{
					swap(p[r],p[pos]);
					heapfy(p,r,size);
				}
			}
			else 
			{
				if(p[pos] < p[l])
				{
					swap(p[l],p[pos]);
					heapfy(p,l,size);
				}
			}
		}
		else	// r == size+1; l == size;
		{
			if(p[pos] < p[l])
			{
				swap(p[pos],p[l]);
			}
		}
	}
}



int main()
{
	int test[N];
	for(int i=0; i<N; i++) test[i]=i;
	randomShuffle(test);
	heapSort(test,N-1);
	if(check(test)) cout<<"AC"<<endl;
	else
	{
		cout<<"WA"<<endl;
		for(int i=0; i<N; i++)
		{
			cout<<test[i]<<endl;
		}
	}
	return 0;
}
