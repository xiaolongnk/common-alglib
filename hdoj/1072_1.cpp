# include <cstdio>
# include <cstring>
# include <iostream>
# include <queue>
using namespace std;

const int dx[4]={-1,1,0,0};
const int dy[4]={0,0,-1,1};
struct node
{
	int tim,step,x,y;
};
queue<node> que;
int main()
{
	int T,i,j,n,m,map[20][20],equ[20][20];
	node ip,id;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		while(!que.empty()) que.pop();
		memset(equ,0,sizeof(equ));
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]==2)
				{
					ip.x=i;
					ip.y=j;
					ip.step=0;
					ip.tim=6;
					que.push(ip);
				}
				if(map[i][j]==4) equ[i][j]=1;
			}
		while(!que.empty())
		{
			ip=que.front();
			que.pop();
			if(map[ip.x][ip.y]==3) break;
			if(1==ip.tim) continue;
			int xx,yy;
			for(i=0;i<4;i++)
			{
				xx=ip.x+dx[i];
				yy=ip.y+dy[i];
				if(xx>0 && xx<=n && yy>0 && yy<=m && map[xx][yy] )
				{
					if(4==map[xx][yy])
						if(!equ[xx][yy]) continue;
						else equ[xx][yy]--;
					id.x=xx;
					id.y=yy;
					id.step=ip.step+1;
					id.tim=ip.tim-1;
					if(map[xx][yy]==4) id.tim=6;
					que.push(id);
				}
			}
		}
		if(que.empty()) cout<<"-1"<<endl;
		else cout<<ip.step<<endl;
	}
	return 0;
}
