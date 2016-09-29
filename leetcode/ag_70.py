class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0: return 0
        ret = [1,2]
        for i in range(2,n):
            ret.append(ret[i-1] + ret[i-2])
        return ret[n-1]
        
def run():
    so = Solution()
    print so.climbStairs(5)
