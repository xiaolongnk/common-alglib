class Solution(object):


    def cp(self, s1, s2):
        cnt = 0
        while cnt < len(s1) and cnt < len(s2):
            if s1[cnt] == s2[cnt]:
                cnt += 1
            else:
                break
        return s1[:cnt]

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ''
        else:
            return reduce(self.cp, strs)
       
def run():
    s = Solution()
    strs = ['ada','adbc','adbc']
    print s.longestCommonPrefix(strs)

