#!/bin/python

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def printList(self , l1):
        tmp = l1
        while(tmp != None):
            print tmp.val,
            tmp = tmp.next

    def reverseList(self , l1):
        pre = None
        head = l1
        nxt = None

        while head != None:
            next = head.next
            head.next = pre
            pre = head
            head = next
        return pre


    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        tmp_l1 = l1
        tmp_l2 = l2
        n_head = ListNode(0)
        n_tmp  = n_head
        register = 0
        while tmp_l1 or tmp_l2 or register:
            cur_ans = 0
            if tmp_l1 :
                cur_ans += tmp_l1.val
                tmp_l1 = tmp_l1.next
            if tmp_l2 :
                cur_ans += tmp_l2.val
                tmp_l2 = tmp_l2.next
            cur_ans += register
            register = cur_ans / 10
            cur_ans = cur_ans % 10
            n_tmp.val = cur_ans
            if tmp_l1 == None and tmp_l2 == None and register == 0:
                break;
            n_tmp.next = ListNode(0)
            n_tmp = n_tmp.next
        return n_head

    def gen_link_list(self , flag):
        if flag == 1:
            a = [2,4,3]
        else:
            a = [5,6,4]
        cnt = 0
        head = ListNode(0)
        cur = head
        while cnt < len(a):
            cur.val = a[cnt]
            if cnt == len(a) - 1:
                break;
            cur.next = ListNode(0)
            cur = cur.next
            cnt = cnt + 1
        return head


if __name__ == '__main__':
    Sol = Solution()
    l1 = Sol.gen_link_list(1)
    l2 = Sol.gen_link_list(2)
    n3 = Sol.addTwoNumbers(l1,l2)
    Sol.printList(n3)
