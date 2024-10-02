// Solution 1
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        /*
        store copy of sorted array,
        map sorted array to ranks
        */
        auto sorted = arr;

        std::sort(sorted.begin(), sorted.end());

        auto rank_num = std::unordered_map<int, int>{};
        auto rank = 1;

        for (auto i = 0; i < arr.size(); ++i) {
            if (i == 0 or sorted[i] != sorted[i - 1]) {
                rank_num[sorted[i]] = rank;
                rank++;
            }
        }

        auto res = std::vector<int>(arr.size());
        for (auto i = 0; i < arr.size(); ++i) {
            res[i] = rank_num[arr[i]];
        }

        return res;
    }
};

// Solution 2
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()) return {};

        // Find min and max values
        auto [min_it, max_it] = minmax_element(arr.begin(), arr.end());
        int min_val = *min_it;
        int max_val = *max_it;

        // Create a count array
        int range = max_val - min_val + 1;
        if (range > 2'000'000) {
            // Fall back to sorting method if range is too large
            return sortingMethod(arr);
        }

        vector<bool> count(range, false);
        for (int num : arr) {
            count[num - min_val] = true;
        }

        // Calculate ranks
        vector<int> ranks(range);
        int rank = 1;
        for (int i = 0; i < range; i++) {
            if (count[i]) {
                ranks[i] = rank++;
            }
        }

        // Assign ranks to original array
        for (int& num : arr) {
            num = ranks[num - min_val];
        }

        return arr;
    }

private:
    vector<int> sortingMethod(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        
        unordered_map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        
        vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            result[i] = rankMap[arr[i]];
        }
        
        return result;
    }
};
static const int kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
//KDS
