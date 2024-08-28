#include <iostream>
#include <vector>

// Solution 1
class Solution {
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        /* 
        count islands from grid 1 and grid 2
        store a starting point for all islands
        store size of islands (dont compare grid 2 islands with smaller grid 1 islands)
        store max/min row and col for each island?dw

        maybe we can determine subislands as we find all islands in grid 1
        traversing through potential islands while searching in grid 1,
        or search grid 2
            if any cell in the current grid 2 island matches to a grid 1 water cell, this current island is not a subisland 
        */
      
        grid1_ = std::move(grid1);
        grid2_ = std::move(grid2);
        visited_ = std::vector<std::vector<int>>(grid1_.size(), std::vector<int>(grid1_[0].size(), 0));

        for (auto i = 0; i < grid2_.size(); ++i) {
            for (auto j = 0; j < grid2_[0].size(); ++j) {
                if (grid2_[i][j] == 0)
                    continue;
                
                if (visited_[i][j])
                    continue;
                
                auto is_sub = dfs(std::make_pair(i, j));
                if (is_sub)
                    total++;
            }
        }
        
        return total;
    }

private:
    bool dfs(std::pair<int, int> curr) {
        auto r = curr.first;
        auto c = curr.second;
        auto is_sub = true;

        if (visited_[r][c])
            return is_sub;
        
        visited_[r][c] = 1;
        if (grid2_[r][c] and !grid1_[r][c])
            is_sub = false;

        auto still_sub = true;
        if (r + 1 < grid2_.size() and grid2_[r + 1][c]) {
            still_sub = dfs(std::make_pair(r + 1, c));
            if (is_sub)
                is_sub = still_sub;
        }

        if (r - 1 >= 0 and grid2_[r - 1][c]) {
            still_sub = dfs(std::make_pair(r - 1, c));
            if (is_sub)
                is_sub = still_sub;
        }
        
        if (c + 1 < grid2_[0].size() and grid2_[r][c + 1]) {
            still_sub = dfs(std::make_pair(r, c + 1));
            if (is_sub)
                is_sub = still_sub;
        }
        
        if (c - 1 >= 0 and grid2_[r][c - 1]) {
            still_sub = dfs(std::make_pair(r, c - 1));
            if (is_sub)
                is_sub = still_sub;
        }
        
        return is_sub;
    }

    std::vector<std::vector<int>> grid1_;
    std::vector<std::vector<int>> grid2_;
    std::vector<std::vector<int>> visited_;
    int total = 0;
};


// Solution 2
class Solution {
private:
    int rows, cols;
    std::vector<std::vector<int>> status;
    const std::vector<int> DR = {-1, 1, 0, 0};
    const std::vector<int> DC = {0, 0, -1, 1};

    bool dfs(int r, int c, std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        if (grid1[r][c] != 1) {
            status[r][c] = -1;
            return false;
        }

        status[r][c] = 1;
        bool isSubIsland = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + DR[i];
            int nc = c + DC[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (status[nr][nc] == -1) {
                    status[r][c] = -1;
                    return false;
                }
                if (status[nr][nc] == 1) continue;
                if (grid2[nr][nc] == 1 && !dfs(nr, nc, grid1, grid2)) {
                    status[r][c] = -1;
                    return false;
                }
            }
        }

        return isSubIsland;
    }

public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2) {
        rows = grid1.size();
        cols = grid1[0].size();
        status = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
        int subIslandCount = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (status[r][c] == 0 && grid2[r][c] == 1) {
                    if (dfs(r, c, grid1, grid2)) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};

static const auto speedup = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main() {
    Solution sol;
    std::vector<std::vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1}
    };

    std::vector<std::vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0}
    };

    std::cout << "There are " << sol.countSubIslands(grid1, grid2) << " sub islands\n";

    return 0;
}
