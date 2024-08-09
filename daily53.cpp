#include <vector>

class Solution {
public:
    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        if (grid.size() < 3)
            return {};
            
        // precompute prefix sums of grid from left to right, up to down
    }
};