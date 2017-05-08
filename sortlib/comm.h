#ifndef _COMM_H_
#define _COMM_H_

#define N 1000
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <vector>
#include <ctime>

using namespace std;

inline void randomShuffle(int *p)
{
	for(int i=0; i<N-1; i++)
	{
		int temp = rand()%(N-1);
		swap(p[N-i-1],p[temp]);
	}
}
inline bool check(int *p)
{
	for(int i=0; i<N-1; i++)
		if(p[i]>p[i+1]) return false;
	return true;
}


#endif
