#include "daily57_solution.h"
#include <iostream>

void printResult(const std::vector<std::vector<int>>& results) {
    for (const auto& combination : results) {
        std::cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            std::cout << combination[i];
            if (i < combination.size() - 1) std::cout << ",";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    Solution solution;
    std::vector<int> candidates = {8, 7, 4, 3};
    int target = 11;

    std::vector<std::vector<int>> result = solution.combinationSum2(candidates, target);

    std::cout << "Output:" << std::endl;
    printResult(result);

    return 0;
}