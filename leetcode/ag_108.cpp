#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    private:
        int length = 60;
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            uint arr_size = nums.size();
            if(arr_size == 0) return NULL;
            uint mid = arr_size/2;
            TreeNode * root = new TreeNode(nums[mid]);
            vector<int> left ,right;
            for(uint i = 0 ; i < mid ; ++i ) left.push_back(nums[i]);
            for(uint i = mid+1; i< arr_size ; ++i) right.push_back(nums[i]);
            TreeNode *lnode = sortedArrayToBST(left);
            TreeNode *rnode = sortedArrayToBST(right);
            root->left  = lnode;
            root->right = rnode;
            return root;
        }

        int depth(TreeNode * root) {
            if(root) {
                return max(depth(root->left) , depth(root->right))  + 1;
            }
            return 0;
        }

        void printTree(TreeNode *root , uint width , uint offset) {
            if(root) {
                printTree(root->left , width + offset, offset);
                for(int i = 0 ; i < width ; ++i ) cout<<" ";
                cout<<root->val;
                char  s[100] ;
                sprintf(s ,"%d",root->val);
                string ss = string(s);
                for(int i = 0 ; i < this->length - width - ss.length() ; ++i ) cout<<"-";
                cout<<"\n"<<endl;
                printTree(root->right , width + offset , offset);
            }
        }
};

int main()
{
    vector< int > test_case({1,2,3,4,5,6,7,8,9,100,101,102,103,105});
    Solution s ;
    TreeNode * root = s.sortedArrayToBST(test_case);
    s.printTree(root , 0 , 5);
    return 0;
}
