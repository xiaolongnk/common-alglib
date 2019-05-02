class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        last_level_str = self.countAndSay(n-1)
        prev_char = ''
        prev_char_cnt = 0
        res = ''
        for i in last_level_str:
            if prev_char == '':
                prev_char = i
                prev_char_cnt += 1
            else:
                if prev_char == i:
                    prev_char_cnt += 1
                else:
                    res = res + str(prev_char_cnt) + prev_char
                    prev_char_cnt = 1
                    prev_char = i
        res += str(prev_char_cnt) + prev_char
        return res



def run():
    s = Solution()
    print s.countAndSay(8)
