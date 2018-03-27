from ojlib.TreeLib import *

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []

        def slu(root, level, ans):
            if not root: return []
            if level < len(ans):
                ans[level].append(root.val)
            else:
                ans.append([root.val])
            slu(root.left, level+1, ans)
            slu(root.right, level+1, ans)
        ans = []
        slu(root, 0 , ans)
        return ans


def run():
    s = Solution()
    root = make_tree()
    ans = s.levelOrder(root)
    for i in ans:
        print i
