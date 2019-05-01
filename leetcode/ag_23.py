# Definition for singly-linked list.
import pdb
from common import CommonUtil

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        from heapq import heapify, heappop, heapreplace
        h = [(n.val, n) for n in lists if n]
        heapify(h)
        dn = it = ListNode(0)
        while h:
            (k, n) = h[0]
            if n.next == None:
                heappop(h)
            else:
                heapreplace(h, (n.next.val, n.next))
            it.next = n
            it = it.next
        return dn.next


def run():
    l1 = ListNode(1)
    l2 = ListNode(3)
    r1 = ListNode(2)
    r2 = ListNode(4)
    l1.next = l2
    r1.next = r2
    s = Solution()
    ss = [l1, r1]
    res = s.mergeKLists(ss)
    CommonUtil.printList(res)
