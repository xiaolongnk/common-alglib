import copy
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        ret = []
        pos = []
        mlen = len(nums)
        nums.sort()

        def find_all_permute(start):
            if start == mlen:
                ret.append(copy.deepcopy(ans))
                return
            for i in range(0,mlen):
                if (i not in pos) and (i == 0 
                        or nums[i] != nums[i-1] or (i-1 in pos)):
                    pos.append(i)
                    ans.append(nums[i])
                    find_all_permute(start + 1)
                    pos.pop()
                    ans.pop()
        find_all_permute(0)
        return ret
       

def run():
    so = Solution()
    print so.permuteUnique([1,2,2,1])

