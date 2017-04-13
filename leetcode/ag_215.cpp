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

#define left(i) ((i<<1) + 1)
        void heapfy(vector<int>&nums , int pos) {
            int l = left(pos);
            if(l >= nums.size()) return;
            int r = l + 1;
            int min_i = 0;
            if(r >= nums.size()) min_i = l;
            else {
                min_i = nums[l] > nums[r] ? r : l;
            }
            if(nums[pos] > nums[min_i]) {
                swap(nums[pos] , nums[min_i]);
                heapfy(nums , min_i);
            }
        }

        int findKthLargest(vector<int>& nums, int k) {
            vector<int> heap;
            for(int i = 0; i < k ; ++i) {
                heap.push_back(nums[i]);
            }

            for(int i = (k)/2 + 1; i>=0 ; --i) {
                heapfy(heap , i);
            }

            for(int i = k; i < nums.size(); ++i) {
                if(nums[i] > heap[0])  {
                    heap[0] = nums[i];
                    heapfy(heap , 0);
                }
            }
            return heap[0];
        }
};

int main()
{
    vector<int> test ;
    int arr[] = {5,6,2,1,9,10,3};
    for(int i = 0; i < 7; ++i)  test.push_back(arr[i]);
    for(const auto &x : test) cout<<x<<" ";
    cout<<endl;
    swap(test[0], test[1]);
    for(const auto &x : test) cout<<x<<" ";
    cout<<endl;


    Solution s ;
    cout<<s.findKthLargest(test , 1)<<endl;



    return 0;
}
