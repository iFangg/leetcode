// Solution 1 - FAIL
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        /*
        max answer is m
        array to store each row's bits
        max XOR sum from one row to all others?
        */

        int[] r_bits = new int[matrix.length];

        int idx = 0;
        for (int[] r : matrix) {
            int bits = 0b0;

            for (int b : r) {
                bits |= b;
                bits <<= 1;
            }

            r_bits[idx] = bits;
            idx++;
        }

        int res = 0;

        for (int i = 0; i < matrix.length; ++i) {
            int score = 0;
            for (int j = 0; j < matrix.length; ++j) {
                if (i == j)
                    continue;
                
                if ((r_bits[i] ^ r_bits[j]) == 0)
                    score++;
            }

            res = Math.max(res, score);
        }

        return res;
    }
}


// Solution 2
import java.util.HashMap;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        HashMap<String, Integer> rowPatterns = new HashMap<>();

        for (int[] row : matrix) {
            StringBuilder normal = new StringBuilder();
            StringBuilder flipped = new StringBuilder();

            // Build normal and flipped row patterns
            for (int bit : row) {
                normal.append(bit);
                flipped.append(1 - bit); // Flip the bit
            }

            // Use the normal or flipped pattern as the key
            String key = normal.toString();
            String flipKey = flipped.toString();
            rowPatterns.put(key, rowPatterns.getOrDefault(key, 0) + 1);
            rowPatterns.put(flipKey, rowPatterns.getOrDefault(flipKey, 0) + 1);
        }

        // Find the maximum count of any pattern
        int res = 0;
        for (int count : rowPatterns.values()) {
            res = Math.max(res, count);
        }

        return res;
    }
}


// Solution 3
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        // Get the number of rows (n) and columns (m) in the matrix
        int n = matrix.length, m = matrix[0].length;
        
        // Variable to store the maximum number of identical rows
        int res = 0;

        // A HashMap to count the occurrences of normalized row patterns
        Map<Integer, Integer> map = new HashMap<>();

        // Iterate through each row of the matrix
        for (int i = 0; i < n; i++) {
            // Check the last element of the current row to decide if we need to flip the row
            if (matrix[i][m - 1] == 1) {
                // Flip the entire row if the last element is 1
                for (int j = 0; j < m; j++) {
                    // XOR each element with the last element (1) to flip it
                    matrix[i][j] ^= matrix[i][m - 1];
                }
            }
            
            // Generate a unique hash code for the normalized row
            int hashCode = Arrays.hashCode(matrix[i]);

            // Use HashMap.merge to update the count of this row's hash code
            // - If the hash code already exists, increment its count by 1
            // - If it doesn't exist, initialize its count to 1
            int count = map.merge(hashCode, 1, Integer::sum);

            // Update the result to store the maximum frequency of any normalized row
            res = Math.max(res, count);
        }

        // Return the result, which is the maximum number of rows that can be made identical
        return res;
    }
}
