#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
	public:
		int findPeakElement(vector<int>& nums) {
            int l = 0 , r = nums.size() - 1;
            while(l <= r ) {
                int m = (l + r)>>1;
                if(m == 0 && nums[m] > nums[m+1]) {
                    return m;
                }else if(m == nums.size() - 1 && nums[m] > nums[m-1]) {
                    return m;
                }else if(nums[m] > nums[m-1] && nums[m] > nums[m+1]) {
                    return m;
                }else if(nums[m] > nums[m-1] && nums[m] < nums[m+1]) {
                    l = m;    
                }else if(nums[m] < nums[m-1] && nums[m] > nums[m+1] ) {
                    r = m;
                }
            }
            // not found.
            return -1;
		}
};


int main()
{
	return 0;
}
