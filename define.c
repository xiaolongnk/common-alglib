#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a , b)                     \
    *(a) = (*(a)) ^ (*(b));             \
    *(b) = (*(a)) ^ (*(b));             \
    *(a) = (*(a)) ^ (*(b));   

#define msort(a , n )                   \
    do{                                 \
        for(int i = 0; i < n; i++){     \
            for(int j =0 ; j < i ;j++){ \
                if(a[i] < a[j]) {       \
                    swap(a+i , a+j);    \
                }                       \
            }                           \
        }                               \
    }while(0)                           




#define printArr(a , n)                 \
    do                                  \
    {                                   \
        for(int i = 0;  i < n; i++)     \
            printf("%d ",a[i]);         \
        printf("\n");                   \
    }while(0)

int main()
{
    int n =10 , m = 20;
    int ** a = calloc(n , sizeof(int *));
    for(int i = 0;  i < n ; i++){
        a[i] = calloc(m , sizeof(int));
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j<m ; j++){
        }
        printf("\n");
    }

    int *p[10];
    for(int i = 0; i<n;i++){
        p[i] = calloc(n, sizeof(int));
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j<n ; j++){
        }
        printf("\n");
    }
    int cc[10] = {1,1,1,1,1,1,1,1,1,1};
    int aaa[10] = {2,2,2,2,2,2,2,2,2,2};
    int ddd[10] = {3,3,3,3,3,3,3,3,3,3};
    int c1[3][10];
    for(int i = 0 ; i<3 ; i++)
        for(int j = 0 ; j<10 ;j++) a[i][j] = i+j;
}

