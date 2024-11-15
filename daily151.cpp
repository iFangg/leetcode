// Solution 1 - FAIL
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        /*
        start from the right and decrement
            count current subarray
        start counting removal subarray
            while num n < num n - 1
                removal subarray size ++
            
            shortest subarray = min(curr subarr, rem subarr)
        */

        auto subarr = INT_MAX;
        int curr_arr_len = 1;
        auto curr = arr.back();

        int i = arr.size() - 2;
        while (i >= 0) {
            if (curr > arr[i]) {
                curr_arr_len++;
                curr = arr[i];
                --i;
                continue;
            }

            int rem = 0;

            while (i >= 0 and curr <= arr[i]) {
                rem++;
                curr = arr[i];
                --i;
            }

            subarr = std::min(subarr, std::min(curr_arr_len, rem));
            curr_arr_len = 1;
        }

        return subarr;
    }
};


// Solution 2
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;

        // Find the longest non-decreasing prefix
        while (left < n - 1 && arr[left] <= arr[left + 1]) {
            left++;
        }

        // If the array is already sorted
        if (left == n - 1) return 0;

        // Find the longest non-decreasing suffix
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // Compute the minimum subarray to remove
        int result = std::min(n - left - 1, right);

        // Attempt to merge the prefix and suffix
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = std::min(result, j - i - 1); // Size of the middle subarray
                i++; // Move the prefix pointer forward
            } else {
                j++; // Move the suffix pointer forward
            }
      }
    }
};
