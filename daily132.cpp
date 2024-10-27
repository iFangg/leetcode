// Solution 1 - FAIL
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        /*
        prefix sum to figure out how many 1s up to ith row and column
        check thru all possible squares to find squares with a one in it

        rows VV
        cols ->>
        */

        auto one_rows = std::vector<int>(matrix.size(), 0);
        auto one_cols = std::vector<int>(matrix[0].size(), 0);

        for (auto i = 0; i < matrix.size(); ++i) {
            for (auto j = 0; j < matrix[0].size(); ++j) {
                if (j == 0)
                    one_rows[i] = matrix[i][j] == 1 ? 1 : 0;
                else
                    one_rows[i] = matrix[i][j] == 1 ? one_rows[i - 1] + 1 : one_rows[i - 1];
                
                if (i == 0)
                    one_cols[j] = matrix[i][j] == 1 ? 1 : 0;
                else
                    one_cols[j] = matrix[i][j] == 1 ? one_cols[j - 1] + 1 : one_cols[j - 1];
            }
        }

        int squares = 0;
        for (int i = one_rows.size() - 1; i >= 0; --i) {
            for (int j = one_cols.size() - 1; j >= 0; --j) {
                if (one_rows[i] * one_cols[j] >= j * j)
                    squares++;
            }
        }

        return squares;
    }
}


// Solution 2
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int squares = 0;

        // Use matrix itself as the DP table
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    // Update the cell to store the size of the largest square ending at (i, j)
                    matrix[i][j] = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                }
                squares += matrix[i][j]; // Sum up all squares sizes
            }
        }

        return squares;
    }
};

