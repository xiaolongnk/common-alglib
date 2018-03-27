class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
            g(n) = f(1,n) + f(2,n) + f(3,n) ... + f(n,n)
            f(i,n) = g(i-1) * g(n-i)
            g(n) = g(0)*g(n-1) + g(1) * g(n-2) + ... + g(n-1)*g(0)
            g(0) = 1
            g(1) = 1
            g(2) = g(0)*g(1) + g(1)*g(0)
        """
        g = []
        for x in xrange(n + 1):
            if x <= 1:
                g.append(1)
            else:
                cur = 0
                for w in xrange(x):
                    cur += g[w]*g[x-w-1]
                g.append(cur)
        return g[n]

       

def run():
    s = Solution()
    print s.numTrees(3)
