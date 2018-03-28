class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        def is_number(s):
            try:
                float(s)
                return True
            except ValueError:
                return False

        stk = []
        for tk in tokens:
            if is_number(tk):
                stk.append(int(tk))
            elif tk in ['+','-','*','/']:
                p1, p2, ans = 0,0,0
                if stk: p2 = stk.pop()
                if stk: p1 = stk.pop()
                if tk == '+': ans = p1 + p2
                elif tk == '-': ans = p1 - p2
                elif tk == '*': ans = p1 * p2
                elif tk == '/': ans = int(float(p1) / p2)
                print "%s%s%s=%s"%(p1,tk,p2,ans)
                stk.append(ans)
            else:
                return -1
        if stk: return stk.pop()
        return -1

def run():
    ptr = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    s = Solution()
    ans = s.evalRPN(ptr)
    print ans
