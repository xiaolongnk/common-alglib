/* doggie */
#include <stdio.h>
#include <cstring>
#include <cstdlib>

using namespace std;

char board[10][10];
int t;
int row,col,tag;
int erow,ecol;
bool visit[8][8];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int nr,nc,nt;

bool dfs(int sr, int sc, int st)
{
	if (board[sr][sc]=='D'&& st==tag) 
	{
		return true;
	}
	else if(st >= tag)
	{
		return false;
	}
	else 
	{
		if(abs(erow-sr)+abs(ecol-sc)>tag-st)return false;//小剪枝
		for(int i=0; i<4; i++)
		{
			nr = sr + dir[i][0];
			nc = sc + dir[i][1];
			if ( nr>=0 && nr < row
				 && nc>=0 && nc < col
				 && board[nr][nc]!='X'
				 && visit[nr][nc]==false)
			{
				visit[sr][sc] = true;
				if (dfs(nr,nc,st+1)) return true;
				visit[sr][sc] = false;
			}
		}
	}
	return false;
}


int main()
{
	int i,j;
	int srow,scol;
	int sum=0;
	while(scanf("%d%d%d",&row,&col,&tag))
	{
		if(row==0 && col ==0 && tag ==0) break;
		for(i=0; i<row; i++)
			scanf("%s",board[i]);
		for(i=0; i<row; i++)
			for(j=0; j<col; j++)
			{	
				if(board[i][j]=='S') 
				{
					srow=i,scol=j;
				}
				else if(board[i][j]=='.')
				{
					sum++;
				}
				else if(board[i][j] =='D')
				{
					erow=i,ecol=j;
				}
			}
		memset(visit,0,sizeof(visit));
		//奇偶剪枝条件。
		if (sum+1 < tag||(tag+srow+scol+erow+ecol)%2==1) puts("NO");
		else if (dfs(srow,scol,0)) puts("YES");
		else puts("NO");
	}	
	return 0;
}
