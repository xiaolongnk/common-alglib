class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        mlen = len(nums)
        if mlen == 0: return []
        if mlen == 1: return [str(nums[0])]
    
        ans = []
        tmpList = []
        for i in range(0,mlen-1):
            if nums[i+1] != nums[i] + 1:
                tmpList.append(str(nums[i]))
                ans.append("->".join(tmpList))
                tmpList = []
            elif len(tmpList) == 0:
                tmpList.append(str(nums[i]))
            else:
                pass

        if nums[mlen - 1] == nums[mlen-2] + 1:
            tmpList.append(str(nums[mlen-1]))
            ans.append("->".join(tmpList))
        else:
            ans.append(str(nums[mlen-1]))
        return ans


def run():
    so = Solution()
    print so.summaryRanges([0,2,7,91])
    pass
