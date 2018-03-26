class Solution(object):
    
    def fourSumBest(self, nums, target):

        def search_sub_sum(nums, n, target, current_result, results):
            if len(nums) < n or n < 2 or n * nums[0] > target or n * nums[-1] < target:
                return
            elif n == 2:
                # solve two sum problems.
                l = 0
                r = len(nums) -1
                while l < r:
                    w = nums[l] + nums[r]
                    if w == target:
                        results.append(current_result + [nums[l], nums[r]])
                        l += 1
                        while l < r and nums[l] == nums[l-1]:
                            l += 1
                    elif w > target:
                        r -= 1
                    else:
                        l += 1
            else:
                for x in range(len(nums) - n + 1):
                    if x == 0 or (x > 0 and nums[x] != nums[x - 1]):
                        search_sub_sum(nums[x +1:], n -1, target - nums[x], current_result + [nums[x]], results)
        
        results = []
        nums.sort()
        search_sub_sum(nums, 4, target, [], results)
        return results


    def threeSum(self, nums, target):
        ans = []
        llen = len(nums)
        for i in xrange(llen -2):
            l = i + 1
            r = llen - 1
            t = target - nums[i]
            if i == 0 or nums[i] != nums[i-1]:
                while l < r:
                    s = nums[l] + nums[r]
                    if s == t:
                        ans.append([nums[i], nums[l], nums[r]])
                        while l < r and nums[l] == nums[l + 1]:
                            l += 1
                        while l < r and nums[r] == nums[r - 1]:
                            r -= 1
                        r -= 1
                        l += 1
                    elif s > t:
                        r -= 1
                    else :
                        l += 1
        return ans

    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        nums.sort()
        for x in xrange(len(nums) - 3):
            if x == 0 or nums[x] != nums[x - 1]:
                ret = self.threeSum(nums[x+1:], target - nums[x])
                for i in ret:
                    ans.append([nums[x]] + i)
        return ans

def run():
    t = [1,0,-1,0,-2,2]
    s = Solution()
    ans = s.fourSumBest(t, 0);
    for i in ans:
        print i

    pass
