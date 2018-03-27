from ojlib.TreeLib import *

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        def slu(root, level, ans):
            if not root: return []
            if level >= len(ans):
                ans.insert(0,[])
            slu(root.left, level+1, ans)
            slu(root.right, level+1, ans)
            ans[len(ans) - level - 1].append(root.val)
        ans = []
        slu(root, 0 , ans)
        return ans


def run():
    s = Solution()
    root = make_tree()
    ans = s.levelOrderBottom(root)
    for i in ans:
        print i
