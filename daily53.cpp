#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>

// Solution 1
class Solution {
public:
    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        if (grid.size() < 3)
            return 0;
            
        // precompute prefix sums of grid from left to right, up to down
        // then observe every row and col sum after the 3rd row and column.

        // first is row sum, second is col sum
        auto sums = std::vector<std::vector<std::pair<int, int>>>(grid.size(), std::vector<std::pair<int,int>>(grid[0].size(), std::make_pair(0, 0)));

        // find all possible square starts?
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                auto r_add = grid[i][j];
                auto c_add = grid[i][j];

                // add to row sum
                if (j != 0) {
                    r_add += sums[i][j - 1].first;
                }

                // add to col sum
                if (i != 0) {
                    c_add += sums[i - 1][j].second;
                }

                sums[i][j].first += r_add;
                sums[i][j].second += c_add;
            }
        }

        auto total = 0;
        auto curr_sum = 0;
        auto r = 0;
        auto c = 2;

        // have starting coords (bounds) for first square
        // move magic square to the right, then reset and move down one row
        while (r < grid.size() - 2 and c < grid.size()) {
            auto seen = std::unordered_set<int>{};
            auto gt_nine_found = false;
            auto equal = true;
            curr_sum = sums[r][c].first;

            if (curr_sum >= 25) { // sum can't be greater than 25 - curr_sum < 25 or <= 24
                equal = false;

                c++;
                if (c == grid.size()) {
                    r++;
                    c = 2;
                }
                
                continue;
            }

            // checking for unique and in between 0 and 9
            for (auto i = r; i < r + 3; ++i) {
                for (auto j = r; j < r + 3; ++j) {
                    if (grid[i][j] <= 9 and grid[i][j] > 0)
                        seen.insert(grid[i][j]);
                }
            }

            if (seen.size() != 9) {
                c++;
                if (c == grid.size()) {
                    r++;
                    c = 2;
                }
 
                continue;
            }

            // check diagonals
            if (grid[r][r] + grid[r + 1][r + 1] + grid[c][c] != curr_sum) {
                gt_nine_found = false;
            }

            if (grid[r][c] + grid[r + 1][r + 1] + grid[c][r] != curr_sum) {
                gt_nine_found = false;
            }

            // check row rums
            for (auto i = r + 1; i < r + 3; ++i) {
                if (sums[i][c].first != curr_sum) {
                    equal = false;
                    break;
                }
            }

            // check col sums
            for (auto j = r; j < r + 3; ++j) {
                if (sums[c][j].second != curr_sum) {
                    equal = false;
                    break;
                }
            }

            c++;
            if (c == grid.size()) {
                r++;
                c = 2;
            }

            if (equal and !gt_nine_found)
                total++;
        }

        return total;
    }
};


// Solution 2
class Solution {
public:
    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;

        int total = 0;

        for (int r = 0; r <= grid.size() - 3; ++r) {
            for (int c = 0; c <= grid[0].size() - 3; ++c) {
                if (isMagic(grid, r, c))
                    total++;
            }
        }

        return total;
    }

private:
    bool isMagic(const std::vector<std::vector<int>>& grid, int r, int c) {
        std::unordered_set<int> seen;
        int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

        // Check rows and collect numbers
        for (int i = r; i < r + 3; ++i) {
            int rowSum = 0;
            for (int j = c; j < c + 3; ++j) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || !seen.insert(grid[i][j]).second)
                    return false;
                rowSum += grid[i][j];
            }
            if (rowSum != sum)
                return false;
        }

        // Check columns
        for (int j = c; j < c + 3; ++j) {
            int colSum = 0;
            for (int i = r; i < r + 3; ++i) {
                colSum += grid[i][j];
            }
            if (colSum != sum)
                return false;
        }

        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum)
            return false;

        return true;
    }
};


// Solution 3
#include <vector>
#include <set>

class Solution {
public:
    bool isMagic(const std::vector<std::vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if (i + 2 >= n || j + 2 >= m) return false;

        // Calculate sums for rows, columns, and diagonals
        int col1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
        int col2 = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
        int col3 = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];

        int row1 = grid[i][j] + grid[i+1][j] + grid[i+2][j];
        int row2 = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
        int row3 = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];

        int dia1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int dia2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        // Check if all sums are equal
        if (col1 == col2 && col1 == col3 && col1 == row1 && col1 == row2 && 
            col1 == row3 && col1 == dia1 && col1 == dia2) {
            
            std::set<int> s{1, 2, 3, 4, 5, 6, 7, 8, 9};
            
            // Check if all numbers 1-9 are used exactly once
            for (int k = 0; k < 3; ++k) {
                for (int l = 0; l < 3; ++l) {
                    s.erase(grid[i+k][j+l]);
                }
            }
            return s.empty();
        }
        
        return false;
    }

    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isMagic(grid, i, j)) {
                    ++count;
                }
            }
        }
        
        return count;
    }
};

