#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>

#include <stdio.h>

using namespace std;


int  h,l,sl,sh,num;
char map[12][12];
int  stepmap[12][12]; 

int dfs(int sh,int sl)
{ 
    if(sh<0||sh>=h||sl<0||sl>=l)
    {

        printf("%d step(s) to exit\n",num-1);
        return 0; 
    } 
    if(stepmap[sh][sl])
    {
        printf("%d step(s) before a loop of %d step(s)\n",stepmap[sh][sl]-1,num-stepmap[sh][sl]);
        return 0; 
    }       
    stepmap[sh][sl]=num; 
    if(map[sh][sl]=='E')
    {

        num++;
        dfs(sh,sl+1);

    }              
    if(map[sh][sl]=='W')
    {

        num++;
        dfs(sh,sl-1);
    } 

    if(map[sh][sl]=='S')
    {   

        num++;
        dfs(sh+1,sl);
    }

    if(map[sh][sl]=='N')
    {                
        num++;
        dfs(sh-1,sl);
    }                           

}

int main()
{
    int i,j; 
    while(scanf("%d%d%d",&h,&l,&sl)!=EOF)
    {
        if(h==0&&l==0&&sl==0)break; 
        sh=0;
        num=1;
        memset(stepmap,0,sizeof(stepmap)); 
        for(i=0;i<h;i++)
        {
            for(j=0;j<l;j++)
                cin>>map[i][j];
        } 
        dfs(0,sl-1);  
    }   
    return 0;
}
