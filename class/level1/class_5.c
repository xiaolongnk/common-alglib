#include <stdio.h>

void safe_flush()
{
    char ch;
    while(( ch = getchar()) != '\n' && ch!=EOF);
}

int main()
{
    int a, b;
    char op;
    printf("Welcome to use simple caculator: num op num\ninput three @ @ @ to quit program!\n");
    while(1) {
        printf("please input operator:(+-*/)\n");
        scanf("%c %d %d", &op , &a , &b);
        safe_flush();
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

