#include <vector>
#include <string>

// Solution 1
class Solution {
public:
    int strangePrinter(std::string s) {
        s_ = s;
        dp_ = std::vector<std::vector<int>>(s.size(), std::vector<int>(s.size(), -1));

        return find_min_prints(0, s.size() - 1);
    }

private:
    int find_min_prints(int i, int j) {
        if (i > j)
            return 0;
        
        if (dp_[i][j] != -1)
            return dp_[i][j];
        
        auto ans = 1 + find_min_prints(i + 1, j);
        for (auto k = i + 1; k <= j; ++k) {
            if (s_[k] == s_[i]) {
                auto better = find_min_prints(i, k - 1) + find_min_prints(k + 1, j);
                ans = std::min(ans, better);
            }
        }

        dp_[i][j] = ans;

        return dp_[i][j];
    }

    std::string s_;
    std::vector<std::vector<int>> dp_;
};
