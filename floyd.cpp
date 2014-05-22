/*
 * Description: A standard implention of floyd algorithm! Include print the path!
 * Author: light_light
 * Date:   2012--7--4
 * 
 */

#include <cstring>
#include <iostream>
#include <vector>
#define M 100
#define Max 100000
using namespace std;

struct graph
{
    int arcs[M][M];
    int v;
    int e;
    graph()
    {
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                arcs[i][j]=Max;
        v=0;e=0;
    }
}csn;
bool ***path;
int w[M][M];

void ini()
{
    path=new bool **[M];    //Here create a matrix to store my path
    for(int i=0;i<M;i++) path[i]=new bool *[M];
    for(int i=0;i<M;i++)
        for(int j=0;j<M;j++)
            path[i][j]=new bool [M];
    cout<<"Please input your v and e:"; //Input your information for your graph
    cin>>csn.v>>csn.e;
    cout<<"Please input your edges:"<<endl;
    for(int i=0;i<csn.e;i++)
    {
        int h,k,w;
        cin>>h>>k>>w;
        csn.arcs[h][k]=w;
    }
}
void floyd(graph &p)
{
    for(int i=0;i<p.v;i++)
        for(int j=0;j<p.v;j++)
        {
            w[i][j]=p.arcs[i][j];
            for(int k=0;k<p.v;k++) path[i][j][k]=false;
            if(w[i][j]<Max) path[i][j][i]=true,path[i][j][j]=true;
        }
    for(int k=0;k<p.v;k++)
        for(int i=0;i<p.v;i++)
            for(int j=0;j<p.v;j++)
            {
                if(w[i][j]>w[i][k]+w[k][j])
                {
                    w[i][j]=w[i][k]+w[k][j];
                    for(int h=0;h<p.v;h++)
                        path[i][j][h]=path[i][k][h]||path[k][j][h];
                }
            }
}
int main()
{
    ini();
    floyd(csn);
    for(int i=0;i<csn.v;i++)
        for(int j=0;j<csn.v;j++)
        {
            if(i!=j)
            {
                cout<<i<<" to "<<j<<"'s weight: ";
                if(w[i][j]!=Max) cout<<w[i][j]<<" ====   ";
                else cout<<"INF ";
                cout<<"Path is: ";
                for(int k=0;k<csn.v;k++)
                    if(path[i][j][k]) cout<<k<<" ";
                cout<<endl;
            }
        }
    return 0;
}
