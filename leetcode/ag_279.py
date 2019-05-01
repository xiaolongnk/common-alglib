class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        ac = []
        j = 1
        while j * j <= n:
            ac.append(j * j)
            j += 1
        j = 1
        lst = {n}
        lvl = 0
        while lst:
            lvl += 1
            current_set = set()
            for fst in lst:
                for v in ac:
                    if fst == v:
                        return lvl
                    if fst < v:
                        break
                    current_set.add(fst - v)
            lst = current_set
        return lvl

def run():
    s = Solution()
    print s.numSquares(12)
