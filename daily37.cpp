// Solution 1
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto num_mapping = std::unordered_map<int, int>{};
        for (auto i = 0; i < mapping.size(); ++i) {
            num_mapping[i] = mapping[i];
        }

        auto get_map = [&num_mapping](int num) {
            auto mapped = 0;
            auto tens = 1;
            auto n = std::to_string(num);
            std::cout << n << std::endl;
            for (auto i = static_cast<int>(n.size() - 1); i >= 0; --i) {
                mapped += tens * (num_mapping[n[i] - '0']);
                tens *= 10;
            }

            return mapped;
        };

        auto mapped_nums = std::unordered_map<int, int>{};
        for (auto i = 0; i < nums.size(); ++i) {
            mapped_nums[nums[i]] = get_map(nums[i]);
        }

        std::sort(nums.begin(), nums.end(), [&mapped_nums](int a, int b) {
            return mapped_nums[a] < mapped_nums[b];
        });

        return nums;
    }
};

// Solution 2
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> storePairs;

        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0;
            int temp = nums[i];
            // Start making changes from the units place.
            int place = 1;
            // If the value initially is 0, return mapping[0] and index.
            if (temp == 0) {
                storePairs.push_back({mapping[0], i});
                continue;
            }
            // Repeat the process for units, tenths, hundredths.. places.
            while (temp != 0) {
                mappedValue = place * mapping[temp % 10] + mappedValue;
                place *= 10;
                temp /= 10;
            }
            storePairs.push_back({mappedValue, i});
        }

        // Sort the array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]);
        }
        return answer;
    }
};
