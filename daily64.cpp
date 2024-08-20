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
       // 
       return dp_alice(0, 1, piles);
    }
    
    int dp_alice(int i, int M, std::vector<int>& piles) {
        if (i >= piles.size() - 1)
            return piles[i];

        auto max_stones = 0;
        auto total = 0;
        for (auto x = 1; x <= 2 * M; ++x) {
            total += piles[i + x - 1];

            max_stones = std::max(max_stones, dp_bob(i + x, std::max(x, M), piles) + total);
        }

        return max_stones;
    }

    int dp_bob(int i, int M, std::vector<int>& piles) {
        if (i >= piles.size() - 1)
            return 0;

        auto min_stones = INT_MAX;
        for (auto x = 1; x <= 2 * M; ++x) {
            min_stones = std::min(min_stones, dp_alice(i + x, std::max(x, M), piles));
        }

        return min_stones;
    }    
};
