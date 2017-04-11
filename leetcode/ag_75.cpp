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
		void sortColors(vector<int>& nums) {
            int start_0 = 0 , start_2 = nums.size() - 1;
            for(int i = 0 ; i < nums.size() ; i++) {
                if(nums[i] == 0) swap(nums[start_0++] , nums[i]);
                if(nums[i] == 2) swap(nums[start_2--] , nums[i]);
            }
            for(const auto & x : nums) {
                cout<<x<<" ";
            }
            cout<<endl;
		}
};

int main()
{
    Solution s;
    int arr[] = {0,2,0,0,1,1,1,2,0,0};
    vector<int> ans ;
    for(int i = 0 ; i < 10; ++i) {
        ans.push_back(arr[i]);
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    s.sortColors(ans);
	return 0;
}
