#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> sol;
        if (num.empty()) {
            return sol;
        }
        helper(sol, "", num, target, 0, 0, 0);
        return sol;
    }
    void helper(vector<string>& sol, string path, string num, int target, int pos, long eval, long multed) {
        if (pos == num.length()) {
            if (target == eval) {
                sol.push_back(path);
            }
            return;
        }
        for (int i = pos; i < num.length(); i++) {
            if (i != pos && num[pos] == '0') {
                break;
            }
            string curString = num.substr(pos, i - pos + 1);
            auto cur = stol(curString);
            if (pos == 0) {
                helper(sol, path + curString, num, target, i + 1, cur, cur);
            } else {
                helper(sol, path + "+" + curString, num, target, i + 1, eval + cur, cur);
                 
                helper(sol, path + "-" + curString, num, target, i + 1, eval - cur, -cur);
                 
                helper(sol, path + "*" + curString, num, target, i + 1, eval - multed + multed * cur, multed * cur);
            }
        }
    }
};

int main()
{

}
