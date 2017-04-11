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
        void sortColors(vector<int>& nums) {
            int start_0 = 0 , start_2 = nums.size() - 1;
            for(int i = 0 ; i <= start_2 ; i++) {
                int tmp_val = nums[i];
                if(tmp_val == 0) swap(nums[start_0++] , nums[i]);
                else if(tmp_val == 2) {
                    while(nums[start_2] == 2) {
                        --start_2;
                    }
                    if(i > start_2) break;
                    swap(nums[i] , nums[start_2]);
                    if(nums[i] == 0) --i;
                    --start_2;
                }
            }
        }
};
void printLine()
{
    cout<<"--------------"<<endl;
}
int main()
{
    Solution s;
    vector<int> ans;
    int total , tmp;
    cin>>total;
    int case_num = 0;
    for(int i = 0 ; i < total ; ++i) {
        cin>>case_num;
        for(int _i = 0; _i < case_num ; ++_i) {
            cin>>tmp;
            ans.push_back(tmp);
        }
        printLine();
        printVector(ans);
        s.sortColors(ans);
        printVector(ans);
        printLine();
        ans.clear();
    }
    return 0;
}
