import copy
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        ret = []
        mlen = len(nums)

        def find_all_permute(ans , ret):
            if len(ans) == mlen:
                ret.append(copy.deepcopy(ans))
                return
            for x in nums:
                if x not in ans:
                    ans.append(x)
                    find_all_permute(ans , ret)
                    ans.pop()
        find_all_permute(ans , ret)
        return ret
       

def run():
    so = Solution()
    print so.permute([1,2,3])

