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
        if divisor == -1 and dividend == -2147483648:
            return 2147483647
        divisor = abs(divisor)
        dividend = abs(dividend)
        if dividend < divisor:
            return 0
        origin_divisor = divisor
        q = 1
        rq = 0
        while True:
            t = divisor << 1
            if dividend >= t:
                divisor = t
                q += q
            else:
                rq += q
                q = 1
                dividend -= divisor
                divisor = origin_divisor
                if dividend < (divisor << 1):
                    if dividend >= divisor:
                        rq += 1
                    break
        return -rq if sign == -1 else rq

def run():
    s = Solution()
    ans = s.divide(331, 1)
    print ans

