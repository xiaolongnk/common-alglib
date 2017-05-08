/*************************
 * author: xiaolongou
 * date:  2013-12-11 19:40
 ************************/
#include "comm.h"

#define LEFT(i) (i<<1)+1

void heapfy(int*,int,int);

// size is last element idx of the array;
void heapSort(int *p,int size)
{
	for(int i=size/2; i>=0; i--)
	{
		heapfy(p,i,size);
	}
	for(int i=0; i<size; i++)
	{
		swap(p[0],p[size-i]);
		heapfy(p,0,size-i-1);
	}
}

// create a max-heap first element is max element;
// size is idx of last element.

void heapfy(int *p, int pos, int size){
    int left = LEFT(pos);
    int right = left + 1;
    if(left == size){
        if(p[pos] < p[left]) swap(p[pos],p[left]);
        return;
    }
    if(right <= size){
        int max_i = p[left] < p[right] ? right : left ;
        if(p[pos] < p[max_i]) {
            swap(p[pos] , p[max_i]);
            heapfy(p , max_i , size);
        }
    }
}

int main()
{
	int test[N];
	for(int i=0; i<N; i++) test[i]=i;
	randomShuffle(test);
	heapSort(test,N-1);
	if(check(test)) cout<<"AC"<<endl;
	else
	{
		cout<<"WA"<<endl;
		for(int i=0; i<N; i++)
		{
			cout<<test[i]<<endl;
		}
	}
	return 0;
}
