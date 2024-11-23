// Solution 1
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        /**
        m x n becomes n x m
        move all stones before swapping
            stones move to the right of each row

        obstacles swap coordinates but do not move
            swap from i, j to j, row len - 1 - i
        all stones move to nearest obstacle or end of col
            count amount of stones, n, in the row until obstacle/end
            place n at obstacle/end of the row
         */

        for (int i = 0; i < box.length; i++) {
            int stones = 0;
            int j = 0;
            
            while (j < box[0].length) {
                if (box[i][j] == '#') {
                    box[i][j] = '.';
                    stones++;
                } else if (box[i][j] == '*') {
                    int curr = j - 1;

                    while (stones > 0 && (curr >= 0 || box[i][curr] != '*')) {
                        box[i][curr] = '#';
                        stones--;
                        curr--;
                    }
                }

                j++;
            }

            int curr = box[0].length - 1;

            while (stones > 0 && (curr >= 0 || box[i][curr] != '*')) {
                box[i][curr] = '#';
                stones--;
                curr--;
            }
        }

        char[][] flipped = new char[box[0].length][box.length];
        
        // each row becomes a column
        for (int r = 0; r < box.length; r++) {
            for (int c = 0; c < box[0].length; c++) {
                flipped[c][box.length - 1 - r] = box[r][c];
            }
        }

        return flipped;
    }
}


// Solution 2
class Solution {
    public char[][] rotateTheBox(char[][] box) {
        int m = box.length, n = box[0].length; // m = rows, n = columns in the original box
        char[][] res = new char[n][m];        // Resultant box after 90-degree rotation

        // Iterate over each row of the box
        for (int i = 0; i < m; ++i) {
            // Initialize pointers:
            // j = iterates through the current row from right to left
            // k = position where the next stone will "fall" due to gravity
            for (int j = n - 1, k = n - 1; j >= 0; --j) {
                // By default, set the rotated position to empty
                res[j][m - i - 1] = '.';

                // If the current cell contains a stone or an obstacle
                if (box[i][j] != '.') {
                    // If it's an obstacle ('*'), reset k to this position
                    if (box[i][j] == '*') {
                        k = j;
                    }
                    // Place the stone or obstacle at the correct rotated position
                    res[k--][m - i - 1] = box[i][j];
                }
            }
        }

        return res; // Return the rotated and processed box
    }
}

