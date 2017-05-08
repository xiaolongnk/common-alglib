#include <stdio.h>

#define PRIME_START 2
void printPrimer(int num)
{
    const int number_width = 10;
    int cnt = 0;
    for(int i = PRIME_START ; i < num ; ++i) {
        int is_p = 1;
        for(int j = PRIME_START ; j < i ; ++j) {
            if((i % j) == 0) {
                is_p = 0;
                break;
            }
        }
        if(is_p) {
            ++cnt;
            if(cnt % number_width == 0) {
                printf("  %d\n" , i);
            }else {
                printf("  %d" , i);
            }
        }
    }
    printf("\n");
}


int main()
{
    printf("This program is aim to print primer numbers [1,1000]\n");
    int num = 0;
    const int max_num = 1000;
    const int min_num = 2;
    const int quit_num = -1;
    while(1) {
        printf("Please input your max number:");
        scanf("%d",&num);
        if(num == quit_num) break;
        if(num < min_num || num > max_num) {
            printf("Your number is out of range, please reinput.\n");
            continue;
        }
        printPrimer(num);
    }
    printf("Bye!\n");
    return 0;
}
