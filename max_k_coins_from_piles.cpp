// Solution 1
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        auto n = piles.size();
        auto dp = std::vector<std::vector<int>>{n + 1, std::vector<int>(k + 1, 0)};
        for (int i = 0; i < n; ++i) {
            for (int coins = 0; coins <= k; ++coins) {
                int current_sum = 0;
                for (int j = 0; j <= piles[i].size() && j <= coins; ++j) {
                    if (j > 0) {
                        current_sum += piles[i][j - 1];
                    }
                    dp[i + 1][coins] = max(dp[i + 1][coins], dp[i][coins - j] + current_sum);
                }
            }
        }

        return dp[n][k];
    }
};


// Solution 2

