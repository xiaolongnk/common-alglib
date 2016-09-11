class Solution(object):

    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        startval = 0
        ans = []
        path = []

        def cacu(start , k , n , curval , path ):
            if k == 0 and curval == n:
                path.sort()
                if path not in ans:
                    ans.append(path)
                return
            if k <= 0:
                return

            for i in range(start+ 1,10):
                    cacu(i , k-1 , n , curval + i , path + [i])
            return ans

        ret = cacu(0 , k , n , startval , path)
        return ret




def run():
    so = Solution()
    ww = so.combinationSum3(3,9)
    print ww
