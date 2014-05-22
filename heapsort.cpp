/*
 * Tags: sort!
 * 2013-08-04 15:59:12 
 * Author: Ouxiaolong!
 * Project: Standrad heapsort!
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
vector< int > data;

#define M 100
#define leftchild(i) (i<<1)+1

void ini()
{
    for(int i=0;i<M;i++)
        data.push_back(rand()%1797);
}
//This function will create a max element first heap,This
//is the basic feature of this operation!
// n is the size of the array that is a!
void perdown(vector< int >&a,int pos,int n){
    int child;
    int temp;
    for(temp=a[pos];leftchild(pos)<n; pos=child){
        child=leftchild(pos);
        if( child!=n-1 && a[child]<a[child+1] ) child++;
        //Find the correct position!
        if( temp<a[child] ) a[pos]=a[child];
        else break;
    }
    a[pos]=temp;  //In fact this is the position of a child!
}

void heapsort(vector< int >&a){
    for(int i=a.size();i>=0;i--)//Build heap
        perdown(a,i,a.size());
    //Delete Max element and in a.size() times operation
    //the list will become a sorted one!
    for(int j=a.size()-1;j>0;j--){
        swap(a[0],a[j]);
        perdown(a,0,j);
    }
}
// check if the sort is correct!
bool check()
{
    for(int i=0;i<data.size();i++)
        for(int j=i;j<data.size();j++)
            if(data[i]>data[j]) return false;
    return true;
}
int main()
{
    ini();
    heapsort(data);
    if(check()) printf("Yes!\n");
    else printf("No\n");
    return 0;
}

