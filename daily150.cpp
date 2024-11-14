// Solution 1 - FAIL
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        /*
        sum of max quantities / n = target score
        for each quantity q
            take away target score until q = 0 or q < target score
            update max?
        */

        if (n == quantities.size())
            return *std::max_element(quantities.begin(), quantities.end());

        int sum = 0;
        auto target_score = std::ceil(std::accumulate(quantities.begin(), quantities.end(), 0) / static_cast<float>(n));

        return target_score;
    }
};


// Solution 2
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        n_ = n;
        qs = quantities;
        int l = 1;
        int r = *std::max_element(quantities.begin(), quantities.end()); 

        while (l < r) {
            auto mid = l + (r - l) / 2;

            if (canDistribute(mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

private:
    bool canDistribute(int x) {
        auto needed = 0;
        for (auto& q : qs) {
            needed += (q + x - 1) / x;  // This effectively does the ceiling without float division

            if (needed > n_) {
                return false;  // Early exit if we exceed available stores
            }
        }

        return needed <= n_;
    }
    int n_;
    std::vector<int> qs;
};
