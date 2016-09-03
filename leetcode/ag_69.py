class Solution(object):

    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x <= 1: 
            return x
        l = 0
        r = x
        abss = 0.01
        while True:
            mid = float(l + r ) / 2
#            print "%d %d",(l ,r)
            vmid = mid * mid
            if abs(vmid - x) < abss:
                break
            if mid * mid > x:
                r = mid
            else:
                l = mid
        return int(mid)

def run():
    ns = Solution()
    print ns.mySqrt(33)
