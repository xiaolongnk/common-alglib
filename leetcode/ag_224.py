class Solution(object):

    def cal(self , ss):
        if len(ss) == 0:
            return 0
        ans = ss[0]
        cnt = 1
        while cnt < len(ss):
            try:
                if ss[cnt] =='+':
                    ans = ans + int(ss[cnt+1])
                elif ss[cnt] == '-':
                    ans = ans - int(ss[cnt+1])
                cnt += 2
            except:
                pass
        return ans

    def calculate(self, s):
        lt = []
        t_token = ''
        for i in s:
            if i ==' ':
                continue
            if i >= '0' and i <='9':
                t_token += i
            else:
                if(t_token != ''):
                    num = int(t_token)
                    lt.append(num)
                    t_token = ''
                if i == ')':
                    sss = []
                    while True:
                        top = lt.pop()
                        if top == '(':
                            break
                        sss.append(top)
                    sss.reverse()
                    curval = self.cal(sss)
                    lt.append(curval)
                else :
                    lt.append(i)
        if t_token != '':
            lt.append(int(t_token))
        return self.cal(lt)

def run():
    s = "1123 - 100 - (12 - 3 - (3 + 5)) + (1 +2) "
    ns = Solution()
    print ns.calculate(s)
