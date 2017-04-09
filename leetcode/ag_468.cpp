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
        string validIPAddress(string IP) {
            const string ans[3] = {"IPv4" , "IPv6" , "Neither"};
            const char comma = ':';
            const char dot = '.';
            string block;
            if(IP.substr(0 , 4).find(dot) != string::npos) {
                int dotcnt = 0;
                for(int j = 0 ; j < IP.length(); ++j) {
                    if(IP[j] == dot || (IP[j]!=dot && j == IP.size() - 1)) {
                        if(IP[j] == dot) dotcnt++;
                        if(!ip4bv(block)) return ans[2];
                        block.clear();
                    } else {
                        block += IP[j];
                    }
                }
                if(dotcnt>3) return ans[2];
                return ans[0];
            } else if (IP.substr(0 , 5).find(comma) != string::npos) {
                int commacnt = 0;
                int conjective_flag = 0;
                for(int j = 0; j < IP.size(); ++j) {
                    if(IP[j] == comma || (IP[j]!=comma && j == IP.size() - 1)) {
                        if(IP[j] == comma) commacnt++;
                        if(!ip6bv(block)) return ans[2];
                        block.clear();
                    } else {
                        block += IP[j];
                    }
                    if(j && IP[j] == IP[j-1] && IP[j] == comma ) {
                        // no 2 conjective comma
                        if(conjective_flag) return ans[2];
                        else conjective_flag = 1;
                    }
                }
                if(!conjective_flag) {
                    // comma not enough
                    if(commacnt < 7) return ans[2];
                } else {
                    if(commacnt > 5) return ans[2];
                }
                // too many comma
                if(commacnt>7) return ans[2];
                return ans[1];
            }
            return ans[2];
        }

        bool ip4bv(string &block) {
            if(block.length() > 3) return false;
            short sum = 0;
            if(block[0] == '0' && block.length() > 1) return false;
            for(int i =0 ; i < block.length() ; ++i) {
                if( block[i] < '0' && block[i] >'9' ) return false;
                sum += (block[i] - '0') * 10; 
            }
            if(sum>255) return false;
            return true;
        }

        bool ip6bv(string &block) {
            if(block.length() >4 ) return false;
            const string ip6charset ="0123456789abcdefABCDEF";
            for(int i = 0 ; i < block.length() ; ++i) {
                if(ip6charset.find(block[i])==string::npos) {
                    return false;
                }
            }
            return true;
        }
};


int main()
{
    string str = "";
    Solution s;
    while(cin>>str) {
        cout<<str<<"   :   "<<s.validIPAddress(str)<<endl;
    }
    return 0;
}
