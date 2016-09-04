class Solution(object):

    def binaryTreePaths(self, root):
        path = ""
        ltMap = []
        return self.travelRoot(root , path , ltMap)

    def travelRoot(self , root , path , ltMap):
        if root == None:
            return []
        if root != None and root.left == None and root.right == None:
            if path == '': path = str(root.val)
            else: path = path+"->"+str(root.val)
            ltMap.append(path)
            return ltMap
        if path == '': nextPath = str(root.val)
        else: nextPath = path + "->" + str(root.val)
        l1 = self.travelRoot(root.left , nextPath , ltMap)
        l2 = self.travelRoot(root.right, nextPath , ltMap)
        if l1: return l1
        if l2: return l2
        return []


def run():
    from common import CommonUtil
    root = None
    root = CommonUtil.generateTree(root)
    CommonUtil.printTree(root , 0)
    ns = Solution()
    ret = ns.binaryTreePaths(root)
    print ret
