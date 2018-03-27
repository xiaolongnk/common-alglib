# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        prev,cur, front, fp = None, head, head, None
        while front.next:
            front = front.next
            if front.val > x:
                # do this swap job
                pass
        return head

def run():
    pass
