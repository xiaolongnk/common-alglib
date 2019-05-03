class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        base = 26
        res = ''
        while n:
            res += chr((n - 1)%base + ord('A'))
            n = int((n - 1)/base)
        return res[::-1]


def run():
    s = Solution()
    print s.convertToTitle(28)

