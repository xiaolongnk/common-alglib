/*
 * Author: light_light
 * Date:   2012--7--3
 * Description: A Standrad quicksort！
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>
#define M 100

using namespace std;

vector< int > data;
int media(vector< int >&a,int left,int right);

void prt(){
	for(int i=0;i<M;i++)
	{
		if(i%10==0) cout<<endl;
		cout<<data[i]<<" ";
	}
	cout<<endl;

}
void quicksort(vector< int >&a,int left,int right)
{
	if(left<right)
	{
		int q=media(a,left,right);
		quicksort(a,left,q-1);
		quicksort(a,q+1,right);
	}
}
int media(vector< int >&a,int left,int right)
{
	int x=a[right];
	int i=left-1;
	for(int j=left;j<right;j++)
		if( a[j]<x )
		{
			i++;
			swap(a[i],a[j]);
		}
	swap(a[i+1],a[right]);
	return i+1;
}


void quicksort(vector< int >&a)
{
	quicksort(a,0,a.size()-1);
}
void ini(vector<int>&a)
{
	int number;
	for(int i=0;i<M;i++){
		scanf("%d",&number);
		data.push_back(number);
	}
}

int main()
{
	ini(data);
	quicksort(data);
	for(int i=0;i<M;i++)
	{
		if(i%10==0) cout<<endl;
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return 0;
}
