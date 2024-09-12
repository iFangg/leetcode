// Solution 1
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        // alphabet map, 0 = doesn't exist, 1 = exists
        auto seen = std::vector<int>(26, 0);
        for (auto c : allowed) {
            seen[c - 'a'] = 1;
        }

        auto total = 0;
        for (auto s : words) {
            auto consistent = true;
            for (auto c : s) {
                if (!seen[c - 'a']) {
                    consistent = false;
                    break;
                }
            }

            total += consistent ? 1 : 0;
        }

        return total;
    }
};
