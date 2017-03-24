#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {

        }

        int depth(TreeNode * root) {
            if(root) {
                return max(depth(root->left) , depth(root->right))  + 1;
            }
            return 0;
        }

        void printTree(TreeNode *root) {
            if(root) {
                printTree(root->left);
                cout<<root->val<<"  ";
                printTree(root->right);
            }
        }

};

int main()
{
    vector< int > test_case = {1,2,3,4,5,6,7,8};

    return 0;
}
