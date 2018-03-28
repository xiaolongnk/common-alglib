# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        # duplicate this linklist
        it = head
        while it:
            tmp = RandomListNode(it.label)
            next = it.next
            it.next = tmp
            tmp.next = next
            it = next
        # copy random pointer for copy nodes
        it = head
        while it:
            if it.random:
                it.next.random = it.random.next
            it = it.next.next
        # extract copy link list
        dm = RandomListNode(0)
        prev = dm
        it = head
        while it:
            nxt = it.next.next
            prev.next = it.next
            prev = prev.next
            it.next = nxt
            it = nxt
        return dm.next

def run():
    pass
