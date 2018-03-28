class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not ( head and head.next and head.next.next):
            return False
        fast , slow = head, head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

