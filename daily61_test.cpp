#include "daily61_solution.h"

#include <vector>
#include <iostream>

int main() {
    Solution sol;
    std::vector<std::vector<int>> points = {
        {1, 2, 3},
        {1, 5, 1},
        {3, 1, 1}
    };

    int result = sol.maxPoints(points);
    std::cout << "The maximum number of points you can achieve is: " << result << std::endl;

    return 0;
}