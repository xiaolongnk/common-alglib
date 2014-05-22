/*
 * Description :A standard impletation of bellmanford algorithm!
 *              This can be used to caculate when the weight of the edge
 *              can be negative! 
 *              Adjance without pointer!
 * Author   :   light_light
 * Date: 2012--7--4
 */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define INF 100000
#define M 100

int u[M],v[M],first[M],next[M],w[M],vn,en;
int d[M];
int s;
void ini()
{
    cin>>vn>>en;
    for(int i=0;i<vn;i++) first[i]=-1;
    for(int i=0;i<en;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
        next[i]=first[u[i]];    //add this edge in the list!
        first[u[i]]=i;      //list without point!
    }
    cin>>s;
}
void bellmanford(int s)
{
    queue< int >q;
    bool visit[M];
    for(int i=0;i<vn;i++) d[i]=(i==s?0:INF);
    memset(visit,0,sizeof(visit));
    q.push(s);
    while(q.empty()==false)
    {
        int x=q.front();
        q.pop();
        for(int e=first[x];e!=-1;e=next[e])
            if(d[v[e]]>d[x]+w[e])
            {
                d[v[e]]=d[x]+w[e];
                if(visit[v[e]]==false)
                {
                    visit[v[e]]=true;
                    q.push(v[e]);
                }
            }
    }
}


int main()
{   
    ini();
    bellmanford(s);
    for(int i=0;i<vn;i++)
        if(i!=s)
        {
            cout<<s<<" to "<<i<<"  ||  "<<d[i]<<endl;
        }
    return 0;
}
