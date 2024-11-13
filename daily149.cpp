// Solutiuon 1 - FAIL
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        /*
        sort
        two pointer approach
        start with left and right
        if left + right > upper, right --
        if left + right < lower, left ++
        else total ++
        return total
        */
        std::sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        long long total = 0;

        while (r >= 0) {
            std::cout << l << " - " << r << std::endl;
            if (l >= r) {
                r--;
                l = 0;
                continue;
            }

            auto sum = nums[l] + nums[r];

            if (sum > upper) {
                r--;
                l = 0;
            } else if (sum < lower)
                l++;
            else {
                l++;
                total++;
            }
        }

        return total;
    }
};


// Solution 2 - FAIL
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        /*
        sort
        two pointer approach
        start with left and right
        if left + right > upper, right --
        if left + right < lower, left ++
        else total ++
        NO

        BINARY SEARCH
        keep mid point
        if left + right > upper, right = mid - 1
        if left + right < lower, left = mid + 1
        else add (right - left)
        return total
        */
        std::sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            std::cout << l << " - " << r << std::endl;
            auto sum = nums[l] + nums[r];
            auto mid = l + (r - l) / 2;

            if (sum > upper)
                r = mid;
            else if (sum < lower)
                l = mid;
            else
                return r - l;
        }

        return 0;
    }
}


// Solution 3
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long total = 0;

        // i is the number in the index we are finding pairs for
        // we then find pairs of (i, n) using binary search to find how many pairs exist using start index i
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1;
            int r = nums.size() - 1;

            // Find the first position where nums[i] + nums[l] >= lower
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] >= lower) 
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
            int leftBound = l;

            // Find the first position where nums[i] + nums[l] > upper
            l = i + 1;
            r = nums.size() - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[i] + nums[mid] > upper) 
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
            int rightBound = r;

            // Count pairs in range
            if (leftBound <= rightBound)
                total += rightBound - leftBound + 1;
        }
        return total;
    }
};
