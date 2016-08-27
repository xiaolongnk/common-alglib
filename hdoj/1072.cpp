// 1072 bfs  you can revisit one position.
#include <stdio.h>

#include <queue>

using namespace std;
int t,r,c;

typedef struct node 
{
	int r,c,tm,cnt;
} step;
step start;
queue< step > mque;
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int board[10][10];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
			{
				scanf("%d",&board[i][j]);
				if (board[i][j] == 2)
				{
					start.r = i;
					start.c = j;
					start.tm = 6;
					start.cnt = 0;
				}
			}
		while( !mque.empty()) mque.pop();
		bool flag = false;
		mque.push(start);
		while( !mque.empty())
		{
			step cur,next;
			cur = mque.front();
			mque.pop();
			if (board[cur.r][cur.c]==3)
			{
				printf("%d\n",cur.cnt);
				flag = true;
				break;
			}
			for (int i=0; i<4; i++)
			{
				next.r = cur.r + dir[i][0];
				next.c = cur.c + dir[i][1];
				next.cnt = cur.cnt + 1;
				next.tm = cur.tm - 1;
				if (   next.r >= 0 && next.r < r
					&& next.c >= 0 && next.c < c
					&& next.tm && board[next.r][next.c] )
				{
					if (board[next.r][next.c] == 4)
					{
						board[next.r][next.c] = 0;
						next.tm = 6;
					}
					mque.push(next);
				}
			}
		}
		if (flag==false) puts("-1");
	}
	return 0;
}
