#include "daily64_solution.h"

#include <iostream>
#include <vector>

int main() {
    Solution sol;

    // auto test = std::vector<int>{2, 7, 9, 4, 4};
    auto test = std::vector<int>{3111,4303,2722,2183,6351,5227,8964,7167,9286,6626,2347,1465,5201,7240,5463,8523,8163,9391,8616,5063,7837,7050,1246,9579,7744,6932,7704,9841,6163,4829,7324,6006,4689,8781,621};

    std::cout << "Max stones attainable by Alice is: " << sol.stoneGameII(test) << std::endl;

    return 0;
};
