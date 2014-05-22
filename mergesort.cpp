/*
 * Description: A standard implention of mergesort!
 * Author: light_light
 * Date: 2012--7--3
 *
 */
#include <iostream>
#include <vector>
#include <cstdlib>
#define M 100

using namespace std;
vector< int >data;
void ini()
{
    for(int i=0;i<M;i++)
        data.push_back(rand()%198);
}
void merge(vector< int >&a,vector< int >&tarray,int leftpos,int rightpos,int rightend);
void mergesort(vector<int >&a,vector<int >&tarray,int left,int right)
{
    if(left<right)
    {
        int center=(left+right)/2;
        mergesort(a,tarray,left,center);
        mergesort(a,tarray,center+1,right);
        merge(a,tarray,left,center+1,right);
    }
}

void merge(vector< int >&a,vector< int >&tarray,int leftpos,int rightpos,int rightend)
{
    int num=rightend-leftpos+1;
    int leftend=rightpos-1;
    int tpos=leftpos;
    while(leftpos<=leftend&&rightpos<=rightend)
        if(a[leftpos]<=a[rightpos]) tarray[tpos++]=a[leftpos++];
        else tarray[tpos++]=a[rightpos++];
    while(leftpos<=leftend) tarray[tpos++]=a[leftpos++];
    while(rightpos<=rightend) tarray[tpos++]=a[rightpos++];

    for(int i=0;i<num;i++,rightend--)
        a[rightend]=tarray[rightend];
}

void mergesort(vector< int >& a)
{
    vector< int >tarray(a.size());
    mergesort(a,tarray,0,a.size()-1);
}
int main()
{
    ini();
    mergesort(data);
    for(int i=0;i<M;i++)
    {
        if(i%10==0) cout<<endl;
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
}
