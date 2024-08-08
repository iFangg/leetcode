// Solution 1
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;  // If there are 4 or fewer elements, we can make all of them the same
        
        std::sort(nums.begin(), nums.end());
        
        // We need to consider changing up to three largest or smallest numbers
        int n = nums.size();
        int result = INT_MAX;
        
        // We have four possibilities:
        // 1. Change three largest numbers
        // 2. Change two largest and one smallest
        // 3. Change one largest and two smallest
        // 4. Change three smallest numbers
        
        result = std::min(result, nums[n-4] - nums[0]);
        result = std::min(result, nums[n-3] - nums[1]);
        result = std::min(result, nums[n-2] - nums[2]);
        result = std::min(result, nums[n-1] - nums[3]);
        
        return result;
    }
};


// Solution 2
static int _ = [](){ std::ios_base::sync_with_stdio(false); 
        std::cin.tie(nullptr); return 0;}();
class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) {
            return 0;
        }

        std::nth_element(nums.begin(), nums.begin() + 4, nums.end());
        std::nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        std::sort(nums.begin(), nums.begin() + 4);
        std::sort(nums.end() - 4, nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            //std::cout << nums[i] << " ";
        }

        int min = INT_MAX;
        for (int left = 0; left <= 3; ++left) {
            int right = 3 - left;
            min = std::min(min, std::abs(nums[nums.size() - 1 - right] - nums[left]));
        }

        return min;
    }
};

/*
0,1,5,10,14

10,14  4
5,10   5
1,5   4
0,1   1




*/
