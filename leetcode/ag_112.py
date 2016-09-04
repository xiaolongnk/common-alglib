# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        currentVal = 0
        return self.travelRoot(root , currentVal , sum)

    def travelRoot(self , root , currentVal , tSum):
        if root == None:
            return False
        if root != None and root.left == None and root.right == None:
            if currentVal + root.val == tSum:
                return True

        l1 = self.travelRoot(root.left , currentVal + root.val , tSum)
        l2 = self.travelRoot(root.right, currentVal + root.val , tSum)
        return l1 or l2


def run():
    from common import CommonUtil
    root = None
    root = CommonUtil.generateTree(root)
    CommonUtil.printTree(root , 0)
    ns = Solution()
    ret = ns.hasPathSum(root , 17)
    print ret
