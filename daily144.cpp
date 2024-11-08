// Solution 1 - FAIL
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        /*
        count set bits of all numbers?
        find max bit = 2 ^ maxBit
        store max index after every query

        */

        int max_bit = std::pow(2, maximumBit);
        int idx = nums.size() - 1;
        auto xors = std::vector<int>(nums.size());

        for (auto i = 0; i < nums.size(); ++i) {
            auto val = nums[0];
            for (auto j = 1; j <= idx; ++j) {
                val ^= nums[j];
            }

            auto res = val ^ (max_bit - 1);
            while (res >= max_bit) {
                --res;
            }

            xors[i] = res;
            --idx;
        }

        return xors;
    }
};


// Solution 2
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        /*
        count set bits of all numbers?
        find max bit = 2 ^ maxBit
        store max index after every query

        */

        int max_bit = std::pow(2, maximumBit);
        int idx = nums.size() - 1;
        auto xors = std::vector<int>(nums.size());

        auto val = nums[0];
        for (auto j = 1; j < nums.size(); ++j) {
            val ^= nums[j];
        }
        
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i != nums.size() - 1)
                val ^= nums[i + 1];

            auto res = val ^ (max_bit - 1);
            while (res >= max_bit) {
                --res;
            }

            xors[nums.size() - 1 - i] = res;
            --idx;
        }

        return xors;
    }
};
