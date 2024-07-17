// Solution 1
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // Number of piles
        auto n = piles.size();
        
        // dp[i][j] will store the maximum value obtainable using the first i piles with exactly j coins
        auto dp = std::vector<std::vector<int>>(n + 1, std::vector<int>(k + 1, 0));

        // Iterate through each pile
        for (int i = 0; i < n; ++i) {
            // Iterate through each possible number of coins
            for (int coins = 0; coins <= k; ++coins) {
                // To keep track of the sum of the first j coins taken from the current pile
                int current_sum = 0;

                // Iterate through the possible number of coins we can take from the current pile
                for (int j = 0; j <= piles[i].size() && j <= coins; ++j) {
                    // If we take j coins from the current pile, update current_sum
                    if (j > 0) {
                        current_sum += piles[i][j - 1];
                    }

                    // Update dp[i+1][coins] by taking the maximum of its current value and the value obtained
                    // by taking j coins from the current pile plus the value of the remaining coins from previous piles
                    dp[i + 1][coins] = max(dp[i + 1][coins], dp[i][coins - j] + current_sum);
                }
            }
        }

        // Return the maximum value obtainable with exactly k coins using all piles
        return dp[n][k];
    }
};





// -----------------------------------------------------------------------------------
// This is a lambda function that improves I/O performance for competitive programming
auto init = []() {
    ios::sync_with_stdio(0); // Disable synchronization with C stdio
    cin.tie(0); // Untie cin from cout, enabling faster input
    cout.tie(0); // Untie cout from cin, enabling faster output
    return 'c'; // Dummy return value to execute the lambda function
}();

