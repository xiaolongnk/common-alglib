class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        acc = 0
        for i in nums:
            acc ^= i
        s = len(bin(acc))- 3
        a,b = 0,0
        for i in  nums:
            if i >> s & 1:
                a ^= i
            else:
                b ^= i
        return a,b

def run():
    s = Solution()
    print s.singleNumber([1,2,2,1,5,3])


