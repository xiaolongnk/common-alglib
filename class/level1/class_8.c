#include <stdio.h>

typedef const int cint;
void print_mul_table()
{
    cint x_max = 9;
    for(int i = 1 ; i <= x_max ; ++i){
        for(int j = 1; j <= i ; ++j) {
            printf("%d*%d=%d  ", i,j ,i*j);
        }
        printf("\n");
    }
}

int main()
{
    print_mul_table();
    return 0;
}
