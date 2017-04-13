#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
    public:

        void exchange(string & s , int start , int end) {
            for(int i = start ; i <= (end + start) /2; ++i) {
                auto tmp = s[i];
                s[i] = s[end + start - i];
                s[end +start -i] = tmp;
            }
        }

        void reverseWords(string &s) {
            const char blank_char = '$';
            if(s == "") return;
            std::reverse(s.begin() , s.end());
            // trim the string.
            int first_non_blank_char= -1, last_non_blank_char= 0 , non_blank_flag = 0;
            for(int i =0; i < s.length() ; ++i) {
                if(s[i] !=blank_char) {
                    non_blank_flag = 1;
                    if(first_non_blank_char == -1) {
                        first_non_blank_char= i;
                    }
                    last_non_blank_char = i;
                }
                if(i > 0 && s[i] == blank_char && s[i-1] == blank_char ) {
                    s.erase(i-1,1);
                    --i;
                }
            }
            if(non_blank_flag ==0) {
                s.erase(0, s.length());
                return;
            }else {
                s.erase(0, first_non_blank_char);
                s.erase(last_non_blank_char - first_non_blank_char + 1 , s.length() - last_non_blank_char - first_non_blank_char + 1);
            }

            if(s.length() == 0) return;
            // reverse word in this string..
            int w_s = 0 , w_e = 0;
            int word_start_flag = 0;
            for(int i = 0 ; i< s.size() ; ++i) {
                if(s[i] != blank_char && word_start_flag == 0 ) {
                    w_s = i;
                    word_start_flag = 1;
                } else {
                    if(s[i] == blank_char && word_start_flag == 1) {
                        w_e = i - 1;
                        word_start_flag = 0;
                        exchange(s , w_s , w_e);
                    } else if( i == s.size() -  1 && word_start_flag == 1) {
                        w_e = i;
                        word_start_flag = 0;
                        exchange(s , w_s , w_e);
                    }
                }
            }
        };
};

int main()
{
    string _s = "$$$$$$a$$$$b$";
    cout<<_s<<endl;
    Solution s ;
    s.reverseWords(_s);
    cout<<_s<<endl;
    return 0;
}
