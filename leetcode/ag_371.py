class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        ans = a
        while b != 0:
            ans = a ^ b
            b = (a & b) << 1
            a = ans
        return ans

def run():
    so = Solution()
    print so.getSum(-1,1)
