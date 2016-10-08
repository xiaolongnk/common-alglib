class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        def madd(s1 , s2 , cnt):
            if s1 == "":
                return s2
            if s2 == "":
                return s1
            app = ""
            for i in range(0,cnt):
                app += "0"
            s2 = s2 + app
            len1 = len(s1)
            len2 = len(s2)
            mm = max(len1 , len2)
            start = 0
            ret = ""
            tmp = 0
            while start < mm :
                idx1 = len1 - start - 1
                idx2 = len2 - start - 1
                if idx1 >=0 and idx2 >=0 :
                    tmp += int(s1[idx1]) + int(s2[idx2])
                elif idx1 >=0 :
                    tmp += int(s1[idx1])
                elif idx2 >=0 :
                    tmp += int(s2[idx2])
                ret += str(tmp%10)
                tmp = tmp/10
                start += 1
            if tmp:
                ret += str(tmp)
            return ret[::-1]
        
        def mmul(s1 , n):
            s1 = s1[::-1]
            ans = ""
            ai = 0
            for i in s1:
                tmp = int(i) * int(n) + ai
                ai = tmp/10
                ans += str(tmp%10)
            if ai:
                ans += str(ai)
            return ans[::-1]
        n2 = num2[::-1]
        ans = ""
        cnt = 0
        for i in n2:
            tmpstr = mmul(num1 , i)
            ans = madd(ans , tmpstr ,cnt)
            cnt+=1
        if ans[0] == '0': 
            return "0"
        return ans

class Solution1(object):

    def multiply(self , num1 , num2):
        if num1 == '' or num2 == '':
            return '0'
        len1 = len(num1)
        len2 = len(num2)
        ans = []
        for i in range(0,len1 + len2):
            ans.append(0)
        i = len1-1
        while i>= 0:
            j = len2-1
            while j>= 0:
                tmpInt = int(num1[i]) * int(num2[j]) + ans[i+j+1]
                ans[i+j+1] = tmpInt%10
                ans[i+j]  += tmpInt/10
                j-=1
            i-=1

        flag = False
        ret = ''
        for i in ans:
            if i and flag == False:
                flag = True
            if flag == True:
                ret += str(i)
        if flag == False:
            return '0'
        return ret

def run():
    so = Solution1()
    print so.multiply("887215951631860898850672165670178191617772888069065122540029356168329298406","44311453195435793851382571199824255312824367056642992271581465800553855214")
