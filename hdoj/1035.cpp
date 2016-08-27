// 1035 robot motion
// dfs

#include <stdio.h>
#include <string.h>

using namespace std;

#define N 100

int visit[N][N];
char board[N][N];
int nx,ny,s;

void solve(int start){
    int ans = 1;
    int curx = start-1;
    int cury = 0;
    char ch;
    while(true){
        if(cury<0 || curx <0 || cury > ny-1 || curx > nx-1 ){
            printf("%d step(s) to exit\n",ans-1);
            return;
        }
        if(visit[cury][curx]){
            printf("%d step(s) before a loop of %d step(s)\n",
                    visit[cury][curx]-1,ans-visit[cury][curx]);
            return;
        }
        ch = board[cury][curx];
        visit[cury][curx] = ans;
        ans++;
        switch(ch){
            case 'N':
                cury-=1;
                break;
            case 'S':
                cury+=1;
                break;
            case 'W':
                curx-=1;
                break;
            case 'E':
                curx+=1;
                break;
        }
    }   
    printf("\n");
}


int main(){
    while(scanf("%d%d%d",&ny,&nx,&s)!=EOF){
        if(nx==0 && ny==0 &&s==0){
            break;
        }
        for(int i=0; i<ny;i++){
            scanf("%s",board[i]);
        }
        memset(visit,0,sizeof(visit));
        solve(s);
    }
}
