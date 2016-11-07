#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0 , right = nums.size(), middle;
        while( left < right){
            middle = (left + right) >> 1;
            if(target == nums[middle]){
                return middle;
            }else if(target > nums[middle] ){
                left = middle + 1;
            }else {
                right = middle;
            }
        }
        return (left + right) >> 1;
    }
};

int main()
{


}
