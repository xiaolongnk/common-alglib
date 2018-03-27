from ojlib.TreeLib import *

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        lst = []
        def trv(root, lst):
            if not root:
                return
            trv(root.left, lst)
            lst.append(root.val)
            trv(root.right, lst)
        trv(root, lst)
        return lst

    def stackTraversal(self, root):
        ans , stack, current = [], [], root
        while stack or current:
            if current:
                stack.append(current)
                current = current.left
            else:
                top = stack.pop()
                ans.append(top.val)
                current = top.right
        return ans

def run():
    tree = make_tree()
    s = Solution()
    print s.stackTraversal(tree)
