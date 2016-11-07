#include <iostream>
#include <vector>


using namespace std;

class Solution {
private:
    std::vector<int> nums;
    std::vector<int> origin_nums;

public:
    Solution(vector<int> nums) {
        this->nums = nums;
        this->origin_nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        this->nums = this->origin_nums;
        return this->nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto len = this->nums.size();
        for(auto i = 0 ; i< len; i++){
            swap(this->nums[i] , this->nums[rand() % len]);
        }
        return this->nums;
    }
    void print()
    {
        for(auto i : this->nums){
            std::cout<<i<<"  ";
        }
        std::cout<<std::endl;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main()
{

    std::vector<int> ww = {1,2,3,4,5};
    Solution *s = new Solution(ww);
    s->shuffle();
    s->print();

}
