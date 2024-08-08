// Solution 1 - 18/6/24
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        auto diff_prof_pairs = std::vector<std::pair<int, int>>{};
        for (auto i = size_t{0}; i < difficulty.size(); ++i) {
            diff_prof_pairs.emplace_back(difficulty[i], profit[i]);
        }
        std::sort(diff_prof_pairs.begin(), diff_prof_pairs.end());
        std:sort(worker.begin(), worker.end());

        auto max_profit = int{0};
        auto job = int{0};
        auto total = int{0};
        for (auto w = size_t{0}; w < worker.size(); ++w) {
            while (job < diff_prof_pairs.size() && diff_prof_pairs[job].first <= worker[w]) {
                max_profit = std::max(max_profit, diff_prof_pairs[job].second);
                job++;
            }
            
            total += max_profit;
        }

        return total;
    }
};

