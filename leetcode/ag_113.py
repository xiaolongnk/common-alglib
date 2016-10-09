import copy
class Solution(object):
    def pathSum(self, root, mSum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        ltMap = []
        def travelRoot(root , currentVal , ltTmp):
            if root == None:
                return
            if root.left == None and root.right == None and root.val + currentVal == mSum:
                ltTmp.append(root.val)
                ltMap.append(copy.deepcopy(ltTmp))
                return
            travelRoot(root.left , currentVal + root.val , ltTmp + [root.val])
            travelRoot(root.right, currentVal + root.val , ltTmp + [root.val])
        
        travelRoot(root , 0 , [])
        return ltMap


def run():
    from common import CommonUtil
    root = None
    root = CommonUtil.generateTree(root)
    CommonUtil.printTree(root , 0)
    ns = Solution()
    ret = ns.pathSum(root , 17)
    print ret
