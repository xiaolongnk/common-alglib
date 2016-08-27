/*
 * This problem should be marked, 
 * where you should place your visit[x][y] = true;
 * the place you place this will affect memory use.
 *
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;
#define NX 102
#define NY 102

int ss[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int nx,ny;
char board[NY][NX];
bool visit[NY][NX];
int dir[NY][NX];
int k, totalstep,i;

int output(int x, int y);

struct step
{
	int x, y,num;
	step(){}
	step(int a,int b, int c)
	{
		x = a;
		y = b;
		num = c;
	}
	const bool operator < (const step &x) const
	{
		return x.num < num;
	}
};
step cur,next;
priority_queue<step> mqueue;

void bfs()
{
	memset(visit,0,sizeof(visit));
	dir[0][0] = -1;
	while(!mqueue.empty()) mqueue.pop();
	mqueue.push(step(0,0,0));
	visit[0][0] = true;
	while(!mqueue.empty())
	{
		cur = mqueue.top();
		mqueue.pop();
		/*   think about this. */
		//visit[cur.y][cur.x] = true;
		if(cur.x == nx-1 && cur.y == ny-1)
		{
			totalstep = cur.num;
			printf("It takes %d seconds to reach the target position, let me "
					"show you the way.\n",totalstep);
			output(ny-1, nx-1);
			printf("FINISH\n");
			return;
		}
		
		for(i=0;i<4; i++)
		{
			next.x = cur.x + ss[i][0];
			next.y = cur.y + ss[i][1];
			if(next.x>=0 && next.x<nx && next.y>=0 && next.y <ny)
				if(!visit[next.y][next.x] && 
						board[next.y][next.x]!='X')
				{
					if(board[next.y][next.x]>='1' &&
							board[next.y][next.x]<='9')
					{
						next.num = cur.num + 
							board[next.y][next.x]-'0'+1;
					}
					else if(board[next.y][next.x] == '.')
					{
						next.num = cur.num + 1;
					}
					mqueue.push(next);
					dir[next.y][next.x] = i;
					visit[next.y][next.x] = true;
				}
		}
	}
	printf("God please help our poor hero.\nFINISH\n");
}
int output(int row, int col)
{
	if(row==0 && col ==0)
	{
		int a = 1;
		printf("%ds:(%d,%d)->",a,row,col);
		return a;
	}
	else  k = dir[row][col];
	int nt = output(row-ss[k][1],col-ss[k][0]);
	printf("(%d,%d)\n",row,col);
	if(0< board[row][col]-'0' && board[row][col]-'0'<=9)
	{
		int ll = board[row][col]-'0';
		while(ll--)
			printf("%ds:FIGHT AT (%d,%d)\n",++nt,row,col);
	}
	if (nt==totalstep) return 0;
	printf("%ds:(%d,%d)->",++nt,row,col);
	return nt;
}

int main()
{
	while(scanf("%d%d",&ny,&nx)!=EOF)
	{
		for(i=0; i<ny; i++)
				scanf("%s",board[i]);
		bfs();
	}
	return 0;
}

