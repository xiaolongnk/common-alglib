#include <iostream>
#include <vector>

using namespace std;


class Solution {
    public:
        int findMin(vector<int>& nums) {
            int l = 0 , r = nums.size() - 1;
            if(nums[l] <= nums[r]) {
                return nums[l];
            }else {
                while( l < r ) {
                    int mid = ( l + r ) >> 1;
                    if( nums[mid] >= nums[l] ) {
                        if(mid == l) l = mid + 1;
                        else l = mid;
                    } else if( nums[mid] <= nums[r] ){
                        if(r == mid) r = mid -1;
                        else r = mid;
                    }
                    cout<<"process "<<mid <<"  "<<l<<"  "<<r<<endl;
                    if(nums[l] < nums[r]) return nums[l];
                }
                return nums[l];
            }
        };
};

int main()
{
    Solution s;
    int array_length = 0;
    int tmp;
    int result_pos=0;
    vector<int> h ;
    while(true) {
        cout<<"please input array_length , 0 to stop"<<endl;
        cin>>array_length;
        h.clear();
        for(int i = 0; i < array_length ; ++i) {
            cin>>tmp;
            h.push_back(tmp);
        }
        for(const auto &x : h){
            cout<<x<<" ";
        }
        cout<<endl;
        result_pos = s.findMin(h);
        cout<<"min element is array is: "<<result_pos<<endl;
    }
    return 0;
}
