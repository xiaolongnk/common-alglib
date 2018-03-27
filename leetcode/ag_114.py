from ojlib.TreeLib import *

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        def solve(root, pre):
            if not root: return pre
            pre = solve(root.right, pre)
            pre = solve(root.left, pre)
            root.right = pre
            root.left = None
            pre = root
            return pre
        solve(root, None)
        
       

def run():
    root = make_tree()
    s = Solution()
    s.flatten(root)
    print_tree(root)
