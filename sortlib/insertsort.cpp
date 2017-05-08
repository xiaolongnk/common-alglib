/* 2012--7--2
 * Author: light_light
 * Description: A Standard implement of insertionsort!
 * For exercise!
 */
#include "comm.h"

#define M 100

vector< int > data;
void insertsort(vector< int > &a)
{
    for(int i=1;i<a.size();i++)
    {
        int j;
        for(j=i;j>0&&a[j-1]>a[i];j--)
            a[j]=a[j-1];
	   a[j]=a[i];
    }
}
void ini()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<M;i++)
        data.push_back(rand()%234645); 
}
bool check()
{
    for(int i=0;i<M;i++)
    {
        for(int j=i;j<M;j++)
            if(data[i]>data[j]) return false;
    }
    return true;
}
int main()
{
    ini();
    printf("After insertionsort operation:\n");
    insertsort(data);
    if(check()) printf("Yes!\n");
    else 
    {
        printf("No! For example:\n");
        for(int i=0;i<100;i++) printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}
