// Solution 1
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        auto frequency = std::unordered_map<int, int>{};
        for (auto& n : nums) {
            if (!frequency.contains(n))
                frequency[n] = 0;

            frequency[n]++;
        }

        std::sort(nums.begin(), nums.end(), [&frequency](int a, int b) {
            if (frequency[a] == frequency[b])
                return a > b;
            
            return frequency[a] < frequency[b];
        });

        return nums;
    }
};

