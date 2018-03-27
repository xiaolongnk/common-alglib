class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        maxn = max(i + nums[i], maxn)
        """
        maxn = nums[0] 
        for i in range(len(nums)):
            if i == 0: 
                continue
            if maxn < i:
                return False
            maxn = max(i + nums[i], maxn)
        return True

def run():
    t = [2,3,1,1,3]
    t1 = [3,2,1,0,4]
    s = Solution()
    print s.canJump(t)
