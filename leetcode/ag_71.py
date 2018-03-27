class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        pt = path.split('/')
        stk = []
        for i in pt:
            if i == '.' or i == '':
                continue
            elif i == '..':
                if stk: stk.pop()
            else:
                stk.append(i)
        return '/' + '/'.join(stk)


       
def run():
    s = Solution()
    path = "/a/b/./c/../../../d/"
    print s.simplifyPath(path)
