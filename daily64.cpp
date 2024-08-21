#include <vector>

// Solution 1
#include <vector>

// Solution 1
class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        /*
        1 - A takes 1 to 2 piles
        if A take 1: M = max (1, 1)
        2 - B takes 1 to 2 piles
        if A takes 2: M = max(2,1)
        2 - B takes 1 to 4 piles
        ...

        how does alice ensure that she takes the most stones?
        alice takes the smallest number of bags until she can a big bag
        consider what happens if alice takes bag i for 1 <= i <= 2M
        dp(i) where i is the 2Mth bag = the max number of stones that can possibly be taken up to the ith bag (invalid?)

        dp(i, M) where i is the ith bag and 1 <= X <= 2M where X is the num. of bags we take
        dp(i, M) = max{dp(i + 1, M) + pile[i]} where M = upper limit of piles, X = number of piles (in order) we take
            once alice makes her turn, run separate dp algorithm for bob and vice versa
            haver boolean tracker for Alice/Bob turn
            returns max possible amount of stones achievable starting from i/ from i onwards

            _ _ _ _ _
        */

        piles_ = piles;

        for (int i = piles_.size() - 2; i >= 0; --i) {
            piles_[i] += piles_[i + 1];
        }

        dp_.resize(piles.size() + 1);
        for (auto& M : dp_) {
            M.resize(piles.size() + 1);
        }

        dp_b_.resize(piles.size() + 1);
        for (auto& M : dp_b_) {
            M.resize(piles.size() + 1);
        }

       return dp_alice(0, 1);
    }
    
    int dp_alice(int i, int M) {
        if (i + 2 * M  >= piles_.size()) {
            return piles_[i];
        }

        if (dp_[i][M - 1])
            return dp_[i][M - 1];

        int max_stones = 0;
        for (auto x = 1; i + x - 1 < piles_.size(); ++x) {
            max_stones = std::max(max_stones, dp_bob(i + x - 1, std::max(x, M)) + piles_[i + x - 1] - piles_[i]);
        }

        dp_[i][M - 1] = max_stones;
        return max_stones;
    }

    int dp_bob(int i, int M) {
        if (i + 2 * M  >= piles_.size()) {
            return 0;
        }

        if (dp_b_[i][M - 1])
            return dp_b_[i][M - 1];

        int min_stones = INT_MAX;
        for (auto x = 1; i + x - 1 < piles_.size(); ++x) {
            min_stones = std::min(min_stones, dp_alice(i + x - 1, std::max(x, M)));
        }

        dp_b_[i][M - 1] = min_stones;
        return min_stones;
    }    

private:
    std::vector<int> piles_;
    std::vector<std::vector<int>> dp_;
    std::vector<std::vector<int>> dp_b_;
};


// Solution 2
class Solution {
private:
    int helper(int i, int M, std::vector<int>& piles, std::vector<std::vector<int>>& dp, std::vector<int>& suffixSum) {
        int n = piles.size();

        // Base case: If we're at the last pile, return the sum of the remaining piles
        if (i >= n) {
            return 0;
        }
        // If we've already calculated this state, return the stored value
        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int maxStones = 0;

        // Try taking all possible X (1 <= X <= 2 * M)
        for (int X = 1; X <= 2 * M; ++X) {
            if (i + X > n) {
                break; // Don't go out of bounds
            }

            // Remaining stones after taking X piles
            int opponentScore = helper(i + X, std::max(M, X), piles, dp, suffixSum);

            // Maximum stones Alice can get if she takes X piles
            maxStones = std::max(maxStones, suffixSum[i] - opponentScore);
        }

        // Store and return the result for this state
        dp[i][M] = maxStones;
        return dp[i][M];
    }
    
public:
    int stoneGameII(std::vector<int>& piles) {
        int n = piles.size();
        // dp array to store the results
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, -1));
        // suffixSum to quickly compute the sum of remaining piles
        std::vector<int> suffixSum(n, 0);

        // Calculate the suffix sum
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }

        // Call the recursive helper function
        return helper(0, 1, piles, dp, suffixSum);
    }
};
