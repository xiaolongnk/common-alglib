from ojlib.TreeLib import *
from ojlib.LinkListLib import *

class Solution(object):
    def sortedListToBSTold(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        if not head: return None
        if not head.next: return TreeNode(head.val)
        slow , fast = head, head.next.next
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        cur = slow.next
        slow.next = None
        root  = TreeNode(cur.val)
        left  = self.sortedListToBST(head)
        right = self.sortedListToBST(cur.next)
        root.left = left
        root.right = right
        return root

    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        def solve(head, start, end):
            if start > end: return None
            mid = (start + end) >> 1
            left = solve(head, start, mid - 1)
            root = TreeNode(head[0].val)
            root.left = left
            head[0] = head[0].next
            root.right = solve(head, mid + 1, end) 
            return root
        cp = head
        cnt = 0
        while cp:
            cp = cp.next
            cnt += 1
        return solve([head], 0, cnt - 1)

       
def run():
    head = get_link_list(10)
    print_link_list(head)
    s = Solution()
    root = s.sortedListToBST(head)
    print_tree(root)
    pass
