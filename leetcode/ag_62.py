class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
        """
        dp = []
        for i in range(m + 1):
            dp.append([])
            for j in range(n + 1):
                dp[i].append(0)
        dp[1][1] = 1
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                dp[i+1][j+1] = dp[i + 1][j] + dp[i][j + 1]
        return dp[m][n]


def run():
    s = Solution()
    print s.uniquePaths(3,3)

       

