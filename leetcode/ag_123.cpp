#include <iostream>
#include <vector>
using namespace std;



class Solution { 
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), num = 2;
        if (n <= 1) return 0;
        vector<vector<int> > dp(num + 1, vector<int>(n, 0));
        for (int k = 1; k <= num; k++) {
            int temp = dp[k - 1][0] - prices[0];
            for (int i = 1; i < n; i++) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + temp);
                temp = max(temp, dp[k - 1][i] - prices[i]);
            }
        }
        for(int i = 0; i < num+1; i++) {
            for (int j = 0; j < n; j++) {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[num][n - 1];
    } 
} ss;
int main()
{
    int input[] = {3,3,5,0,0,3,1,4 };
    vector<int> s(input, input + sizeof(input)/sizeof(int));
    int ans = ss.maxProfit(s);
    cout<<"ans is"<<ans<<endl;
    return 0;
}
