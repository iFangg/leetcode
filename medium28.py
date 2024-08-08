# Solution 1
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        length = len(matrix)
        for i in range(length):
            for j in range(i, length - i):
                if j == length - i - 1:
                    continue
                q1 = matrix[i][j]
                q2 = matrix[j][length - 1 - i]
                q3 = matrix[length - 1 - i][length - 1 - j]
                q4 = matrix[length - 1 - j][i]
                print(q1, q2, q3, q4)

                matrix[i][j] = q4
                matrix[j][length - 1 - i] = q1
                matrix[length - 1 - i][length - 1 - j] = q2
                matrix[length - 1 - j][i] = q3

# Solution 2
    def rotate(self, matrix: List[List[int]]) -> None:
        for i in range(len(matrix)):
            for j in range(i):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
                
        for row in matrix:
            lp = 0
            rp = len(row) - 1
            while lp < rp:
                row[lp], row[rp] = row[rp], row[lp]
                lp += 1
                rp -= 1
        return matrix

