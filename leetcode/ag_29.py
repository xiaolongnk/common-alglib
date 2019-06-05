class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = -1
        if (dividend < 0 and divisor < 0) or (dividend > 0 and divisor > 0):
            sign = 1
        if divisor == 1:
            return dividend if sign == 1 else -dividend
        i = 0
        while True:
            a = divisor << i
            b = divisor << (i + 1)

def run():
    pass
