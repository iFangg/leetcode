#include <iostream>
#include <vector>
#include "daily55_solution.h" // Include the file where your Solution class is defined.

int main() {
    // Test case
    std::vector<std::vector<int>> grid = {
        {0, 1, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the minDays method with the test case
    int result = solution.minDays(grid);

    // Print the result
    std::cout << "\nMinimum days to disconnect the grid: " << result << std::endl;

    return 0;
}
