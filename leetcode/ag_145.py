# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        q = [root]
        ans=[]
        while q:
            top = q.pop()
            if top:
                ans.append(top.val)
                q.append(top.left)
                q.append(top.right)
        ans.reverse()
        return ans

from ojlib.TreeLib import *
from ojlib.LinkListLib import *

def run():
    root = make_tree()
    s = Solution()
    print s.postorderTraversal(root)

