# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = None
        prev = None
        carry = 0
        while l1 != None or l2 != None or carry :
            t1 = 0
            t2 = 0
            if l1 == None:
                t1 = 0
            else:
                t1 = l1.val
                l1 = l1.next
            if l2 == None: 
                t2 = 0
            else :
                t2 = l2.val
                l2 = l2.next
            tmp = t1 + t2 + carry
            cur = ListNode(0)
            cur.val = tmp % 10
            carry = tmp / 10
            if head == None:
                head = cur
                prev = cur
            else:
                prev.next = cur
                prev = prev.next
        return head

    def printList(self , l):
        while l:
            print l.val,
            l = l.next
        print ""

if __name__ == '__main__':
    l1 = ListNode(3)
    l2 = ListNode(4)
    l1.next = l2

    a1 = ListNode(5)
    a2 = ListNode(6)
    a1.next = a2
    so = Solution()
    so.printList(l1)
    so.printList(a1)
    n1 = so.addTwoNumbers(l1 ,a1)
    so.printList(n1)
    
