#include <stdio.h>

#define MAX 100

typedef const int cint;


void printResult(int *p , cint start_pos , cint total , cint interval)
{
    int cnt = 0;
    while(cnt < total - 1) {
        for()
    }
}

int main()
{
    int total = 0;
    int start_pos = 0;
    int interval = 0;
    int flag_arr[MAX];

    while(1) {
L0:
        printf("please input total people(<%d):",MAX);
        scanf("%d", &total);
        if(total > MAX) {
            printf("number of total must less than %d , please input again\n");
            goto L0;
        }
L1: 
        printf("please input start pos(<%d) :",total);
        scanf("%d", &start_pos);
        if( start_pos > total) {
            printf("number of start pos must less than %d , please input again\n" , total);
            goto L1;
        }
        printf("please input your interval\n");
        scanf("%d" , &interval);
        for(int i = 0 ; i < total; ++i) flag_arr = [1];
        printResult(flag_arr , start_pos , total , interval);

    }

    return 0;
}
