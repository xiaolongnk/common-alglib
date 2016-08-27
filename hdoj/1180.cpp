// dayday up;
// good search prob;
#include <stdio.h>
#include <queue>
#include <iostream>

using namespace std;
char board[21][21];
int r,c;

int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

typedef struct node 
{
	int r,c,tm;
	const bool operator < (const node & a) const
	{
		return a.tm < tm;
	}
} step;

bool visit[21][21];

step start;
priority_queue< step > mque;


void bfs()
{
	while(!mque.empty()) mque.pop();

	mque.push(start);
	while(!mque.empty())
	{
		step cur,next;
		cur = mque.top();
		mque.pop();
		if (board[cur.r][cur.c]=='T')
		{
			printf("%d\n",cur.tm);
			return ;
		}
		for (int i=0; i<4; i++)
		{
			next.r = cur.r + dir[i][0];
			next.c = cur.c + dir[i][1];
			next.tm = cur.tm;

			if (board[next.r][next.c]=='.' ||
				board[next.r][next.c]=='T' )
			{
				next.tm ++;
			}
			else 
			{

				if (dir[i][0] == 0 )
				{
					if ( board[next.r][next.c]=='-' && cur.tm % 2 == 0)
					{
						next.c += dir[i][1];
						next.tm ++;
					}
					else if (board[next.r][next.c] =='-' && cur.tm % 2 == 1)
					{
						next.c += dir[i][1];
						next.tm += 2;
					}
					else if (board[next.r][next.c] =='|' && cur.tm % 2 == 0)
					{
						next.c += dir[i][1];
						next.tm += 2;
					}
					else if (board[next.r][next.c]=='|' && cur.tm % 2==1)
					{
						next.c += dir[i][1];
						next.tm ++;
					}
				}
				else if (dir[i][1] == 0)
				{
					if (board[next.r][next.c]=='-' && cur.tm %2 == 0)
					{
						next.r += dir[i][0];
						next.tm += 2;
					}
					else if (board[next.r][next.c]=='-' && cur.tm %2==1)
					{
						next.r += dir[i][0];
						next.tm ++;
					}
					else if (board[next.r][next.c]=='|' && cur.tm % 2 == 0)
					{
						next.r += dir[i][0];
						next.tm ++;
					}
					else if (board[next.r][next.c] =='|' && cur.tm % 2 == 1)
					{
						next.r += dir[i][0];
						next.tm += 2;
					}
				}
			}

			if (   next.r >= 0 && next.c >= 0
					&& next.r < r && next.c < c
					&& board[next.r][next.c]!='*'
					&& !visit[next.r][next.c])
			{
				visit[next.r][next.c] = true;
				mque.push(next);
			}
		}
	}
	puts("No ans");
}

int main()
{
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				cin>>board[i][j];
				visit[i][j] = false;
				if (board[i][j]=='S')
				{
					start.r = i;
					start.c = j;
					start.tm = 0;
					visit[i][j] = true;
				}
			}
		}
		bfs();
	}
	return 0;
}
