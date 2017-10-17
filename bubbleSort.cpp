#include <iostream>

using namespace std;

int printList(int *a , int len)
{
    for(int i =0; i<10;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
}

int bubbleSort(int *a , int len)
{
    for(int i = 0; i<len; i++){
        bool flag = false;
        for(int j = 0; j<len - 1; j++){
            if(a[j] > a[j+1]){
                swap(a[j] , a[j+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}


int selectSort(int *a , int len)
{
    for(int i = 0; i<len ; i++){
        for(int j = i+1 ; j<len ; j++){
            if(a[i] > a[j]) swap(a[i], a[j]);
        }
        printList(a ,len);
    }
}

int main()
{
    int a[10] = {-3,-2,-1 , 0 ,9,6,13,1,8,27};
    //bubbleSort(a , 10);
    //selectSort(a , 10);
    return 0;
}
