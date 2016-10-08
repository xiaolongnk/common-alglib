class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        l1 = len(a)
        l2 = len(b)
        mx = max(l1, l2)
        cnt = 0
        ans = ""
        carry = 0
        while cnt < mx:
            na = 0
            nb = 0
            if cnt < l1:
                na = int(a[l1 - cnt - 1])
            if cnt < l2:
                nb = int(b[l2 - cnt - 1])
            tmp = carry + na + nb
            carry = tmp /2
            ans += str(tmp%2)
            cnt+=1
        if carry==1:
            ans += str(carry)
        return ans[::-1]

def run():
    so = Solution()
    print so.addBinary("1111",'1')
