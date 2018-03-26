class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        nums.sort()
        for i in xrange(len(nums) - 2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l < r:
                ret = nums[i] + nums[l] + nums[r]
                if ret < 0:
                    l += 1
                elif ret > 0:
                    r -= 1
                else:
                    ans.append((nums[i], nums[l], nums[r]))
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
        return ans
       
def run():
    s = Solution()
    t = [0,0,0]
    ans = s.threeSum(t)
    for i in ans:
        print i
