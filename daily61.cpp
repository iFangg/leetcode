#include <vector>
#include <iostream>

// Solution 1 - Fail
class Solution {
public:
    long long maxPoints(std::vector<std::vector<int>>& points) {
        auto index = points.size() - 1;
        auto results = std::vector<long long>(points[0].size(), 0);

        for (auto c = 0; c < points[0].size(); ++c) {
            results[c] = find_maxPoints(points, index, c);
        }

        return *std::max_element(results.begin(), results.end());
    }

 private:
    long long find_maxPoints(std::vector<std::vector<int>>& points, int row, int prev_col) {
        if (row == -1)
            return 0;
        
        long long curr_max = 0;
        for (auto c = 0; c < points[0].size(); ++c) {
            curr_max = std::max(curr_max, points[row][c] - std::abs(c - prev_col) + find_maxPoints(points, row - 1, c));
        }

        return curr_max;
    }
};


// Solution 2
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<long long> dp(col, 0);
        
        for(int i = 0; i < col; i++) {
            dp[i] = points[0][i];
        }
        
        for(int r = 1; r < row; r++) {
            vector<long long> leftMax(col, 0), rightMax(col, 0);
            vector<long long> newDp(col, 0);
            
            leftMax[0] = dp[0];
            for(int i = 1; i < col; i++) {
                leftMax[i] = max(leftMax[i-1], dp[i] + i);
            }
            
            rightMax[col-1] = dp[col-1] - (col-1);
            for(int i = col-2; i >= 0; i--) {
                rightMax[i] = max(rightMax[i+1], dp[i] - i);
            }
            
            for(int i = 0; i < col; i++) {
                newDp[i] = max(leftMax[i] - i, rightMax[i] + i) + points[r][i];
            }
            
            dp = newDp;
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};
