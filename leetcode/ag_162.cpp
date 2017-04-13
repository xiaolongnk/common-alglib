#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

void printVector(vector<int>& test) {
    for(const auto & x : test) {
        cout<<x<<" ";
    }
    cout<<endl;
}


class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int l = 0 , r = nums.size() - 1 , m = 0;
            while(l <= r ) {
                m = (l + r)>>1;
                if( (m == 0 && m+1<=nums.size() 
                            && nums[m] > nums[m+1]) ||
                    (m == nums.size() - 1 && nums[m] > nums[m-1]) ||
                    (nums[m] > nums[m-1] && nums[m] > nums[m+1]) )
                {
                    break;
                }else if((m==0 && m+1 < nums.size() && 
                            nums[m] < nums[m+1])||
                        (nums[m]>nums[m-1] && nums[m]<nums[m+1])) 
                {
                    l == m ? ++l :l = m;
                }else if((nums[m]<nums[m-1] && nums[m]>nums[m+1]) ||
                        (nums[m]<nums[m-1] && nums[m]<nums[m+1]))
                {
                    r == m ? --r : r = m;
                }
            }
            return m;
        }
};

void get_input()
{
    int total_line = 0;
    int total = 0;
    vector<int> ans;
    cin>>total_line;
    for(int i = 0 ; i < total_line ; ++i) {
        cin>>total;
        for(int i =0; i < total; ++i) {
            int tmp;
            cin>>tmp;
            ans.push_back(tmp);
        }
        Solution s ;
        cout<<s.findPeakElement(ans)<<endl;
        ans.clear();
    }
}

int main()
{
    get_input();
    return 0;
}
