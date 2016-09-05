# Definition for singly-linked list.
class ListNode(object):

    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        mlen = 0
        tmp = head
        while tmp:
            tmp = tmp.next
            mlen+=1
        remove_index = mlen - n
        if remove_index == 0:
            return head.next
        tmp = head
        cnt = 1
        while tmp:
            if cnt == remove_index:
                if tmp.next:
                    tmp.next = tmp.next.next
                else:
                    tmp.next = None
            cnt+=1
            tmp = tmp.next
        return head

def buildList():
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    return head

def printList(head):
    flag = 0
    while head:
        if flag == 1:
            print str(head.val),
        else:
            flag = 1
            print str(head.val),
        head = head.next
    print "\n";

def run():
    head = buildList()
    ns = Solution()
    head = ns.removeNthFromEnd(head , 1)
    printList(head)
