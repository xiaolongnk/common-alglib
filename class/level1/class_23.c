/****
 * quick sort.
 * recursive execrise.
 * 2017-05-19 06:55
 * **/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void swap(int *a , int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int process(int *p, int left, int right)
{
	int temp = left;
	int key = p[right];
	for(int i=left; i<right; i++)
	{
		if(p[i]<key)
		{
			swap(&p[temp++],&p[i]);
		}
	}
	swap(&p[temp], &p[right]);
	return temp;
}
// left and right is idx of the array;
void qsort(int *p, int left, int right)
{
	if( left < right)
	{
		int n = process(p,left,right);
		qsort(p,left,n-1);
		qsort(p,n+1,right);
	}
}

int print_arr(int * p , int total) {
    for(int i = 0 ; i < total ; ++i ) {
        printf("%d " , p[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    int a[5];
    a[0] = 8;
    a[1] = 3;
    a[2] = 1;
    a[3] = 7;
    a[4] = 2;
    qsort(a , 0 , 4);
    print_arr(a , 5);
    return 0;
}
