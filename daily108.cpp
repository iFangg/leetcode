// Solution 1 - FAIL
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        /*
        brute force:
            at least n^2
            remove element by element, then two element by two element, then three ...
            until you find the smallest subarray
            return such subarray

        recursive backtracking solution:
            try removing one element
            if removed element makes sum less than p, try another element
            if r.e makes sum greater than p, recurse without that element in next stage
            if equal, return amount of removed elements
          INCORRECT

        sliding window
        */
        p_ = p;
        nums_ = nums;
        size_ = nums.size();
        auto sum = std::accumulate(nums.begin(), nums.end(), 0);

        bt(sum);

        return min_sub_;
    }

private:
    void bt(int curr_sum) {
        std::cout << "curr sum is " << curr_sum << ", with " << nums_.size() << " numbers in the array" << std::endl;
        if (curr_sum <= 0 or nums_.size() == 1)
            return;

        if (curr_sum % p_ == 0) {
            if (nums_.size() == size_)
                min_sub_ = 0;
            else
                min_sub_ = std::min(min_sub_, static_cast<int>(size_ - nums_.size()));
            
            return;
        }

        for (auto n = nums_.begin(); n != nums_.end();) {
            auto value = *n;
            auto remainder = curr_sum - value;
            n = nums_.erase(n);
            bt(remainder);
            nums_.push_back(value);
        }
    }

    int p_;
    int size_;
    std::vector<int> nums_;
    int min_sub_ = -1;
};


// Solution 2
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for (int num : nums) sum += num;
        int target = sum % p;
        if (target == 0) return 0;
        
        unordered_map<int, int> last_occurrence;
        last_occurrence[0] = -1;
        int min_length = nums.size();
        long long current_sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            current_sum += nums[i];
            int remainder = current_sum % p;
            int complement = (remainder - target + p) % p;
            
            if (last_occurrence.count(complement)) {
                min_length = min(min_length, i - last_occurrence[complement]);
            }
            
            last_occurrence[remainder] = i;
        }
        
        return min_length < nums.size() ? min_length : -1;
    }
};
