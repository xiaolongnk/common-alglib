#include <stdio.h>
#include <stdbool.h>


void printArray(int *p , int len)
{
    printf("****************\n");
    for(int i = 0; i<len ; ++i){
        printf("%d ",p[i]);
    }
    printf("\n****************\n");
}

int find_max_pos(int *nums , int left , int right )
{
    int max_pos = 0;
    int middle  = 0;
    int origin_right = right;
    while(left < right - 1){
        middle = (left + right) >> 1;
        if(nums[middle] == nums[left]){
            //how to deal with this
            if(nums[middle] == nums[right]){
                ++left;
                --right;
            }else if(nums[middle] > nums[right]){
                left = middle;
            }else {
                right = middle;
            }
        }else if(nums[middle] > nums[left]){
            left = middle;
        }else {
            right = middle;
        }
    }
    if(nums[left] < nums[right])  max_pos = right;
    else max_pos = left;
    while(max_pos < origin_right){
        if(nums[max_pos] == nums[max_pos+1]){
            ++max_pos;
        }else {
            break;
        }
    }
    return max_pos;
}

bool binary_search(int *nums , int left , int right , int target)
{
    int middle = 0;
    while(left <= right){
        middle = ( left + right ) >> 1;
        if(target == nums[middle]){
            return true;
        }else if(target > nums[middle]){
            left = middle + 1;
        }else {
            right = middle - 1;
        }
    }
    return false;
}

bool search(int * nums, int numsSize , int target)
{
    int left  = 0 , right = numsSize - 1, middle = 0;
    while(left < right - 1){
        middle = ( left + right ) >> 1;
        if(nums[middle] == target) return true;
        if(nums[middle] > nums[left]){
            if(target < nums[middle] && target >= nums[left]) right = middle;
            else left = middle + 1;
        }else if(nums[middle] < nums[left]){
            if(target > nums[middle] && target < nums[left]) left = middle + 1;
            else right = middle;
        }else {
            ++left;
        }
    }
    return false;
}

#define  DEBUG 1
bool bad_search(int* nums, int numsSize, int target) {
    int max_pos = find_max_pos(nums , 0 , numsSize -1);
    if(DEBUG){
        printf("max pos is %d\n",max_pos);
    }
    return binary_search(nums , 0 , max_pos ,target) || binary_search(nums ,max_pos + 1 , numsSize -1 , target);   
}

void test_binary_search()
{
    int testarr[15] = {1,2,3,3,3,3,4,4,4,5,5,6,6,6,6};
    int target[6] = {0,3,1,7,5,6};
    int targetlen = 6;
    int arrlen = 15;
    int ans = 0;
    printArray(testarr ,arrlen);
    for(int i =0; i<targetlen; ++i){
        ans =binary_search(testarr, 0 , arrlen -1 , target[i]);
        printf("find %d with ret %d\n",target[i] , ans);
    }
}

void test_find_max_pos()
{
    int testarr[5][6] = {
        {3,4,5,5,1,2},
        {9,9,9,1,2,3},
        {8,9,3,4,4,5},
        {1,2,5,6,6,6},
        {9,1,1,1,4,5}
    };
    int testnum = 5;
    int testlen = 6;
    int ans = 0;
    for(int i =0 ; i<testnum;i++){
        printArray(testarr[i] , testlen);
        ans = find_max_pos(testarr[i] , 0 , testlen - 1);
        printf("max_pos is %d\n",ans);
    }
}

void testMain()
{
//    int test[5] = {2,2,2,3,1};
    int test[21] = {1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1};
    int target = 2;
    int ans = search(test , 20 , target);
    printArray(test , 20);
    printf("ans is %d\n",ans);
}

int main()
{
    testMain();
    return 0;
}
