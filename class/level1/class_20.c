/****
 * simple bubble sort.
 * sort execrise
 * 2017-05-19 06:56
 ***/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


int bubble_sort(int *arr , int total)
{
    for(int i = 0 ; i < total ; ++i) {
        for(int j = 0; j < total ; ++j) {
            if(arr[i] < arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int a[5];
    a[0] = 1;
    a[1] = 3;
    a[2] = 8;
    a[3] = 0;
    a[4] = 2;
    bubble_sort(a , 5);
    for(int i = 0 ; i<5; ++i) {
        printf("%d " , a[i]);
    }
    printf("\n");
    return 0;
}
