class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        boxdup = [[]  for i in range(9)]
        current_box_idx = 0
        for r in range(0,9):
            rowdup = [0] * 9
            coldup = [0] * 9
            coldata = []
            for c in range(0,9):
                coldata.append(board[c][r])
                current_box_idx = int(r / 3) * 3 + int((c) / 3);
                boxdup[current_box_idx].append(board[r][c])
            boxdup.append(board[r]) # all rows
            boxdup.append(coldata) # all columns
        
        for jst in boxdup:
            tdup = [0] * 9
            for k in jst:
                if k != '.':
                    key = int(k) - 1
                    if tdup[key] == 0:
                        tdup[key] = 1
                    else:
                        return False
        return True




def run():
    lst = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ];
    s = Solution()
    print s.isValidSudoku(lst)
