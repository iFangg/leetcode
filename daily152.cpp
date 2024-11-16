// Solution 1
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        /*
        can keep prefix sum for consecutiveness and sortedness
        consecutiveness, con[i] = nums[i] - nums[i - 1] == 1
        sortedness, srt[i] = nums[i] >= nums[i - 1]
        do both in one?
            con_srt[i] = (nums[i] - nums[i - 1] == 1)
            since this implies nums[i] > nums[i - 1]
            within each cycle!
        sliding window
            update max as the window slides
            udpate consecutiveness
            update sortedness
            ==>
        */
        auto res = std::vector<int>(nums.size() - k + 1);
        auto con_srt = std::vector<bool>(nums.size(), 0);
        con_srt[0] = 1;

        // std::cout << con_srt[0] << " ";
        for (auto i = 1; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == 1)
                con_srt[i] = 1;
            else
                con_srt[i] = 0;
            
            // std::cout << con_srt[i] << " ";
        }

        auto l = 0;
        auto r = k;

        for (auto i = 0; i < res.size(); i++) {
            auto power = -1;
            for (auto j = l; j < r; ++j) {
                if (!con_srt[j] and j != l) {
                    power = -1;
                    break;
                }
                
                power = std::max(power, nums[j]);
            }

            res[i] = power;
            ++l;
            ++r;
        }

        return res;
    }
};


// Solution 2
// DEQUEs EXIST!!
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // Get the length of the input array
        int len = nums.size();
        
        // Initialize the result vector with size (len - k + 1) filled with -1
        // This will store the required output
        vector<int> res(len - k + 1, -1);
        
        // Initialize a deque to keep track of indices in the current window
        deque<int> indexDeque;

        // Iterate through each index of the input array
        for (int i = 0; i < len; i++) {
            
            // Remove indices from the deque that are outside the current window
            if (!indexDeque.empty() && indexDeque.front() < i - k + 1) {
                indexDeque.pop_front();
            }

            // Clear the deque if the current value is not part of an incrementing sequence
            if (!indexDeque.empty() && nums[i] != nums[i - 1] + 1) {
                indexDeque.clear();
            }

            // Add the current index to the deque
            indexDeque.push_back(i);

            // Once the window reaches size k, evaluate the current window
            if (i >= k - 1) {
                // Check if the deque size equals k (valid incrementing sequence exists)
                if (indexDeque.size() == k) {
                    // Store the last element in the result array
                    res[i - k + 1] = nums[indexDeque.back()];
                }
            }
        }

        // Return the resulting array
        return res;
    }
};
