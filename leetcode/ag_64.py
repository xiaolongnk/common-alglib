import sys

class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        if m == 0: return 0
        n = len(grid[0])
        dp = []
        for t in range(m + 1):
            dp.append([])
            for v in range(n + 1):
                if t == 0 or v == 0:
                    iniv = sys.maxint
                else:
                    iniv = 0
                dp[t].append(iniv)
        dp[1][1] = grid[0][0]

        for t in range(m + 1):
            for v in range(n + 1):
                if t > 0 and v > 0:
                    if t ==1 and v == 1:
                        continue
                    dp[t][v] = min(dp[t-1][v], dp[t][v-1]) + grid[t-1][v-1]
        return dp[m][n]

       
def run():
    s = Solution()
    grid = [[1,3,1], [1,5,1], [4,2,1]]
    print s.minPathSum(grid)
