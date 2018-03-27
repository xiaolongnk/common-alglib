class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        if obstacleGrid[0][0] == 1:
            return 0
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = []
        for i in range(m+1):
            dp.append([])
            for j in range(n+1):
                dp[i].append(0)
        dp[1][1] = 1
        for k,row in enumerate(dp):
            for j in range(len(row)):
                if (k == 0 or j == 0) or (k == 1 and j == 1):
                    continue
                if obstacleGrid[k-1][j-1] == 0:
                    dp[k][j] = dp[k][j-1] + dp[k-1][j]
                else:
                    dp[k][j] = 0

        return dp[m][n]

       

def run():
    t = [ [0,0,0], [0,1,0], [0,0,0] ]
    s = Solution()
    print s.uniquePathsWithObstacles(t)

