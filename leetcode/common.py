class ListNode(object):

    def __init__(self , val):
        self.val = val
        self.next = None

class CommonUtil(object):
    @staticmethod
    def printList(head):
        while head != None:
            print head.val,
            head = head.next
        print "\n";

    @staticmethod
    def generateList(n , head):
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

