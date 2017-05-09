#include <stdio.h>

#define MAX 100

typedef const int cint;

void printCircle(int *p , cint total)
{
    for(int i = 0 ; i < total ; ++i) {
        if(p[i] == 1) printf("%d  " , i+1);
        else printf("   ");
    }
    printf("\n");
}

void printResult(int *p , cint start_pos , cint total , cint interval)
{
    if(start_pos < 1) {
        printf("start pos must > 0 \n");
        return;
    }
    printCircle(p , total);

    int dead_cnt = 0;
    int cursor = start_pos;
    int _interval = 0;
    while(dead_cnt < total - 1) {
        if(p[cursor - 1] == 1) {
            _interval++;
        }
        if(_interval == interval) {
            p[cursor - 1] = 0;
            ++dead_cnt;
            printCircle(p , total);
            _interval = 0;
        }
        if(cursor == total ) cursor = 1;
        else ++cursor;
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
            printf("number of total must less than %d , please input again\n" , MAX);
            goto L0;
        }
        if(total == -1) {
            printf("Bye Bye!\n");
        }
        return 0;
L1: 
        printf("please input start pos(<%d) :",total);
        scanf("%d", &start_pos);
        if( start_pos > total) {
            printf("number of start pos must less than %d , please input again\n" , total);
            goto L1;
        }
        printf("please input your interval:");
        scanf("%d" , &interval);
        for(int i = 0 ; i < total; ++i) flag_arr[i] = 1;
        printResult(flag_arr , start_pos , total , interval);
    }

    return 0;
}
