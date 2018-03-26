class Solution(object):

    def dfs(self, left, right, s, ans):
        if left > right:
            return
        if not left and not right:
            ans.append(s)
            return
        if left:
            self.dfs(left - 1, right, s + "(", ans)
        if right:
            self.dfs(left, right - 1, s + ")", ans)

    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        left , right , ans = n, n, []
        self.dfs(left, right, "", ans)
        return ans
        
def run():
    s = Solution()
    ans = s.generateParenthesis(3)
    for i in  ans:
        print i
