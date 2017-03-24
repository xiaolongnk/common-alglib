/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <stdio.h>
#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int minDepth(TreeNode* root) {
            if(root) {
                int left_depth = minDepth(root->left);
                int right_depth = minDepth(root->right);
                if(right_depth == 0) return left_depth + 1;
                if(left_depth == 0) return right_depth + 1;
                return min(left_depth , right_depth) + 1;
            }
            return 0;
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

void buildTree(TreeNode * &root)
{
    root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(1);
}

int main()
{
    TreeNode * root;
    buildTree(root);
    Solution s;
    s.printTree(root);
    int depth = s.depth(root);
    cout<<"depth of the tree is "<<depth<<endl;
    int min_depth = s.minDepth(root);
    cout<<"min depth of the tree is "<<min_depth<<endl;
    return 0;
}
