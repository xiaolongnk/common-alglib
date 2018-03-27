class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        cur = 0
        f = 0
        for i in s:
            if i == ' ': f = 0
            else: 
                if f == 0: f , cur = 1, 1
                else: cur += 1
        return cur

def run():
    s = Solution()
    st = 'hello world toublesome  '
    print s.lengthOfLastWord(st)
    pass
