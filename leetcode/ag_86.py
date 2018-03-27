from ojlib.LinkListLib import *
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left, pl, right, pr = None, None, None, None
        while head:
            if head.val >= x:
                if right == None:
                    right ,pr = head , head
                else:
                    pr.next = head
                    pr = pr.next
            else:
                if left == None:
                    left , pl = head, head
                else:
                    pl.next = head
                    pl =  pl.next
            head = head.next
        if pr: pr.next = None
        if pl: pl.next = right
        else: left = right
        return left

def run():
    t = [3,6,1,8,2,22,9]
    t = [2,1]
    head = get_link_list(t)
    print_link_list(head)
    s = Solution()
    ans = s.partition(head, 2)
    print_link_list(ans)
