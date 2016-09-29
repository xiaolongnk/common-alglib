class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        tail = []
        for i in range(0,len(nums)):
            tail.append(0)
        size = 0
        for x in nums:
            l = 0
            r = size
            while l < r:
                m = (l + r) >> 1
                if tail[m] < x :
                    l = m + 1
                else:
                    r = m
            tail[l] = x
            if l == size : 
                size += 1
        return size
       

def run():
    so = Solution()
    print so.lengthOfLIS([10, 9, 2, 5, 3, 7, 101, 18])
