// Solution 1 - FAIL
class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        /*
        so if there is a number on the left larger than a number on the right that does not have the same amount of bitsets, we can't sort the array
        make set bits array
        compare with above condition
        return false
            if current number is smaller than the local max and has different set bits
        
        consider case of setting the new max but following numbers cant be sorted with the previous sections

        partition into clusters of different set bits
        find ranges of each cluster
            if any clusters intersect, return false
        WRONG
        */
        auto set_bits = std::vector<int>(nums.size());
        auto n = nums.size();

        for (auto i = 0; i < n; ++i) {
            set_bits[i] = __builtin_popcount(nums[i]);
        }

        auto local_max = nums[0];
        auto local_bits = set_bits[0];
        for (auto i = 1; i < n; ++i) {
            std::cout << local_max << " - " << nums[i] << "\n";
            std::cout << "b" << local_bits << " - " << "b" << set_bits[i] << "\n";
            if (local_max > nums[i]) {
                if (set_bits[i] != local_bits)
                    return false;
                
            } else if (local_max < nums[i]) {
                local_max = nums[i];
                local_bits = set_bits[i];
            }
        }

        return true;
    }
};


// Solution 2
#include <vector>
#include <iostream>
#include <climits>

class Solution {
public:
    using int2 = std::pair<int, int>; // Define int2 as a shorthand for a pair of integers (min, max) for each segment

    bool canSortArray(std::vector<int>& nums) {
        int2 prev = {INT_MIN, INT_MIN}, curr; // `prev` stores the min and max of the previous segment; `curr` is for the current segment
        const int n = nums.size(); // Get the size of the array for convenience
        int prevBit = -1; // `prevBit` tracks the bit count of the previous segment; initialize to -1 for the first comparison

        // Iterate over each number in the array
        for (int i = 0; i < n; i++) {
            int x = nums[i];               // Current number
            int b = __builtin_popcount(x);  // Bit count of current number (number of 1s in binary representation)

            // Check if we've encountered a new segment (different bit count)
            if (prevBit != b) {
                // If current segment's minimum is less than the previous segment's maximum, sorting is impossible
                if (curr.first < prev.second) return false;

                // Transition to the new segment
                prev = curr;         // Update previous segment to be the current one
                curr = {x, x};       // Reset current segment to start with the new number
                prevBit = b;         // Update `prevBit` to the current bit count
            } else {
                // If still in the same segment (same bit count), update min and max for the current segment
                curr.first = std::min(curr.first, x);   // Update minimum of the current segment
                curr.second = std::max(curr.second, x); // Update maximum of the current segment
            }
        }

        // Final check: ensure the last segment does not violate sorting rules with the previous segment
        return curr.first >= prev.second;
    }
};

