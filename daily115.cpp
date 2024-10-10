// Solution 1 - FAIL
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        /*
         n^2:
            brute force, test every possible ramp width and return max
        
        n:
            start with left and right pointers
            if left num is greater than right num, left++
                if right - 1 is >= new left, move right?
            else return right - left?
        */
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            // std::cout << nums[left] << " - " << nums[right] << std::endl;
            if (nums[left] > nums[right]) {
                if (nums[left] <= nums[right - 1])
                    --right;
                else
                    ++left;
            } else
                return right - left;
        }

        return 0;
    }
};


// Solution 2
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        auto indices = std::vector<int>(nums.size());
        for (auto i = 0; i < nums.size(); ++i) {
            indices[i] = i;
        }

        std::sort(indices.begin(), indices.end(), [&nums](int a, int b) {
            return nums[a] < nums[b] || (nums[a] == nums[b] && a < b);
        });

        int min_index = nums.size();
        int max_width = 0;

        for (auto i = 0; i < nums.size(); ++i) {
            max_width = std::max(max_width, indices[i] - min_index);
            min_index = std::min(min_index, indices[i]);
        }

        return max_width;
    }
};

// Solution 3
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {nums[i], i};
        }
        
        sort(pairs.begin(), pairs.end());
        
        int max_width = 0;
        int min_index = n;
        
        for (const auto& [value, index] : pairs) {
            max_width = max(max_width, index - min_index);
            min_index = min(min_index, index);
        }
        
        return max_width;
    }
};

