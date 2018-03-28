# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fast , slow = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                s1 = head
                while s1 and slow:
                    if s1 == slow:
                        return slow
                    s1, slow = s1.next, slow.next
                return True
        return None

def run():
    
    pass
