// Solution 1 - FAIL
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // determine if the 1's are currently grouped
            // save total number of 1's and 0's
        // swap occurs when there is a gap in between consecutive 1's
        auto zeroes = std::count(nums.begin(), nums.end(), 0);

        // iterate through the array, find smallest distance between groups of ones
        // every 2 groups is 1 necessary swap
        // first change is when you start counting
        // find first instance of one, start counting groups of 0s from then on
        int i = 0;
        while (nums[i] == 0)
            ++i;
        
        auto group_sizes = std::unordered_map<int, int>{};
        int seen_zeroes = 0;
        while (seen_zeroes < zeroes) {
            while (nums[i] == 1)
                i = (i + 1) % nums.size();
            
            int gap = 0;
            while (nums[i] == 0) {
                ++seen_zeroes;
                ++gap;
                i = (i + 1) % nums.size();
            }

            if (!group_sizes.count(gap))
                group_sizes[gap] = 0;
            
            group_sizes[gap]++;
        }

        // if two gaps appear the same amount of times, add the lower gap
        auto min_swaps = std::unordered_map<int, int>{};
        for (auto& [g, c] : group_sizes) {
            if (!min_swaps.count(c))
                min_swaps[c] = g;
            
            min_swaps[c] = std::min(min_swaps[c], g);
        }

        auto swaps = 0;
        for (auto& [c, g] : min_swaps) {
            // occured once, add once
            // occured twice, add once
            // occured three times, add twice
            // occurred four times, add twice
            std::cout << g << " 0's in a row, occured " << c << " times\n";
            if (c / 2 == 0)
                swaps += g;
            else
                swaps += g * std::ceil(c / 2);
        }

        return swaps;
    }
};


// Solution 2
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int count = accumulate(nums.begin(), nums.begin() + k, 0);
        int max = count;
        for (int i = k; i < n + k; ++i) {
            count += nums[i % n] - nums[(i - k + n) % n];
            max = std::max(max, count);
        }
        return k - max;
    }
};
