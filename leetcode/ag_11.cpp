#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int i = 0, j = height.size() - 1;
            int value = 0;
            while ( i < j) {
                int h = min(height[i], height[j]);
                value = max( value , (j - i) * h);
                while(i < j && height[i] <= h) ++i;
                while(i < j && height[j] <= h) --j;
            }
            return value;
        }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vs;
    vs.push_back(1);
    vs.push_back(2);
    vs.push_back(3);
    vs.push_back(4);
    vs.push_back(5);
    vs.push_back(6);
    int ans = s->maxArea(vs);
    cout<<ans<<endl;
    return 0;
}
