# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        dm = cur = ListNode(-1)
        dm.next = head
        while cur.next and cur.next.next:
            p1, p2 = cur.next, cur.next.next
            cur.next, p1.next , p2.next = p2, p2.next, p1
            cur = cur.next.next
        return dm.next



def print_link_list(head):
    while head:
        print str(head.val) + " ",
        head = head.next
    print ""

def run():
    head = None
    current = None
    for i in xrange(1):
        hd = ListNode(i)
        if head == None:
            head = hd
            current = hd
        else:
            current.next = hd
            current = current.next
    s = Solution()
    print_link_list(head)
    ans = s.swapPairs(head)
    print_link_list(ans)




