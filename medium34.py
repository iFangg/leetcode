# Solution 1
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        width = len(matrix)
        height = len(matrix[0])
        zeroes_row = set()
        zeroes_col = set()
        for i in range(width):
            for j in range(height):
                if matrix[i][j] == 0:
                    zeroes_row.add(i)
                    zeroes_col.add(j)
        
        for i in range(width):
            for j in range(height):
                if i in zeroes_row or j in zeroes_col:
                    matrix[i][j] = 0


# Solution 2

