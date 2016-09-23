class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num == 0:
            return False
        for x in [2,3,5]:
            while num % x == 0:
                num = num / x
        return num == 1?False:True


def run():
    so = Solution()
    print so.isUgly(932)
