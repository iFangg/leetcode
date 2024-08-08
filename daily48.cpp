// Solution 1
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // make the sums array and find sum of subarray from l to r
        // 
        // we want the l-th smallest sum summed up to the r-th smallest sum
        auto sums = std::vector<int>{};

        for (auto i = 0; i < nums.size(); ++i) {
            auto sub_sum = 0;
            for (auto j = i; j < nums.size(); ++j) {
                sub_sum += nums[j];
                sums.push_back(sub_sum);
            }
        }

        std::sort(sums.begin(), sums.end());
        auto index = left - 1;
        auto sum = 0;

        while (index < right) {
            sum += sums[index];
            sum %= 1000000007;

            ++index;
        }

        return static_cast<int>(sum);
    }
};


// Solution 2
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long result =
            (sumOfFirstK(nums, n, right) - sumOfFirstK(nums, n, left - 1)) %
            mod;
        // Ensure non-negative result
        return (result + mod) % mod;
    }

private:
    int mod = 1e9 + 7;
    // Helper function to count subarrays with sum <= target and their total
    // sum.
    pair<int, long long> countAndSum(vector<int>& nums, int n, int target) {
        int count = 0;
        long long currentSum = 0, totalSum = 0, windowSum = 0;
        for (int j = 0, i = 0; j < n; ++j) {
            currentSum += nums[j];
            windowSum += nums[j] * (j - i + 1);
            while (currentSum > target) {
                windowSum -= currentSum;
                currentSum -= nums[i++];
            }
            count += j - i + 1;
            totalSum += windowSum;
        }
        return {count, totalSum};
    }

    // Helper function to find the sum of the first k smallest subarray sums.
    long long sumOfFirstK(vector<int>& nums, int n, int k) {
        int minSum = *min_element(nums.begin(), nums.end());
        int maxSum = accumulate(nums.begin(), nums.end(), 0);
        int left = minSum, right = maxSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (countAndSum(nums, n, mid).first >= k)
                right = mid - 1;
            else
                left = mid + 1;
        }
        auto [count, sum] = countAndSum(nums, n, left);
        // There can be more subarrays with the same sum of left.
        return sum - left * (count - k);
    }
};
