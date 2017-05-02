#include <stdio.h>

int main()
{
    char name[100] ;
    int ret = scanf("%s" ,name);
    if(ret) {
        printf("Hello : %s\n" , name);
    }
    return 0;
}
