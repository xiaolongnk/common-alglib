# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        if m == n: return head
        dmNode = ListNode(-1)
        dmNode.next = head
        pre = dmNode
        for i in range(m - 1):
            pre = pre.next

        rev = None
        cur = pre.next
        for i in range(n - m + 1):
            next = cur.next
            cur.next = rev
            rev = cur
            cur = next
        pre.next.next = cur
        pre.next = rev
        return dmNode.next
        

