// Solution 1 - FAIL
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        /*

        any element i from index 0 to n - 1
         that are greater than i + 1 should be removed
        any element i from index n - 1 to 0
         that are greater than i - 1 shuold be removed 
        */
        auto removed = 0;
        auto half = nums.size() % 2 == 0 ? nums.size() / 2 - 1 : nums.size() / 2;
        int l = 1;

        while (l < nums.size() - 1) {
            if (nums[l] <= nums[l - 1] and l <= half) {
                removed++;
                half++;
                std::cout << "incorrect 1st half\n";
            }
            
            if (nums[l] <= nums[l + 1] and l >= half) {
                removed++;
                std::cout << "incorrect 2nd half\n";
            }

            ++l;
        }

        return removed;
    }
};


// Solution 2
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        auto lis = std::vector<int>(nums.size(), 1);
        auto lds = std::vector<int>(nums.size(), 1);
        auto n = nums.size();

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = std::max(lis[i], lis[j] + 1);
                }
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = std::max(lds[i], lds[j] + 1);
                }
            }
        }

        int max_len = 0;
        
        for (auto i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 and lds[i] > 1) {
                int mount_len = lis[i] + lds[i];
                max_len = std::max(max_len, mount_len - 1);
            }
        }

        return nums.size() - max_len;
    }
};
