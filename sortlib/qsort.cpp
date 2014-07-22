#include <iostream>
#include <cstdlib>
#include "comm.h"

using namespace std;
int process(int *,int, int);

void qsort(int *p, int left, int right)
{
	if( left < right)
	{
		int n = process(p,left,right);
		qsort(p,left,n-1);
		qsort(p,n+1,right);
	}
}

int process(int *p, int left, int right)
{
	int temp = left-1;
	int key = p[right];
	
	for(int i=left; i<right; i++)
	{
		if(p[i]<key)
		{
			swap(p[++temp],p[i]);
		}
	}
	swap(p[temp+1],p[right]);
	return temp+1;
}


int main()
{
	int test[N];
	for(int i=0; i<N; i++) test[i]=i;
	randomShuffle(test);
	qsort(test,0,N-1);
	if(check(test)) cout<<"AC"<<endl;
	else cout<<"WA"<<endl;
	return 0;
}
