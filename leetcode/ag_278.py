# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        left = 1
        right = n
        while left < right:
            mid = (left + right) / 2;
            ret = isBadVersion(mid)
            if ret == True:
                right = mid
            else:
                left = mid + 1
        return right
