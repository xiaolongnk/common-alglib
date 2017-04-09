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
               
    }
};


int main()
{
    string str = "172.30.21.8";
    string ip6_str = "a2:b1:b2:30:20:bb";
    if(str.substr(0 , 4).find('.') != string::npos) {
        cout<<"ipv4"<<endl;
    }else {
        cout<<"ipv6"<<endl;
    }
    stringstream nss(str);
    string block;
    for(int i = 0 ; i < 4; ++i) {
        getline(nss , block, '.');
        cout<<block<<endl;
    }
    return 0;
}
