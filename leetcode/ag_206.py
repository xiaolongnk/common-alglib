class Solution(object):
    def reverseList(self, head):
	"""
	:type head: ListNode
	:rtype: ListNode
	"""
        pre = None
        nxt = None
        while head:
            nxt = head.next
            head.next = pre
            pre = head
            head = nxt
        head = pre
        return head


def run():
    from common import CommonUtil
    ns = Solution()
    head = None
    head = CommonUtil.generateList( 2 , head)
    CommonUtil.printList(head)
    hed = ns.reverseList(head)

    CommonUtil.printList(hed)
