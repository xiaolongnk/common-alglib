class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """
        if z > x + y: return False
        if x > y : x,y = y,x
        gd = self.gcd(x , y)
        if gd == 0: return not z > 0
        return z % gd == 0

    def gcd(self , a , b):
        if a == 0: return b
        return self.gcd(b%a , a)


if __name__=='__main__':
    sn = Solution()
    a = 3
    b = 5
    c = 4
    print sn.canMeasureWater(a,b,c)
    while True:
        ss = raw_input()
        if ss == 'exit':
            break
        ss = ss.split(" ")
        try:
            print sn.canMeasureWater(int(ss[0]) , int(ss[1]), int(ss[2]))
        except:
            print "Bye"
            break

        
