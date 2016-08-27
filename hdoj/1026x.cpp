#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;

struct P
{
    int x,y,t;
    P(){}
    P(int xx,int yy,int tt)
    {
        x=xx,y=yy,t=tt;
    }
    const bool operator<(const P &x)const
    {
        return x.t<t;
    }
};

priority_queue<P>que;

int n,m;
int i,j,k;
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char MAP[110][110];
bool vis[110][110];
int dir[110][110];

bool check(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m) return true;
    if(vis[x][y]==true || MAP[x][y]=='X') return true;
    return false;
}

int output(int x,int y)
{
    if(x==0 && y==0)
    {
        int nt=1;
        printf("%ds:(%d,%d)->",nt,x,y);
        return nt;
    }
    else
        k=dir[x][y];
    int nt=output(x-fx[k],y-fy[k]);
    printf("(%d,%d)\n",x,y);
    if(0<MAP[x][y]-'0' && MAP[x][y]-'0'<=9)
    {
        int l=MAP[x][y]-'0';
        while(l--)
        printf("%ds:FIGHT AT (%d,%d)\n",++nt,x,y);
    }
    if(nt==j) return 0;
    printf("%ds:(%d,%d)->",++nt,x,y);
    return nt;
}

void bfs()
{
    P NOW,NEXT;
    while(!que.empty()) que.pop();
    que.push(P(0,0,0));
    dir[0][0]=-1;
    while(!que.empty())
    {
        NOW = que.top();
        que.pop();
        if(NOW.x==n-1 && NOW.y==m-1)
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",j=NOW.t);
            output(n-1,m-1);
            puts("FINISH");
            return ;
        }
        for(k=0;k<4;k++)
        {
            NEXT = P(NOW.x+fx[k], NOW.y+fy[k], NOW.t+1);
            if(check(NEXT.x, NEXT.y)) continue;
            if(0<MAP[NEXT.x][NEXT.y]-'0' && MAP[NEXT.x][NEXT.y]-'0'<=9)
            for(i=0;i<MAP[NEXT.x][NEXT.y]-'0';i++)
                NEXT.t++;
            dir[NEXT.x][NEXT.y]=k;
            vis[NEXT.x][NEXT.y] = true;
            que.push(NEXT);
        }
    }
    puts("God please help our poor hero.\nFINISH");
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",MAP[i]);
            for(j=0;j<m;j++)
                vis[i][j]=false;
        }
        bfs();
    }
    return 0;
}
