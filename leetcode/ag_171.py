class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s[::-1]
        cnt = 0
        base = 26
        res = 0
        c = 1;
        for i in s:
            nm = ord(i) - ord('A') + 1
            res += c * nm 
            c *= base
        return res


def run():
    s = Solution()
    t = "AB"
    res = s.titleToNumber(t)
    print res,""
