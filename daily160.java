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
        // Step 1: Initialize variables
        int min = Integer.MAX_VALUE; // To track the smallest absolute value in the matrix
        long sum = 0;                // To accumulate the total sum of absolute values
        int negCount = 0;            // To count the number of negative elements in the matrix

        // Step 2: Iterate over each element in the matrix
        for (int i = 0; i < matrix.length; i++) {          // Loop through rows
            for (int j = 0; j < matrix[0].length; j++) {   // Loop through columns
                // Check if the current element is negative
                if (matrix[i][j] < 0) {
                    negCount++; // Increment the negative count
                }

                // Compute the absolute value of the current element
                int ab = Math.abs(matrix[i][j]);

                // Update the smallest absolute value seen so far
                min = Math.min(min, ab);

                // Add the absolute value to the total sum
                sum += ab;
            }
        }

        // Step 3: Determine the result based on the number of negative elements
        if (negCount % 2 == 0) {
            // If the count of negative elements is even, return the total sum
            return sum;
        }

        // If the count of negative elements is odd, subtract twice the smallest absolute value
        return sum - 2 * min;
    }
}
