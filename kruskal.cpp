/*
 *  2013-08-04 11:06:33
 *	Min-spaning tree 
 *	By ouxiaolong!
 *
 */
#include <stdio.h>
#include <algorithm>

using namespace std;
#define M 100

int start[M],end[M],w[M],p[M],r[M];
int vn,en;	
int find(int x)
{
	if(x==p[x]) return x;
	else return p[x]=find(p[x]);	
}
// method to compare the weight of the edge!
bool cmp(const int &a,const int &b)
{
	return w[a]<w[b];   
}

int kruskal()
{
    int ans=0;
    for(int i=0;i<vn;i++) p[i]=i;   // ini the union and find set!
    for(int i=0;i<en;i++) r[i]=i;	
    sort(r,r+en,cmp);// sort the array of r[];
    for(int i=0;i<en;i++)
    {
        int e=r[i];
        int x=find(start[e]); int y=find(end[e]);
        if(x!=y){  
			ans+=w[e]; 
			p[x]=y; 	// union the two sets!
		}
    }
    return ans;
}
void ini()
{	
	// get edge of the graph and their weight!
    scanf("%d%d",&vn,&en);
	for(int i=0;i<en;i++) scanf("%d%d%d",&start[i],&end[i],&w[i]);
}
int main()
{
    ini();
    int ans=kruskal();
	printf("%d\n",ans);
    return 0;
}

