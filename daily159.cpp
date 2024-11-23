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
      int m = box.length, n = box[0].length;
      char[][] res = new char[n][m];
      
      for (int i = 0; i < m; ++i)
        for (int j = n - 1, k = n - 1; j >= 0; --j) {
          res[j][m - i - 1] = '.';
          
          if (box[i][j] != '.') {
            k = box[i][j] == '*' ? j : k;
            res[k--][m - i - 1] = box[i][j];
          }
      }
      
      return res;
    }
}
