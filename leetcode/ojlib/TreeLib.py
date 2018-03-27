# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def make_tree():
    root = TreeNode(1)
    p1 = TreeNode(2)
    p2 = TreeNode(3)
    root.right = p1
    p1.left = p2
    return root

def print_tree(root):

    def pretty_print(root, depth):
        if not root:
            return
        pretty_print(root.left, depth+2)
        for i in xrange(depth):
            print " ",
        print "%s"%root.val
        pretty_print(root.right, depth+2)
    pretty_print(root, 0)

