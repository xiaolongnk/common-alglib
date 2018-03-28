class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        ln = len(triangle)
        for x in xrange(ln - 1):
            idx = ln - x - 2
            for k, v in enumerate(triangle[idx]):
                triangle[idx][k] = min(triangle[idx+1][k], triangle[idx+1][k+1]) + v

        return triangle[0][0]

def run():
    t = [ [2], [3,4], [6,5,7], [4,1,8,3] ]
    s = Solution()
    print s.minimumTotal(t)

