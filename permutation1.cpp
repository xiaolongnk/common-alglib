/* 
 * 用来产生一个序列的全排列
 * 2013-08-05 11:05:50 
 * xiaolongou
 */

#include <iostream>
#include <cstdio>

using namespace std;
#define M 100
int aa[M];
int pp[M];
void permutation(int *a,int n,int *p, int cur)
{
    if(cur==n)
    {
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
    else for(int i=0;i<n;i++)   if(!i||(p[i]!=p[i-1]))
    {
        int c1=0,c2=0;
        for(int j=0;j<cur;j++) if(a[j]==p[i]) c1++;
        for(int j=0;j<n;j++) if(p[i]==p[j]) c2++;
        if(c1<c2)
        {
            a[cur]=p[i];
            permutation(a,n,p,cur+1);
        }
    }
}

int main()
{
    int n; 
    cout<<"Please input your number:";  scanf("%d",&n);
    cout<<"Please input your numbers:"<<endl;
    for(int i=0;i<n;i++) cin>>pp[i];
    permutation(aa,n,pp,0);
    return 0;
}
