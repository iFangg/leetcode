// Solution 1 - FAIL
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        /*
        prefix sum
        sliding window + deque
        */

        auto n = nums.size();
        auto prefix = std::vector<int>(n, 0);
        prefix[0] = nums[0];
        
        for (auto i = 1; i < n; ++i) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        auto shortest = INT_MAX;
        auto dq = std::deque<int>{};

        for (auto i = 0; i < n; ++i) {
            while (!dq.empty() and prefix[i] - prefix[dq.front()] >= k) {
                shortest = std::min(shortest, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() and prefix[i] <= prefix[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};


// Solution 2
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long curSum = 0;
        deque<pair<long long, int>> q;  // (prefix_sum, end_idx)
        
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            
            if (curSum >= k) {
                res = min(res, r + 1);
            }
            
            // Find the minimum valid window ending at r
            while (!q.empty() && curSum - q.front().first >= k) {
                auto [prefix, endIdx] = q.front();
                q.pop_front();
                res = min(res, r - endIdx);
            }
            
            // Validate the monotonic deque
            while (!q.empty() && q.back().first > curSum) {
                q.pop_back();
            }
            q.push_back({curSum, r});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};
