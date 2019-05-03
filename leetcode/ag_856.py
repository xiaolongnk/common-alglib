class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        ss = []
        for i in S:
            if i == '(':
                ss.append(-1)
            else:
                cur = 0
                while ss[-1] != -1:
                    cur += ss.pop()
                    print cur,""
                ss.pop()
                if cur == 0:
                    ss.append(1)
                else:
                    ss.append(2 * cur)
        return sum(ss)


def run():
    s = Solution()
    st = "((())(()))()"
    print s.scoreOfParentheses(st)
