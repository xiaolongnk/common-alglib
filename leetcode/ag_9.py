class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        p = x;
        n = 0;
        while p > 0:
            n = n * 10 + p % 10
            p /= 10
        return n == x
        

def run():
    s = Solution()
    print s.isPalindrome(12321)
