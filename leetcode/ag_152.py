class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ln = len(nums)
        if ln < 1: return 0
        f, g = [], []
        for x in xrange(ln):
            f.append(0)
            g.append(0)
        ans = 0
        f[0] , g[0] = nums[0]
        for x in xrange(1,ln):
            f[x] = max(max(f[i-1] * nums[x], g[i-1] * nums[x]), nums[x])
            g[x] = min(min(f[i-1] * nums[x], g[i-1] * nums[x]), nums[x])
            ans = max(ans, f[x])
        return ans
        
def run():
    pass
