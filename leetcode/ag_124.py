from ojlib.TreeLib import *

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        def solve(root):
            l,r = 0,0
            ls,rs = None,None
            if root.left:
                l,ls = solve(root.left)
                l = max(l, 0)
            if root.right:
                r,rs = solve(root.right)
                r = max(r, 0)
            return root.val + max(l,r), max(root.val +l +r,ls,rs)

        return solve(root)[1]

def run():
    root = make_tree()
    s = Solution()
    s.maxPathSum(root)

