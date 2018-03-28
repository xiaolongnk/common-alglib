
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        stack = [root]
        ans = []
        while stack:
            top = stack.pop()
            if top:
                ans.append(top.val)
                stack.append(top.left)
                stack.append(top.right)
        return ans
       
from ojlib.LinkListLib import *
from ojlib.TreeLib import *

def run():
    root = make_tree()
    s = Solution()
    print s.preorderTraversal(root)
