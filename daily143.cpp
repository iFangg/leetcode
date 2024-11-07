// Solution 1 - FAIL
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        /*
        backtracking solution
        testing which combination in array returns largest length
            have current index, seen indices, AND combination
            if combination becomes 0, recurse back out
        */
        candi_ = candidates;
        auto seen = std::vector<int>(candidates.size(), 0);
        backtrack(0, seen, -1, 0);

        return max_combo;
    }

private:
    void backtrack(int idx, std::vector<int>& seen, int combo, int len) {
        if (combo == 0) {
            max_combo = std::max(max_combo, len);
            return;
        }
        
        seen[idx] = 1;
        for (auto i = 0; i < candi_.size(); ++i) {
            if (seen[i])
                continue;
            
            combo = combo == -1 ? candi_[i] : combo;
            backtrack(i, seen, combo & candi_[i], len + 1);
        }

        max_combo = std::max(max_combo, len + 1);
    }

    std::vector<int> candi_;
    int max_combo = 0;
};


// Solution 2
class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int max_combo = 0;
        
        // Check each bit position from 0 to 31
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : candidates) {
                // Check if the `bit` position is set in `num`
                if (num & (1 << bit)) {
                    count++;
                }
            }
            // Keep track of the maximum count across all bit positions
            max_combo = std::max(max_combo, count);
        }
        
        return max_combo;
    }
};
