class ListNode(object):

    def __init__(self , val):
        self.val = val
        self.next = None


class TreeNode(object):

    def __init__(self , val):
        self.val = val
        self.left = None
        self.right = None

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
    
    @staticmethod
    def generateTree(root):
        root = TreeNode(8)
        root.left = TreeNode(3)
        root.right = TreeNode(5)
        root.left.left = TreeNode(2)
        root.left.right = TreeNode(6)
        root.right.left = TreeNode(4)
        root.right.right = TreeNode(20)
        return root
    @staticmethod
    def printTree(root , depth = 0):
        if root:
            CommonUtil.printTree(root.right , depth+2)
            for i in range(0,depth):
                print " ",
            print root.val,"\n"
            CommonUtil.printTree(root.left , depth+2)

