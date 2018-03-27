class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class ListKit(object):
    @staticmethod
    def helloworld():
        print "hello world"

def get_link_list(t):
    head = None
    cur = None
    for i in t:
        if head == None:
            head = ListNode(i)
            cur = head
        else:
            cur.next = ListNode(i)
            cur = cur.next
    return head

def print_link_list(head):
    while head:
        print "%s "%(head.val),
        head = head.next
    print ""
