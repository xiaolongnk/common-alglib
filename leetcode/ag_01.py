#!/bin/python2.7

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        ans = None
        for k,v in enumerate(nums):
            for k1,v1 in enumerate(nums[k+1:]):
                if v + v1 == target:
                    ans = k,k1+k+1
        return ans


def run():
     test = [13,  11, 7, 15 ,2]
     target = 9
     s = Solution()
     print s.twoSum(test , target)
