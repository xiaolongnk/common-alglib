class Solution(object):
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        currentVal = 0
        ltTmp = ""
        ltMap = []
        return self.travelRoot(root , currentVal , sum , ltTmp , ltMap)

    def travelRoot(self , root , currentVal , tSum , ltTmp , ltMap):
        if root == None:
            return []
        if root != None and root.left == None and root.right == None:
            if currentVal + root.val == tSum:
                ltTmp = ltTmp+" "+str(root.val)
                ll = ltTmp.strip().split(" ")
                ltMap.append([int(i) for i in ll])
                return ltMap
        ltTmp = ltTmp+" "+str(root.val)
        l1 = self.travelRoot(root.left , currentVal + root.val , tSum ,
                ltTmp , ltMap )
        l2 = self.travelRoot(root.right, currentVal + root.val , tSum ,
                ltTmp , ltMap )
        if l1: return l1
        if l2: return l2


def run():
    from common import CommonUtil
    root = None
    root = CommonUtil.generateTree(root)
    CommonUtil.printTree(root , 0)
    ns = Solution()
    ret = ns.pathSum(root , 17)
    print ret
