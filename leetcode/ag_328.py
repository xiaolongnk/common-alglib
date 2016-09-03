# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        tmp = head
        t = None
        t1 = None
        while tmp:
            if tmp.next != None:
                if t == None:
                    t = tmp.next
                    t1 = t
                else:
                    t1.next = tmp.next
                    t1 = t1.next
                tmp.next = tmp.next.next
            if tmp.next == None:
                tmp.next = t
                if t1:
                    t1.next = None
                break
            else:
                tmp = tmp.next
        return head

def buildList(n):
    head = None
    cnt = 1
    while cnt <= n:
        if head == None:
            head = ListNode(cnt)
            tmp = head
        else:
            tmp.next = ListNode(cnt)
            tmp = tmp.next
        cnt+=1
    return head

def printList(head):
    while head != None:
        print head.val,
        head = head.next
    print "\n";

if __name__ == '__main__':
    ns = Solution()
    head = buildList(3)
    printList(head)
    head = ns.oddEvenList(head)
    printList(head)
    pass

                
                


