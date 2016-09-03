class Solution(object):

    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = []
        for i in range(0,len(nums)):
            dp.append(0)
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        if len(nums) == 2: return max(nums[0],nums[1])
        
        dp[0] = nums[0]
        dp[1] = max(nums[0] ,nums[1])
        
        for i in range(2,len(nums)):
            dp[i] = max(dp[i-1] , dp[i-2]+nums[i])
        return dp[len(nums)-1]


def run():
    nums = [2,1,1,2]
    ns = Solution()
    print ns.rob(nums)
