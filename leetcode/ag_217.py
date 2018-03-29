class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        if not nums or k <=0: return False
        ln = len(nums)
        for x in xrange(ln):
            for i in range(x+1, ln):
                if nums[i] == nums[x]:
                    if i - x <= k:
                        return True
        return False
        """
        if not nums or k <= 0: return False
        mp= {}
        for idx, v in enumerate(nums):
            if v in  mp and idx - mp[v] <= k:
                return True
            mp[v] = idx
        return False
        
def run():
    t = [-1,-1]
    s= Solution()
    print s.containsNearbyDuplicate(t, 1)
    pass
