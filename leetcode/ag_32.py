class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = [0] * len(s)
        mx = 0
        for i in range(1,len(s)):
            if (s[i] == ')') and (i - l[i-1] -1 >=0) and (s[i-l[i-1]-1] == '('):
                c = i - l[i-1] - 2
                if c >0:
                    l[i] = l[i-1] + 2 + l[c]
                else:
                    l[i] = l[i-1] + 2
                if l[i] > mx:
                    mx = l[i]
        return mx


def run():
    s = Solution()
    j =  ")()())"
    print s.longestValidParentheses(j)
