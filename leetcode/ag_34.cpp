#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        auto left = 0 ;
        auto right = nums.size();
        auto middle = 0;
        while( left < right) {
            middle = ( left + right ) >> 1;
            if(nums[middle] == target){
                //find the range
                ans[0] = middle;
                ans[1] = middle;

                for(int j = middle ; j >= 0; --j) {
                    if(nums[j] == target) ans[0] = j;
                    else break;
                }

                for(int j = middle ;j < right; ++j){
                    if(nums[j] == target) ans[1] = j;
                    else break;
                }
                break;
            }else if(target > nums[middle]) {
                left = middle + 1;
            }else {
                right = middle;
            }
        }
        return ans;
    }
};

void printVector(vector<int> out)
{
    for(auto x:out){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main()
{
    Solution s;
    vector<int> ww = {2,4,4,4,7 , 9};
    auto ans = s.searchRange(ww , 4);
    printVector(ans);
    return 0;
}
