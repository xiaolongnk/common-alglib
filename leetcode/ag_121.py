class Solution(object):

    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if len(prices) == 0:
            return 0
        bought_price = prices[0]
        max_benefit = 0
        for i in prices:
            cnp = i - bought_price
            if cnp < 0:
                bought_price = i
            elif cnp > max_benefit:
                max_benefit = cnp
        return max_benefit
       
def run():
    sol = Solution()
    tst = [7, 1, 5, 3, 6, 4]
    ans = sol.maxProfit(tst)
    print ans
    pass
