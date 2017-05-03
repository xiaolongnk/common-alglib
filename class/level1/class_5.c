#include <stdio.h>

int main()
{
    int a, b;
    char op;
    while(1) {
        printf("please input operator:(+-*/)\n");
        scanf("%c %d %d", &op , &a , &b);
        if(op == '+') {
            printf("ans for %d %c %d is %d\n" , a ,op , b , a+b);
        } else if (op == '-') {
            printf("ans for %d %c %d is %d\n" , a ,op , b , a-b);
        } else if (op == '*') {
            printf("ans for %d %c %d is %d\n" , a ,op , b , a*b);
        } else if (op == '/') {
            printf("ans for %d %c %d is %d\n" , a ,op , b , a/b);
        } else {
            break;
        }
    }
    printf("see you!\n");
    return 0;
}

