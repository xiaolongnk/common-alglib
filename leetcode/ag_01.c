#include <stdio.h>

int * twoSum(int* nums, int numsSize, int target) {
//    int ans[2];
//    for(int i = 0; i<numsSize; i++){
//        for (int j = i+1 ; j<numsSize ; j++){
//            if(nums[i] + nums[j] == target){
//                ans[0] = i;
//                ans[1] = j;
//                break;
//            }
//        }
//    }
//    return ans;

    int ans[2];
    for(int i = 0; i<numsSize; i++){
        for (int j = i+1 ; j<numsSize ; j++){
            if(nums[i] + nums[j] == target){
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }
    return ans;

}

int main()
{
    int a[4]={0,4,3,0};
    int * ans = twoSum(a,4,0);
    printf("%d , %d\n",ans[0],ans[1]);
    return 0;
}
