class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        used = {}
        start = 0
        mx = 0
        for i,c in enumerate(s):
            if c in used and start <= used[c]:
                start = used[c] + 1
            else:
                mx = max(mx, i - start + 1)
            used[c] = i
        return mx


def run():
    s = Solution()
    params = 'abcabcdbb'
    r = s.lengthOfLongestSubstring(params)
    print r
