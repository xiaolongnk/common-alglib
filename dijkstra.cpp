/*
 * Description: A standard implemention of dijkstra algorithm!
 * Author: light_light
 * Date : 2012--7--3
 */

#include <iostream>
#include <vector>
#define M 100
#define Max 1000000
using namespace std;

struct graph    //data structure of my graph, undirected graph;
{
    int arcs[M][M];
    int v;
    int e;
    graph()
    {
        v=0;e=0;
        for(int i=0;i<M;i++)
            for(int j=0;j<M;j++)
                arcs[i][j]=Max;
    }
}csn;

vector< int > path[100];
int w[M];

void ini()
{
    cout<<"Please input v and e:";
    cin>>csn.v>>csn.e;
    cout<<"Please input your edges:"<<endl;
    for(int i=0;i<csn.e;i++)
    {
        int h,k,w;
        cin>>h>>k>>w;
        csn.arcs[h][k]=w;
    }
}

void dijkstra(graph &p,int s)
{
    vector< int > tp;
    bool visit[M];
    for(int i=0;i<p.v;i++)
    {
        visit[i]=false;
        w[i]=p.arcs[s][i];
        if(w[i]<Max)    //Set the current information! 
        {
            path[i].push_back(s);
            path[i].push_back(i);
        }
    }
    visit[s]=true; w[s]=0;
    path[s].push_back(s);
    for(int i=1;i<p.v;i++)
    {
        int Min=Max;
        int key;
        for(int j=0;j<p.v;j++)
             if(!visit[j])
                 if(w[j]<Min){
                     Min=w[j];key=j;
                 }
        visit[key]=true;    //visit this node and update the information!
        for(int h=0;h<p.v;h++)
            if(!visit[h] && (Min+p.arcs[key][h]<w[h])){
                w[h]=Min+p.arcs[key][h];
                path[h]=path[key];
                path[h].push_back(h);
            }
    }
}

int main()
{
    ini();
    cout<<"Please input your start point:"; 
    int s; cin>>s;
    cout<<endl;
    dijkstra(csn,s);
    for(int i=0;i<csn.v;i++)
    { 
        cout<<s<<" to "<<i<<"'s weight :"<<w[i]<<endl;
        if(w[i]==Max) cout<<"Not connected!"<<endl;
        else
        {
            cout<<"Path is: ";
            for(int j=0;j<path[i].size();j++)
            cout<<path[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}

