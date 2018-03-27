class Solution(object):

    def dfs(self, board, word, x, y):
        if word == '':
            return True
        if x < 0 or y < 0 \
            or x >= len(board) or y >= len(board[x]) \
            or board[x][y] != word[0]: 
            return False
        tmp = board[x][y]
        board[x][y] = '#'
        ret = self.dfs(board, word[1:], x +1, y) \
                or self.dfs(board, word[1:], x -1, y) \
                or self.dfs(board, word[1:], x, y+1) \
                or self.dfs(board, word[1:], x, y-1)
        board[x][y] = tmp
        return ret

    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        for x in xrange(len(board)):
            for y in xrange(len(board[x])):
                if self.dfs(board, word, x, y):
                    return True
        return False

def run():
    s = Solution()
    mp = [ ['A','B','C','E'], ['S','F','C','S'], ['A','D','E','E']]
    wd = "ABCB"
    print s.exist(mp, wd)

