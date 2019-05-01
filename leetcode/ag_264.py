class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        i2 = i3 = i5 = 0;
        uglys = [1];
        j = 1;
        while j < n:
            mm = min((uglys[i2] * 2, uglys[i3] * 3, uglys[i5] * 5));
            if mm == uglys[i2] * 2:
                i2 += 1;
            if mm == uglys[i3] * 3:
                i3 += 1;
            if mm == uglys[i5] * 5:
                i5 += 1
            uglys.append(mm)
            j = j + 1
        return uglys[-1];

def run():
    s = Solution()
    print s.nthUglyNumber(10)
