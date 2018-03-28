class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ret = 0
        for x in nums:
            ret ^= x
        return ret
       
def run():
    t = [1,2,1]
    s = Solution()
    print s.singleNumber(t)
    pass
