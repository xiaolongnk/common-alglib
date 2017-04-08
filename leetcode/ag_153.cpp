#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int findMin(vector<int>& nums) {
            int l = 0 , r = nums.size() ;
            while( l < r ) {
                int mid = ( l + r ) >> 1;
                if( nums[mid] >= nums[l] ) {
                    l = mid + 1;
                } else if( nums[mid] <= nums[r] ){
                    r = mid ;
                }
            }
            return l;
        };
};

int main()
{
    Solution s;
    int a[6] = {4,5,6,0,1,2};
    vector<int> h ;
    for(int i = 0; i < 6; ++i) {
        h.push_back(a[i]);
    }
    s.findMin(h);
    return 0;
}
