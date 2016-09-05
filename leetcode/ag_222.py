class Solution(object):

    def countNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root == None:
            return 0
        l = self.leftCount(root)
        r = self.rightCount(root)
        if l == r: return (2<<(l - 1)) - 1
        return 1 + self.countNodes(root.left ) + self.countNodes(root.right)

    def leftCount(self , root):
        cnt = 0
        while root:
            cnt+=1
            root = root.left
        return cnt
    
    def rightCount(self , root):
        cnt = 0
        while root:
            cnt+=1
            root = root.right
        return cnt
        
        
def run():
    ns = Solution()
    from common import CommonUtil
    root = None
    root = CommonUtil.generateTree(root)
    CommonUtil.printTree(root)
    print ns.countNodes(root)
