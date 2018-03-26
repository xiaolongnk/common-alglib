class Solution(object):

    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        :dp[k] = nums[k] + (dp[k-1] > 0 ? dp[k-1] : 0)
        """
        ln = len(nums)
        dp = []
        for x in range(ln):
            dp.append(0)
        dp[0] = nums[0]
        mx = -1
        for k, v in enumerate(nums):
            if k == 0: continue
            if dp[k -1] > 0 :
                dp[k] = dp[k -1] + nums[k]
            else:
                dp[k] = nums[k]
            if mx < dp[k]:
                mx = dp[k]
        return mx

def run():
    s = Solution()
    t = [-2,1,-3,4,-1,2,1,-5,4]
    print s.maxSubArray(t)
