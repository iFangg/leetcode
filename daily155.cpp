// Solution 1 - FAIL
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        /*
        sliding window of length k
        prefix sum of whole array
        prefix sum for distinct numbers?
            bitset? or set works fine
            array for seen numbers
        keep tack of max sum
        */

        auto n = nums.size();
        auto prefix = std::vector<int>(n);
        prefix[0] = nums[0];

        for (auto i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        auto seen = std::vector<int>(100001);
        auto max_sum = 0;
        auto sum = 0;

        for (auto i = 0; i < n; ++i) {
            if (i < k) {
                seen[nums[i]] = 1;
                sum += nums[i];
            } else {
                seen[nums[i - k]] = 0;

                if (!seen[nums[i]]) {
                    seen[nums[i]] = 1;
                    sum = prefix[i] - prefix[i - k];
                }

                max_sum = std::max(max_sum, sum);
            }
        }

        return max_sum;
    }
};


// Solution 2
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long max_sum = 0, current_sum = 0;
        std::unordered_map<int, int> count; // Track the frequency of numbers in the current window
        int left = 0;

        for (int right = 0; right < n; ++right) {
            // Add the current number to the window
            current_sum += nums[right];
            count[nums[right]]++;

            // If the window size exceeds k, shrink it from the left
            while (right - left + 1 > k) {
                current_sum -= nums[left];
                count[nums[left]]--;
                if (count[nums[left]] == 0) {
                    count.erase(nums[left]);
                }
                left++;
            }

            // Check if the window has exactly k distinct elements
            if (right - left + 1 == k && count.size() == k) {
                max_sum = std::max(max_sum, current_sum);
            }
        }

        return max_sum;
    }
};


// Solution 3
class Solution {
private:
    long long sum = 0;
    int dupli = 0, cnt[100001] = {};
    void pushElement(int &num) {
        sum += num;
        if (++cnt[num] == 2) ++dupli;
    }
    void popElement(int &num) {
        sum -= num;
        if (--cnt[num] == 1) --dupli;
    }
        
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        for (int i = 0; i < k; ++i) pushElement(nums[i]);
        long long res = dupli ? 0 : sum;

        for (int i = 0; i < nums.size() - k; ++i) {
            popElement(nums[i]);
            pushElement(nums[i + k]);
            if (!dupli) res = max(res, sum);
        }

        return res;
    }
};
