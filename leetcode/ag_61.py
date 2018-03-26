# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        : if k >> lenght:
            then you would better count the lenght of the link list.
            or you may cost too much time
        """
        if not head or not head.next:
            return head
        fast, slow = head, head
        cnt = 0
        length = 0
        while cnt < k:
            if fast.next:
                fast = fast.next
            else:
                fast = head
                length = cnt + 1
                k %= length
                cnt = -1
            cnt += 1

        while fast.next:
            fast = fast.next
            slow = slow.next
        
        fast.next = head
        head = slow.next
        slow.next = None
        return head
       
