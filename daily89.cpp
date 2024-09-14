// Solution 1 - FAIL
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        /*
        prefix sum of ands
        sliding window to find max subarray len
        start with left = 0 right = nums len
        */
        auto largest = *std::max_element(nums.begin(), nums.end());
        auto max = 1;

        auto left = 0;
        while (left < nums.size()) {
            auto result = nums[left];
            auto len = 1;

            for (auto i = left + 1; i < nums.size(); ++i) {
                std::cout << "current elem is " << nums[i] << ", index: " << i << std::endl;
                std::cout << "current AND streak gives: " << result << std::endl;
                if (result == largest) {
                    max = std::max(max, len + 1);
                }
                
                result = result & nums[i];
                len++;
            }

            ++left;
        }

        return max;
    }
}


// Solution 2 - FAIL
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Find the largest element in the array
        int largest = *std::max_element(nums.begin(), nums.end());
        int maxLen = 0;

        int left = 0;
        while (left < nums.size()) {
            // Skip elements that are not equal to the largest element
            if (nums[left] != largest) {
                ++left;
                continue;
            }
            
            // Start a sliding window where all elements AND to largest
            int result = nums[left];
            int len = 1;

            for (int i = left + 1; i < nums.size(); ++i) {
                result = result & nums[i];
                if (result < largest) {
                    break; // No point in continuing since AND will only get smaller
                }
                len++;
            }

            // Update the max length of the subarray found
            maxLen = std::max(maxLen, len);
            
            ++left;
        }

        return maxLen;
    }
};


// Solution 3
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Step 1: Find the largest element in the array
        int largest = *std::max_element(nums.begin(), nums.end());
        
        // Step 2: Traverse and find the longest contiguous subarray of largest element
        int maxLen = 0;
        int currentLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == largest) {
                // If current element is the largest, increment the current subarray length
                currentLen++;
            } else {
                // If not, compare and reset current length
                maxLen = std::max(maxLen, currentLen);
                currentLen = 0; // reset for the next potential subarray
            }
        }

        // Compare one last time in case the array ends with the longest subarray
        maxLen = std::max(maxLen, currentLen);

        return maxLen;
    }
};

