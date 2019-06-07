class Solution(object):
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
     	import re
        def gcd(x, y):
            while y:
                x, y = y, x%y
            return x
        nums = map(int, re.findall('[+-]?\d+', expression))
        A , B = 0, 1
        for a, b in zip(nums[::2], nums[1::2]):
            A = A * b + B * a;
            B *= b
            g = gcd(A, B)
            A /= g
            B /= g
        return '{0}/{1}'.format(A, B)

def run():
    s = Solution()
    c = "-1/2+1/2+1/3"
    print s.fractionAddition(c)
