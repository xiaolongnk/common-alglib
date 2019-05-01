# Definition for singly-linked list.
import pdb
from heapq import heappush, heappop, heapreplace, heapify
from common import CommonUtil

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None:
            return l2
        if l2 == None:
            return l1
        if l1.val < l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1, l2.next)
            return l2

def run():
    l1 = ListNode(1)
    l2 = ListNode(3)
    r1 = ListNode(2)
    r2 = ListNode(4)
    l1.next = l2
    r1.next = r2
    s = Solution()
    res = s.mergeTwoLists(l1, r1)
    CommonUtil.printList(res)
