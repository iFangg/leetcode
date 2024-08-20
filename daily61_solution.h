#include <vector>
#include <iostream>

class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        auto results = std::vector<long long>(points[0].size(), 0);

        for (auto c = 0; c < points[0].size(); ++c) {
            std::cout << "starting point is " << points[0][c] << std::endl;
            auto sum = points[0][c];
            results[c] = find_maxPoints(points, 0, c, sum);
        }

        return *std::max_element(results.begin(), results.end());
    }

 private:
    long long find_maxPoints(std::vector<std::vector<int>>& points, int row, int prev_col, long long sum) {
        std::cout << "current sum is " << sum << std::endl;
        if (row + 1 >= points.size())
            return sum;
        
        long long curr_max = 0;
        auto results = std::vector<long long>{};
        for (auto c = 0; c < points[0].size(); ++c) {
            std::cout << "different in columns: " << prev_col << " - " << c << std::endl;
            auto result = sum + points[row + 1][c] - std::abs(prev_col - c);
            results.push_back(result);
        }

        for (auto i = 0; i < results.size(); ++i) {
            if (results[i] > curr_max) {
                curr_max = results[i];
                prev_col = i;
            }
        }
        std::cout << "next biggest sum is at: " << points[row + 1][prev_col] << std::endl;

        return find_maxPoints(points, row + 1, prev_col, curr_max);
    }
};