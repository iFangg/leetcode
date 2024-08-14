#include <vector>
#include <queue>

// Solution 1 - FAIL too slow
class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        // sort and then max heap for differences?
        // std::sort(nums.begin(), nums.end());

        auto distances = std::priority_queue<int, std::vector<int>>{};
        auto count = 0;
        auto left = 0;
        auto right = 1;
        while (left < nums.size()) {
            if (right >= nums.size()) {
                left++;
                right = left + 1;
            }

            if (right == nums.size())
                break;

            distances.push(std::abs(nums[left] - nums[right]));

            if (distances.size() > k)
                distances.pop();

            right++;
        }

        return distances.top();
    }
};


// Solution 2
#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countPairs(nums, mid) < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
    }

private:
    int countPairs(const std::vector<int>& nums, int distance) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count += std::upper_bound(nums.begin() + i, nums.end(), nums[i] + distance) - (nums.begin() + i + 1);
        }
        return count;
    }
};

