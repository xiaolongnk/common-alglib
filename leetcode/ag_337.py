# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        currentAns = 0
        p = self.printTree(root , currentAns , False)
        np = self.printTree(root , currentAns , True)
        return p > np ? p : np

    def pickNode(root , currentAns  , flag):
        if root:
            return currentAns
        if flag :
            pickNode(root->l , currentAns , False)
            pickNode(root->r , currentAns , False)
        else:
            pickNode(root->l , currentAns + root.val,True)
            pickNode(root->r , currentAns + root.val,True)

def run():
    pass

