#include <stdio.h>
#include <string.h>

/**
 * this is not an eary problem as you thought.
 * @author: ouxiaolong
 * @date  : 2016-11-07 16:58
 */

#define  DEBUG  1

int binary_find(int * , int , int , int);

int search(int* nums, int numsSize, int target) {

    if(DEBUG){
        puts("****** origin nums ******");
        for(int i = 0; i<numsSize; ++i){
            printf("%d ",nums[i]);
        }
        printf("  target is  %d\n", target);
        puts("****** origin nums ******");
    }
    // here find max element
    int left = 0 , right = numsSize  -1 , middle = 0 , max_pos = 0;
    while( left < right -1 ){
        middle = (left + right) >> 1;
        if(nums[middle] > nums[left]){
            left = middle;
        }else {
            right = middle;
        }
    }

    if(nums[left] < nums[right]) max_pos = right;
    else max_pos = left;

    int ans = -1;
    if(DEBUG) printf("max_pos is %d \n", max_pos);
    
    ans = binary_find(nums , 0 , max_pos , target);
    if(ans == -1){
        ans = binary_find(nums , max_pos + 1 , numsSize - 1, target);
    }

    if(DEBUG) printf("find ans %d\n\n\n",ans);
    return ans;
}

int binary_find(int *p , int left , int right , int target)
{ 
    if(DEBUG) printf("call binary_find with %d  %d " , left , right);
    int middle = 0;
    int ans = -1;
    while(left <= right){
        middle = ( left + right ) >> 1;
        if(p[middle] == target) {
            ans = middle;
            break;
        }else if(target > p[middle]){
            left = middle + 1;
        }else if(target < p[middle]){
            right = middle - 1;
        }
    }
    if(DEBUG){
        printf("  with ret  %d \n" , ans);
    }
    return ans;
}
/**
 * find min element in an array like 
 *      [7,8,9,1,2,3]
 *      [5,6,7,1,2,3]
 *      [1,2,3,4,5,7]
 */
int findMin(int * p , int arraySize , int target)
{
    int left =0 , right = arraySize - 1 , middle;
    // 至少有3个元素，才会进入循环
    while(left < right - 1 ){
        middle = left + ((right - left) >> 1);
        if(p[middle] > p[right]){
            left = middle;
        } else {
            right = middle;
        }
    }
    if(p[left] < p[right]) return left;
    else return right;
}

int main()
{
    int n;
    int nums[1000];
    int target;
    int ans;
    while(scanf("%d",&n)!=EOF){
        memset(nums , 0 , sizeof(nums));
        for(int i=0; i<n;i++){
            scanf("%d",&nums[i]);
        }
        scanf("%d",&target);
        ans = search(nums , n , target);
    }
    return 0;
}
