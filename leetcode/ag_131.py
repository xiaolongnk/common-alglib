class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        def dfs(s, cur, result):
            if not s:
                result.append(cur)
                return
            for x in range(1, len(s) + 1):
                if s[:x] == s[:x][::-1]:
                    dfs(s[x:], cur + [s[:x]], result)

        cur , result = [], []
        dfs(s, cur, result)
        return result

def run():
    t = "abc"
    s = Solution()
    ans = s.partition(t)
    print ans
    pass
