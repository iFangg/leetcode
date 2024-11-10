// Solution 1 - FAIL
class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        /*
        sliding window
        increase the right bound when OR sum is < k
        increase left bound when OR sum is >= k
        */

        auto n = nums.size();
        auto l = 0;
        auto r = 1;
        auto or_sum = nums[0];
        auto bits = std::vector<int>(32);
        while (l < n and l <= r) {
            set_bits(or_sum);
            if (or_sum < k)
                r++;
            else
                l++;
        }

        return 0;
    }

private:
    void set_bits(int num, std::vector<int>& bits) {
        auto mask = 1;
        for (auto i = 0; i < 32; ++i) {
            auto bit_ = num & 1;
            bits[i] += bit_;
            mask <<= 1;
        }
    }
}


// Solution 2
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

class Solution {
public:
    // Main function to find the minimum length of a subarray with OR >= k
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> count(32, 0);  // Bit counts for the current subarray (32 bits for 32-bit integers)
        int start = 0, end = 0;    // Pointers for the sliding window (start and end indices)
        int minLength = INT_MAX;   // Initialize minimum length to a large number

        // Extend the window by moving 'end' through each element in nums
        while (end < nums.size()) {
            // Include nums[end] in the current window by updating bit counts
            updateBits(count, nums[end], 1);

            // While the current window's OR is >= k, try to shrink the window from the left
            while (start <= end && getVal(count) >= k) {
                // Update minLength if the current window is the smallest valid one found
                minLength = min(minLength, end - start + 1);

                // Remove nums[start] from the current window by updating bit counts
                updateBits(count, nums[start], -1);
                start++; // Move the start pointer to the right
            }
            // Move the end pointer to the right to expand the window
            end++;
        }

        // If no valid subarray was found, return -1; otherwise, return the minimum length found
        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    // Updates the 'count' array based on the bits of 'num' (add if val = 1, remove if val = -1)
    void updateBits(vector<int>& count, int num, int val) {
        // Check each bit position from 0 to 31
        for (int i = 0; i < 32; i++) {
            // If the i-th bit in 'num' is set to 1
            if ((num >> i) & 1) {
                // Adjust the count of that bit position (add 1 or subtract 1)
                count[i] += val;
            }
        }
    }

    // Computes the bitwise OR value of the current subarray based on 'count'
    int getVal(const vector<int>& count) {
        int ans = 0; // Result for the OR value of the current subarray
        // Check each bit position from 0 to 31
        for (int i = 0; i < 32; i++) {
            // If there is at least one 1 in the i-th position in the subarray
            if (count[i] > 0) {
                // Set the i-th bit in the result 'ans' to 1
                ans |= (1 << i);
            }
        }
        return ans; // Return the computed OR result
    }
};

