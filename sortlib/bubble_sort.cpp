#include <iostream>
#include "comm.h"


using namespace std;


int bubble_sort(int *arr , int total)
{
    for(int i = 0 ; i < total ; ++i) {
        for(int j = 0; j < total ; ++j) {
            if(arr[i] < arr[j]) {
                swap(arr[i] , arr[j]);
            }
        }
    }
}

int main()
{

	int test[N];
	for(int i=0; i<N; i++) test[i]=i;
	randomShuffle(test);
    for(int i = 0 ; i < N; ++i) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    bubble_sort(test , N);
    bool ans = check(test);
    if(ans) cout<<"Ac"<<endl;
    else cout<<"Wrong"<<endl;
    return 0;

}
