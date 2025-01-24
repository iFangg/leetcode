// Solution 1
class Solution {
    public String convert(String s, int numRows) {
        /*
            for diagonals, always gonna be n - 2 steps after we go down n rows
            
            stack
                add chars in order of rows
                first row, add for every n + (n - 2) chars
                second row, add for every n chars?
                sequence is confusing
            
            matrix brute force sol'n
                map string to 2d matrix
                make result string row by row
        */

        if (numRows == 1)
            return s;

        char[][] m = new char[numRows][1000];
        int s_idx = 0;
        int diagonal = 0;
        int cols = 0;

        for (int i = 0; i < 1000; i++) {
            if (s_idx == s.length()) {
                cols = i;
                break;
            }

            if (diagonal != 0 && diagonal <= numRows - 2) {
                // System.out.println(diagonal);
                // System.out.println(s.charAt(s_idx));
                m[numRows - 1 - diagonal][i] = s.charAt(s_idx);
                s_idx++;
                diagonal++;

                if (diagonal > numRows - 2)
                    diagonal = 0;
                    
                continue;
            }

            for (int j = 0; j < numRows; j++) {
                if (s_idx == s.length())
                    break;
                // System.out.println(s.charAt(s_idx));
                m[j][i] = s.charAt(s_idx);
                s_idx++;
            }

            diagonal++;
        }

        StringBuilder res = new StringBuilder();
        s_idx = 0;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < cols; j++) {
                if (m[i][j] != '\u0000')
                    res.append(m[i][j]);
            }
        }

        return res.toString();
    }
}


// Solution 2
class Solution {

    /**
     * Converts the input string `s` into a zigzag pattern based on the number of rows
     * and then reads the pattern row by row.
     *
     * @param s The input string to convert.
     * @param numRows The number of rows in the zigzag pattern.
     * @return The string constructed by reading the zigzag pattern row by row.
     */
    public String convert(String s, int numRows) {
        int l = s.length(); // Length of the input string.
        // Skip (step size) for characters based on the number of rows.
        // If `numRows` is 1, no zigzag is possible, so `skip` is 1. Otherwise, calculate the step size as `2 * (numRows - 1)`.
        int skip = numRows == 1 ? 1 : 2 * (numRows - 1);
        
        int top = 0; // Pointer to track the position in the output character array.
        char[] out = new char[l]; // Output array to store the reordered characters.

        // Iterate over each row in the zigzag pattern.
        for (int i = 0; i < numRows; i++) {
            // Traverse the string, picking characters for the current row.
            for (int j = i; j < l; j += skip) {
                // Add the main vertical characters for this row.
                out[top++] = s.charAt(j);

                // Handle the diagonal characters (for rows that are neither the top nor the bottom).
                if (i > 0 && i < numRows - 1 && j + skip - 2 * i < l) {
                    // Calculate the index of the diagonal character and add it to the output.
                    out[top++] = s.charAt(j + skip - 2 * i);
                }
            }
        }

        // Convert the output character array into a string and return it.
        return new String(out);
    }
}


