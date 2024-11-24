// Solution 1 - FAIL
class solution {
    public long res = 0;

    public long maxmatrixsum(int[][] matrix) {
        /**
        back track
            find intial sum of matrix, set that as max
            start with 0, 0
            for each adjacent element, flip and calculate sum
            recurse down w that
            update max sum
            weird doesn"t work
        
        look at where most negatives are?
        greedy
            how?
        **/

        long sum = 0;

        for (int[] r : matrix) {
            for (int n : r) {
                sum += n;
            }
        }

        res = sum;

        return res;
    }
}


// Solution 2
class Solution {
    public long maxMatrixSum(int[][] matrix) {
      int min = Integer.MAX_VALUE;
      long sum = 0;
      int negCount = 0; 
      for(int i=0; i<matrix.length; i++)
        for(int j=0; j<matrix[0].length; j++)
        {
           if(matrix[i][j]<0)
           negCount++;
           int ab = Math.abs(matrix[i][j]);
           min = Math.min(min, ab);
           sum += ab;    
      }
      if(negCount%2==0)
        return sum; 
      return sum - 2*min;
  }
}
