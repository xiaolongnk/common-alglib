class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == '1':
                    self.dfs(grid, i, j)
                    count+=1
        return count

    def dfs(self, grid, i, j):
        if i < 0 or i>=len(grid) or j < 0 or j >= len(grid[0]):
            return
        if grid[i][j] != '1':
            return
        grid[i][j] = '#'
        self.dfs(grid, i,j + 1)
        self.dfs(grid, i,j - 1)
        self.dfs(grid, i - 1, j)
        self.dfs(grid, i + 1, j)
       
def run():
    s= Solution()
    grid = [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]

    print s.numIslands(grid)
    for i in grid:
        print i,""
