#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>


using namespace std;


class Solution {
private:
    int length;
    int width;
public:
    Solution(int a , int b):length(a),width(b){};

    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin() , matrix.end());
        for(auto i = 0; i < matrix.size()-1; ++i) {
            for(auto j = i + 1 ; j < matrix[i].size(); ++j){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }


    void antirotate(vector<vector<int>>&matrix){
        for(auto &x:matrix) reverse(x.begin() , x.end());
        for(auto i = 0; i < matrix.size()-1; ++i) {
            for(auto j = i + 1 ; j < matrix[i].size(); ++j){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
    }

    void show()
    {
        cout<<"length "<< length <<"width "<<width<<endl;
    }
};

void printMatirx(vector<vector<int>> s)
{
    for(auto i = 0 ; i < s.size() ; ++i){
        for(auto x : s[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    Solution a(1,2);
    vector<int> s1 = {1,2,3};
    vector<int> s2 = {4,5,6};
    vector<int> s3 = {7,8,9};
    vector<vector<int>> ww = {s1 , s2 , s3};
    printMatirx(ww);
    a.rotate(ww);
    printMatirx(ww);
    a.antirotate(ww);
    printMatirx(ww);

    a.show();
    return 0;
}
