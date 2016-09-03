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
        return self.pickNode(root)[0]

    def pickNode(self , root):
        if not root:
            return 0,0
        robL , noRobL = self.pickNode(root.left)
        robR , noRobR = self.pickNode(root.right)
        return max(robL + robR , root.val + noRobL + noRobR) , robL + robR

def run():
    pass

