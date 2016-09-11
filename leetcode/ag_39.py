class Solution(object):

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates = list(set(candidates))
        candidates.sort()
        mlen = len(candidates)
        ans = []
        pathList = []
        def cacu(start , curval , pathList):
            if curval > target:
                return
            if curval == target:
                ans.append(pathList)
            for x in range(start , mlen):
                cacu(x , curval + candidates[x] , pathList + [candidates[x]])
        cacu(0 , 0 , pathList)
        return ans




def run():
    so = Solution()
    ww = so.combinationSum([2,3,6,7] ,7)
    print ww
