// Solution 1 - TOO SLOW (O(kn) time)
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        auto left = int{0};
        auto flips = int{0};
        while (left < nums.size()) {
            // std::cout << "index " << left << "\n";
            if (nums[left] == 1) {
                left++;
                continue;
            }

            // std::cout << "limit = " << left + k - 1 << "\n";
            if (left + k - 1 >= nums.size()) break;
            for (auto i = 0; i < k; i++) {
                // std::cout << "curr: " << nums[left + i] << "\n";
                nums[left + i] = (nums[left + i] + 1) % 2;
            }
            flips++;
            left++;
        }

        for (auto i = nums.size() - k + 1; i < nums.size(); ++i) {
            if (nums[i] == 0) return -1;
        }

        return flips;
    }
};


// Solution 2
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> flipped(n, 0);
        int flips = 0;
        int flipCount = 0;
        
        for (int i = 0; i < n; i++) {
            // if statement effects all elements outside of the original window
            if (i >= k) {
                // decrement the flipCount if the current sliding window has been flipped
                flipCount -= flipped[i - k];
            }

            // if current number is a 0 (ie needs to be flipped)
            if ((nums[i] + flipCount) % 2 == 0) {
                // if there isn't enough room for a window and there's still 0's left in the array
                if (i + k > n) return -1;
                // current element has now been flipped
                // increment number of elements flipped
                // increment total number of flips
                flipped[i] = 1;
                flipCount++;
                flips++;
            }
        }
        
        return flips;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
