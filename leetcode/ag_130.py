class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        if len(board) == 0:
            return
        if len(board[0]) == 0:
            return
        lr = len(board)
        lc = len(board[0])
        for i in range(lr):
            self.borderCheck(board, i, 0)  #first column
            self.borderCheck(board, i, lc - 1) #end column
        
        for i in range(lc):
            self.borderCheck(board, 0, i) #first row
            self.borderCheck(board, lr - 1, i)#end row
        for i in range(len(board)):
            for j in range(len(board[i])):
                if board[i][j] == '1':
                    board[i][j] = 'O'
                elif board[i][j] == 'O':
                    board[i][j] = 'X'

    def borderCheck(self, board, i, j):
        if board[i][j] == 'O':
            board[i][j] = '1'
            if i > 1:
                self.borderCheck(board, i - 1, j)
            if j > 1:
                self.borderCheck(board, i, j - 1)
            if i < len(board) - 1:
                self.borderCheck(board, i + 1, j)
            if j < len(board[0]) - 1:
                self.borderCheck(board, i, j + 1)
def run():
    s= Solution()
    board = [["O"]]
    for i in board:
        print i,""
    s.solve(board)
    for i in board:
        print i,""
