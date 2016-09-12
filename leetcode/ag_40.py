class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        candidates.sort()
        mlen = len(candidates)       
        def cacu(start , curval , tmpList):
            if curval > target:
                return
            if curval == target:
                if tmpList not in ans:
                    ans.append(tmpList)
                return

            for i in range(start , mlen):
                cacu(i+1 , curval + candidates[i] ,
                        tmpList + [candidates[i]])
        cacu(0 , 0 , [])
        return ans


def run():
    so = Solution()
    print so.combinationSum2([10, 1, 2, 7, 6, 1, 5] , 8)
    pass
