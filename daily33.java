// Solution 1
class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int[][] matrix = new int[rowSum.length][colSum.length];

        Queue<Integer> remCols = new LinkedList<>();
        Queue<Integer> remRows = new LinkedList<>();

        for (int i = 0; i < rowSum.length; i++) {
            remRows.add(i);
        }
        for (int i = 0; i < colSum.length; i++) {
            remCols.add(i);
        }

        int c;
        int r;
        while (remCols.size() > 0 && remRows.size() > 0) {
            r = remRows.peek();
            c = remCols.peek();

            if (rowSum[r] < colSum[c]) {
                matrix[r][c] = rowSum[r];
                colSum[c] -= rowSum[r];
                rowSum[r] = 0;
                remRows.poll();
            } else if (rowSum[r] > colSum[c]) {
                matrix[r][c] = colSum[c];
                rowSum[r] -= colSum[c];
                colSum[c] = 0;
                remCols.poll();
            } else {
                matrix[r][c] = rowSum[r];
                rowSum[r] = 0;
                colSum[c] = 0;
                remRows.poll();
                remCols.poll();
            }
        }
        
        return matrix;
    }
}
