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
            stringstream nss(IP);
            string block;
            if(IP.substr(0 , 4).find(dot) != string::npos) {
                int i = 0;
                while(getline(nss , block , dot)) {
                    ++i;
                    if(!ip4bv(block)) return ans[2];
                    block.clear();
                }
                cout<<block<<endl;
                cout<<i<<endl;
                if( i > 4) return ans[2];
                return ans[0];
            } else if (IP.substr(0 , 5).find(comma) != string::npos) {
                int i = 0;
                while(getline(nss , block, dot)){
                    ++i;
                    if(!ip6bv(block)) return ans[2];
                    block.clear();
                }
                cout<<block<<endl;
                if( i > 6 ) return ans[2];
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
            if(block[0] == '0' && block.length() > 1) return false;
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
