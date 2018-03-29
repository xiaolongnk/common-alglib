class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        p1 = version1.split(".")
        p2 = version2.split(".")
        m = len(p1) - len(p2)
        if m < 0:
            for x in xrange(m*-1): p1.append(0)
        elif m > 0:
            for x in xrange(m): p2.append(0)
        cnt = 0
        while cnt < len(p1) and cnt < len(p2):
            if int(p1[cnt]) > int(p2[cnt]) :
                return 1
            elif int(p1[cnt]) < int(p2[cnt]):
                return -1
            cnt += 1
        return 0

def run():
    v1 = '1.1.0'
    v2 = "1"
    s = Solution()
    ret = s.compareVersion(v1, v2)
    print ret
