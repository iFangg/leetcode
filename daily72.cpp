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
        visited_ = std::vector<std::vector<int>>(grid1.size(), std::vector<int>(grid1[0].size(), 0));
        
        return total;
    }

private:
    std::vector<std::vector<int>> grid1_;
    std::vector<std::vector<int>> grid2_;
    std::vector<std::vector<int>> visited_;
    int total = 0;
}
