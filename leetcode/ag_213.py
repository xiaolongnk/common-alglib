import copy

class Solution(object):

    def roobbb(self, nums):
        dp = []
        for i in range(0,len(nums)):
            dp.append(0)
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums[0],nums[1])
        last = len(nums)-1
        
        dp[0] = nums[0]
        dp[1] = max(nums[0] ,nums[1])
        
        for i in range(2 , last+1):
            dp[i] = max(dp[i-2]+nums[i] , dp[i-1])
        return dp[last]

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        aa = copy.deepcopy(nums)
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        del nums[0]
        aa.pop()
        a1 = self.roobbb(nums)
        a2 = self.roobbb(aa)
        return max(a1, a2)


def run():
    nums = [2,1,1,2]
    ns = Solution()
    print ns.rob(nums)
