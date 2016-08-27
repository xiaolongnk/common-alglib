class Solution(object):

    def swipeHighLevelOp(self , ss):
        lt = []
        cnt = 0
        while cnt < len(ss):
            if str(ss[cnt]) == "*":
                tmp = lt.pop() * ss[cnt+1]
                cnt+=2
                lt.append(tmp)
            elif str(ss[cnt]) == "/":
                tmp = lt.pop() / ss[cnt+1]
                cnt+=2
                lt.append(tmp)
            else:
                lt.append(ss[cnt])
                cnt+=1
        return self.cal(lt)

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
                lt.append(i)
        if t_token != '':
            lt.append(int(t_token))
        return self.swipeHighLevelOp(lt)

if __name__ == '__main__':
    s = "123*2-3+3 *2/3"
    ns = Solution()
    print ns.calculate(s)
