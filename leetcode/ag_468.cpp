#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>


using namespace std;


class Solution {
    public:
        string validipAddress(string ip) {
            const string ans[3] = {"ipv4" , "ipv6" , "Neither"};
            const char comma = ':';
            const char dot = '.';
            if(ip.substr(0 , 4).find(dot) != string::npos) {
                int sum = -1;
                int word_count = 0;
                for(int j = 0 ; j < ip.size() ; ++j) {
                    if(ip[j] == dot || j == ip.size() - 1){
                        if(j ==  ip.size() - 1) sum = sum * 10 + (ip[j] - '0');
                        if(sum >256 || sum < 0) return ans[2];
                        sum = -1;
                        word_count++;
                    } else if(ip[j]>'0' && ip[j] <'9'){
                        return ans[2];
                    } else {
                        if(ip[j] > '0' && sum ==0) return ans[2]; 
                        if(sum == -1) sum = 0;
                        sum = sum * 10 + (ip[j] - '0');
                    }
                }
                if(word_count != 4) return ans[2];
                return ans[0];
            } else if (ip.substr(0 , 5).find(comma) != string::npos) {
                const string ip6charset = "0123456789abcdefABCDEF:";
                int commacnt = 0;
                int conjective_flag = 0;
                int current_len =0;
                int word_count = 0;
                for(int j = 0; j < ip.size(); ++j) {
                    if(ip6charset.fiind(ip[j]) == string::npos) return ans[2];
                    if(ip[j] != comma) {
                        ++current_len;
                        if(current_len > 4) return ans[2];
                    }
                    if((ip[j] == comma || ( j == ip.size() - 1 && ip[j] != comma ) && current_len) {
                        ++word_count;
                        current_len = 0;
                    }
                    if(j && ip[j] == ip[j-1] && ip[j] == comma ) {
                        // no 2 conjective comma
                        if(conjective_flag) return ans[2];
                        else conjective_flag = 1;
                    }
                }
                if(!conjective_flag) {
                    // comma not enough
                    if(word_count != 8) return ans[2];
                } else {
                    if(word_count > 6) return ans[2];
                }
                // too many comma
                if(commacnt>7) return ans[2];
                return ans[1];
            }
            return ans[2];
        }

};


int main()
{
    string str = "";
    Solution s;
    while(cin>>str) {
        cout<<str<<"   :   "<<s.validipAddress(str)<<endl;
    }
    return 0;
}
