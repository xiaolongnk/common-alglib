import random

class Solution(object):

    def __init__(self, head):
        self.head = head
    
    def getRandom(self):
        tmp = self.head
        cnt = 0
        ans = None
        while tmp:
            if random.randint(0,cnt) == 0:
                ans = tmp
            tmp = tmp.next
            cnt += 1
        return ans.val
       
class ListNode(object):
    
    def __init__(self , val):
        self.val = val
        self.next = None

def genList(head):
    prev = head
    for i in range(0,5):
        tmp = ListNode(i)
        tmp.val = i
        tmp.next = None
        if i == 0:
            head = tmp
            prev = tmp
        else:
            prev.next = tmp
            prev = tmp
    return head

def printList(head):
    tmp = head
    while tmp:
        print tmp.val,
        tmp = tmp.next
    


    pass

if __name__=='__main__':
    head = ListNode(-1)
    nh = genList(head)
    mapp = dict()
    for i in range(0,5):
        mapp[i] = 0
    obj = Solution(nh)

    for i in range(0,100000):
        val = obj.getRandom()
        mapp[val]+=1

    for k in mapp:
        print mapp[k],str(float(mapp[k])/100000 * 100)+"%"


