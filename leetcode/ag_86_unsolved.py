from ojlib.LinkListLib import ListNode
from ojlib.LinkListLib import ListKit


class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        left = ListNode(0)
        right = ListNode(0)
        while head:
            if head.val >= x:
                right.next, right = head, right.next
            else:
                left.next, left = head, left.next
            head = head.next
        left.next = right.next
        return left.next

def run():
    t = [3,6,1,8,2,22,9]
    head = ListKit.get_link_list(t)
    ListKit.print_link_list(head)

