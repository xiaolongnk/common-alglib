class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        ln = len(prices)
        if ln <= 1: return 0
        if k >= ln/2:
            max_pro = 0
            for x in xrange(1,ln):
                if prices[x] - prices[x-1] > 0:
                    max_pro += prices[x] - prices[x-1]
            return max_pro

        dp = []
        for y in xrange(k+1):
            dp.append([])
            for x in xrange(ln): 
                dp[y].append(0)
        for i in range(1,k+1):
            maxv = dp[i-1][0] - prices[0]
            for t in range(1, ln):
                dp[i][t] = max(dp[i][t-1], maxv + prices[t])
                maxv = max(maxv, dp[i-1][t] - prices[t])
        return dp[k][ln-1]


def run():
    s = Solution()
    t = [3,3,5,0,0,3,1,4]
    p = s.maxProfit(t)
    print p
        
