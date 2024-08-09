#include <iostream>
#include <vector>
#include "daily52_solution.h" // Assuming your Solution class is in a file named Solution.h

void printResult(const std::vector<std::vector<int>>& result) {
    for (const auto& cell : result) {
        std::cout << "[" << cell[0] << ", " << cell[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Test case 1
    int rows1 = 5, cols1 = 6, rStart1 = 1, cStart1 = 4;
    std::vector<std::vector<int>> result1 = sol.spiralMatrixIII(rows1, cols1, rStart1, cStart1);
    std::cout << "Test case 1: " << std::endl;
    printResult(result1);

    // Test case 2
    int rows2 = 1, cols2 = 4, rStart2 = 0, cStart2 = 0;
    std::vector<std::vector<int>> result2 = sol.spiralMatrixIII(rows2, cols2, rStart2, cStart2);
    std::cout << "Test case 2: " << std::endl;
    printResult(result2);

    // Test case 3
    int rows3 = 3, cols3 = 3, rStart3 = 0, cStart3 = 0;
    std::vector<std::vector<int>> result3 = sol.spiralMatrixIII(rows3, cols3, rStart3, cStart3);
    std::cout << "Test case 3: " << std::endl;
    printResult(result3);

    return 0;
}
