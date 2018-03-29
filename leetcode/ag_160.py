# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB: return None
        pa , pb = headA, headB
        while pa is not pb:
            pa = headB if not pa else pa.next
            pb = headA if not pb else pb.next
        return pa
        

def run():
    pass
