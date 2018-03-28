from ojlib.TreeLib import *

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        '''
        def solve(root, cur, total):
            if not root: return
            cur.append(root.val)
            if not root.left and not root.right:
                tmp = []
                for i in cur:
                    tmp.append(i)
                total.append(tmp)
                cur.pop()
                return
            solve(root.left, cur, total)
            solve(root.right, cur, total)
        cur , total = [], []
        solve(root, cur, total)
        return total
        '''
        def solve(root, cur, total):
            if not root: return
            cur = cur * 10 + root.val
            if not root.left and not root.right:
                total.append(cur)
                return
            solve(root.left, cur, total)
            solve(root.right, cur, total)
        cur , total = 0, []
        solve(root, cur, total)
        return sum(total)

def run():
    root = make_tree()
    s = Solution()
    print_tree(root)
    ans = s.sumNumbers(root)
    print ans
