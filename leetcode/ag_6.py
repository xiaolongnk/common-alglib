class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        ans_str = ''
        s_len = len(s)
        processed_rows = 0
        if numRows == 1:
            len_of_parts = 1
        else:
            len_of_parts = 2*(numRows - 1)
        while  processed_rows < numRows:
            processed_len = 0
            while processed_rows + processed_len < s_len:
                ans_str += s[processed_rows + processed_len]
                idx = processed_len + len_of_parts - processed_rows
                if idx < s_len and processed_rows < numRows - 1 and processed_rows > 0:
                    ans_str += s[idx]
                processed_len += len_of_parts
            processed_rows += 1
        return ans_str


def run():
    s = Solution()
    print s.convert('A', 1)
    print s.convert('AB', 2)
    print s.convert('ABC', 3)
    print s.convert('PAYPALISHIRING', 3)


