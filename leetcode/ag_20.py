class Solution(object):

    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        mp ={'{':'}','(':')','[':']'}
        stack = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                stack.append(i)
            elif i == ')' or i == ']' or i == '}':
                if len(stack) == 0:
                    return False
                top = stack.pop()
                if mp[top] != i:
                    return False
        if len(stack):
            return False
        return True
       
def run():
    s = ")"
    t = Solution()
    print t.isValid(s)
