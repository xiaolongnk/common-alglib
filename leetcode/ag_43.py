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
        

        
        n1 = num1[::-1]
        n2 = num2[::-1]
        ans = ""
        cnt = 0
        for i in n2:
            tmp_str = ""
            incnt = 0
            for j in n1:
                current = str(int(i) * int(j))
                tmp_str = madd(tmp_str , current,incnt)
                incnt +=1
            ans = madd(ans , tmp_str,cnt)
            cnt+=1
        if ans[0] == '0': 
            return "0"
        return ans

def run():
    so = Solution()
    print so.multiply("123","0")
