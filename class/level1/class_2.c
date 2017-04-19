#include <stdio.h>

int main()
{
    int width = 5;
    for(int i = 0 ; i <= width * 2; ++i) {
        if( i < width) {
            for(int j = 0 ; j <= width * 2 ; ++j) {
                if(width - j == i || j - width == i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        } else {
            for(int j = 0 ; j <= width * 2 ; ++j) {
                if(width - j == width*2 - i  || j - width == width*2 - i) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
