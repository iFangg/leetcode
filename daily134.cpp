// Solution 1 - FAIL
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        /*
        dp, ith row jth column gives max number of moves to this grid
        */
        // Initialize DP table with the same size as grid, filled with 0s.
        auto moves = std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid[0].size(), 0));

        // Fill DP table from left to right, calculating max moves possible to each cell.
        for (int j = 0; j < grid[0].size() - 1; ++j) {
            for (int i = 0; i < grid.size(); ++i) {
                
                // Move to (i+1, j+1) if valid, and next cell is greater than current cell
                if (i + 1 < grid.size() && grid[i + 1][j + 1] > grid[i][j]) {
                    moves[i + 1][j + 1] = std::max(moves[i + 1][j + 1], moves[i][j] + 1);
                }
                
                // Move to (i, j+1) if next cell is greater than current cell
                if (grid[i][j + 1] > grid[i][j]) {
                    moves[i][j + 1] = std::max(moves[i][j + 1], moves[i][j] + 1);
                }
                
                // Move to (i-1, j+1) if valid, and next cell is greater than current cell
                if (i - 1 >= 0 && grid[i - 1][j + 1] > grid[i][j]) {
                    moves[i - 1][j + 1] = std::max(moves[i - 1][j + 1], moves[i][j] + 1);
                }
            }
        }

        // Find the maximum moves possible from any cell in the last column.
        int max_move = 0;
        for (int i = 0; i < grid.size(); ++i) {
            max_move = std::max(max_move, moves[i][grid[0].size() - 1]);
        }

        return max_move;
    }
};


// Solution 2
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        // Get dimensions of the grid
        int m = grid.size();    // number of rows
        int n = grid[0].size(); // number of columns
        
        // res will store the rightmost column we can reach
        int res = 0;
        
        // dp array stores the maximum number of moves possible to reach each cell
        // in the current column we're processing
        vector<int> dp(m);
        
        // Iterate through each column from left to right (starting from column 1)
        for (int j = 1; j < n; ++j) {
            // leftTop keeps track of the dp value from the cell above-left
            int leftTop = 0;
            // found indicates if we can reach any cell in current column
            bool found = false;
            
            // Iterate through each row in current column
            for (int i = 0; i < m; ++i) {
                // cur will store the maximum moves to reach current cell
                int cur = -1;
                // Store dp[i] for next iteration's leftTop
                int nxtLeftTop = dp[i];
                
                // Check move from top-left cell (if valid)
                if (i - 1 >= 0 && leftTop != -1 && grid[i][j] > grid[i - 1][j - 1]) {
                    cur = max(cur, leftTop + 1);
                }
                
                // Check move from direct left cell (if valid)
                if (dp[i] != -1 && grid[i][j] > grid[i][j - 1]) {
                    cur = max(cur, dp[i] + 1);
                }
                
                // Check move from bottom-left cell (if valid)
                if (i + 1 < m && dp[i + 1] != -1 && grid[i][j] > grid[i + 1][j - 1]) {
                    cur = max(cur, dp[i + 1] + 1);
                }
                
                // Update dp array for current cell
                dp[i] = cur;
                // Update found flag if we can reach current cell
                found = found || (dp[i] != -1);
                // Update leftTop for next row's iteration
                leftTop = nxtLeftTop;
            }
            
            // If we can't reach any cell in current column, break
            if (!found) break;
            // Update result to current column if we can reach it
            res = j;
        }
        
        // Return the maximum number of moves possible
        return res;
    }
};


// Solution 3
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Memoization table for max moves from each cell
        std::vector<std::vector<int>> moves(m, std::vector<int>(n, -1));
        
        // Helper function to perform DFS with memoization
        auto dfs = [&](auto&& self, int i, int j) -> int {
            // If out of bounds, return 0 moves possible
            if (j == n - 1) return 0; // Last column reached
            if (moves[i][j] != -1) return moves[i][j]; // Return cached result
            
            int max_move = 0;

            // Check all valid moves to the next column
            if (i > 0 && grid[i][j] < grid[i - 1][j + 1]) {
                max_move = std::max(max_move, 1 + self(self, i - 1, j + 1));
            }
            if (grid[i][j] < grid[i][j + 1]) {
                max_move = std::max(max_move, 1 + self(self, i, j + 1));
            }
            if (i + 1 < m && grid[i][j] < grid[i + 1][j + 1]) {
                max_move = std::max(max_move, 1 + self(self, i + 1, j + 1));
            }
            
            moves[i][j] = max_move; // Cache the result
            return max_move;
        };
        
        // Find maximum moves possible starting from any cell in the first column
        int max_result = 0;
        for (int i = 0; i < m; ++i) {
            max_result = std::max(max_result, dfs(dfs, i, 0));
        }
        
        return max_result;
    }
};
