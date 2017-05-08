#include <stdio.h>


void convert_to_binary(int num)
{
    if(num < 0) return;
    int j = sizeof(int) * 8;
    for (int i = 0 ; i < j ; ++i) {
        printf("%d",(num >> (j - i - 1)) & 0x1);
    }
    printf("\n");
}

int main()
{
    int a;
    while(1) {
        printf("please input your integer (any negative integer to quit):");
        scanf("%d",&a);
        if(a < 0) break;
        convert_to_binary(a);
    }
    return 0;
}
