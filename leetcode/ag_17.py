class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        mp = {
                '2': 'abc',
                '3': 'def',
                '4': 'hij',
                '5': 'klm',
                '6': 'nop',
                '7': 'qrs',
                '8': 'tuv',
                '9': 'wxyz'
            };
        ret = ['']
        for i in digits:
            tmp = []
            for j in ret:
                for c in mp[i]:
                    tmp.append(j + c)
            ret = tmp
        return ret

def run():
    s = Solution()
    ans = s.letterCombinations('2322')
    for i in ans:
        print i
    pass

