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

# __________
# Solution 2
def setZeroes(matrix: List[List[int]]) -> None:
    if not matrix:return []
    row=len(matrix);col=len(matrix[0])
    zr=[False]*row;zc=[False]*col
    for i in range(row):
        for j in range(col):
            if matrix[i][j]==0:zr[i]=True;zc[j]=True
    for i in range(row):
        for j in range(col):
            if zr[i] or zc[j]:matrix[i][j] = 0
if __name__ == '__main__':
    import json, sys
    with open('user.out', 'w') as f:
        for matrix in map(json.loads, sys.stdin):
            setZeroes(matrix)
            print(json.dumps(matrix, separators=(',',':')), file=f)
    sys.exit()
