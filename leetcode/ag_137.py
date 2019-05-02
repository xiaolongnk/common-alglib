class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        b = 0
        for c in nums:
            t = (a&~b&~c) | (~a&b&c)
            b = (~a&b&~c) | (~a&~b&c)
            a = t
        return a|b

    def singleNumber1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        b = 0
        for c in nums:
            a, b = (a&~b&~c)|(~a&b&c), (~a&b&~c)|(~a&~b&c)
        return a|b
def run():
    s = Solution()
    print s.singleNumber([1,2,2,2,-1,-1,-1])
