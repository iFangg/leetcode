// Solution 1 - correct but quadratic time
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // keep track of start
        // iterate until we find a subarray of k odds
        // move lower bound until subarrays are no longer of k odds
        // add this count
        // increase upper bound
        auto count = long{0};
        auto odds = int{0};
        auto left = int{0};
        auto right = int{0};
        while (right < nums.size()) {
            if (nums[right] % 2 == 1) odds++;
            // std::cout << "current odd no's " << odds << "\n";
            auto curr_odds = odds;
            while (curr_odds >= k) {
                if (curr_odds == k) count++;
                curr_odds -= (nums[left] % 2);
                left++;
            }
            // std::cout << "total subarrays: " << count << "\n";
            left = 0;
            right++;
        }

        return count;
    }
};


// Solution 2
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      // keeps track of how often each prefix sum (number of odd numbers seen so far) has occurred
        unordered_map<int, int> prefixCount;
      // prefix = number of odd numbers encountered so far while iterating through the array.
        prefixCount[0] = 1;  // to handle the case when prefix sum is exactly k
        int currentOddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 == 1) {
                currentOddCount++;
            }

            if (prefixCount.find(currentOddCount - k) != prefixCount.end()) {
                result += prefixCount[currentOddCount - k];
            }

            prefixCount[currentOddCount]++;
        }

        return result;
    }
};
