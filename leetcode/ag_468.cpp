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
        string validIPAddress(string ip) {
            const string ans[3] = {"IPv4" , "IPv6" , "Neither"};
            const char comma = ':', dot = '.';
            if(ip.substr(0 , 4).find(dot) != string::npos) {
                int sum = -1 , word_count = 0;
                for(int j = 0 ; j < ip.size() ; ++j) {
                    if(ip[j] >='0' && ip[j] <='9') {
                        if( sum == 0 ) return ans[2]; 
                        if( sum == -1 ) sum = 0;
                        sum = sum * 10 + (ip[j] - '0');
                        if(j == ip.size() - 1) {
                            ++word_count;
                            if(sum > 255) return ans[2];
                        }
                    }else if(ip[j] == dot ){
                        if(sum >256 || sum < 0) return ans[2];
                        if(j == ip.size() - 1 || j == 0 ) return ans[2];
                        sum = -1;
                        ++word_count;
                    }else {
                        return ans[2];
                    }
                }
                if(word_count != 4) return ans[2];
                return ans[0];
            } else if (ip.substr(0 , 5).find(comma) != string::npos) {
                int current_len =0, word_count = 0;
                for(int j = 0; j < ip.size(); ++j) {
                    if( (ip[j] >='0' && ip[j] <='9') ||
                        (ip[j] >='a' && ip[j] <='f') ||
                        (ip[j] >='A' && ip[j] <='F')) {
                        ++current_len;
                        if(current_len > 4) return ans[2];
                        if(j == ip.size() - 1) ++word_count; 
                    }else if(ip[j] == comma ) {
                        if(j == ip.size() - 1) return ans[2];
                        if(current_len) {
                            ++word_count;
                            current_len = 0;
                        }else {
                            return ans[2];
                        }
                    }else {
                        return ans[2];
                    }
                }
                if(word_count != 8) return ans[2];
                return ans[1];
                /**
                int conjective_flag = 0, current_len =0, word_count = 0;
                for(int j = 0; j < ip.size(); ++j) {
                    if(ip6charset.find(ip[j]) == string::npos) return ans[2];
                    if(ip[j] != comma) {
                        ++current_len;
                        if(current_len > 4) return ans[2];
                        if(j == ip.size() - 1) {
                            word_count++;
                        }
                    }
                    if(ip[j] == comma ) {
                        if(j == 0 && j + 1 < ip.size() && ip[j+1] != comma ) return ans[2];
                        if(j == ip.size() - 1 && j - 1 > 0 && ip[j-1] != comma) 
                            return ans[2];
                        if(j && ip[j-1] == comma) {
                            if(conjective_flag) return ans[2];
                            else conjective_flag = 1;
                        }
                        if(current_len) {
                            ++word_count;
                            current_len = 0;
                        }
                    }
                }
                if(conjective_flag) {
                    if(word_count > 6) return ans[2];
                } else {
                    if(word_count != 8) return ans[2];
                }
                return ans[1];
                ***/
            }
            return ans[2];
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
