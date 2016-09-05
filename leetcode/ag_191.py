class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        cnt = 0
        while n:
            if n&1 :
                cnt+=1
            n = n>>1
        return cnt

def run():
    ns = Solution()
    print ns.hammingWeight(7)
