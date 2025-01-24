// Solution 1 - too slow
class Solution {
    private int min_jumps = Integer.MAX_VALUE;

    public int jump(int[] nums) {
        /*
            start from the back
            counter init at 0
            
            recursive solution
            for i = idx - 1; i >= 0; i--
                if number is geq to distance between i and curr idx,
                recurse
                else move on
            
            as we recurse, keep track of the number of jumps
                update for minimum number when we reach beginning (0 idx)
        */
        recurse(nums, nums.length - 1, 0);

        return min_jumps;
    }

    public void recurse(int[] nums, int idx, int curr_jumps) {
        if (idx == 0) {
            min_jumps = Math.min(min_jumps, curr_jumps);
            return;
        }

        for (int i = idx - 1; i >= 0; i--) {
            if (nums[i] >= idx - i) {
                recurse(nums, i, curr_jumps + 1);
            }
        }
    }
}


// Solution 2
class Solution {
    private int min_jumps = Integer.MAX_VALUE;

    public int jump(int[] nums) {
        /*
            start from the back
            counter init at 0
            
            recursive solution
            for i = idx - 1; i >= 0; i--
                if number is geq to distance between i and curr idx,
                recurse
                else move on
            
            as we recurse, keep track of the number of jumps
                update for minimum number when we reach beginning (0 idx)

        ________________

            dp solution
            dp(i) = minimum amount of jumps to reach index i
            dp 0 = 0
            
            for j = 1; j <= i; j++
                dp i = dp (i - j) + 1 if nums[j] >= i - j
        
        ________________

            greedy solution
            start at back
            find earliest point to jump from
                loop from i = 0 and find earliest point
        */
        recurse(nums, nums.length - 1, 0);

        return min_jumps;
    }

    public void recurse(int[] nums, int idx, int curr_jumps) {
        if (idx == 0) {
            min_jumps = Math.min(min_jumps, curr_jumps);
            return;
        }

        for (int i = 0; i < idx; i++) {
            if (nums[i] >= idx - i) {
                recurse(nums, i, curr_jumps + 1);
                break;
            }
        }
    }
}


// Solution 3
class Solution {

    // Main function to calculate the minimum number of jumps to reach the end.
    public int jump(int[] nums) {
        // Calls the helper function `jump` with initial parameters.
        return jump(nums, 0, 0, 0);
    }

    /**
     * Recursive approach to calculate the minimum number of jumps.
     *
     * @param nums Array of integers where each element represents the maximum jump length.
     * @param from Current start position.
     * @param to Maximum reachable index in the current jump.
     * @param jumpCount Number of jumps taken so far.
     * @return The minimum number of jumps to reach the end.
     */
    public int jump(int[] nums, int from, int to, int jumpCount) {
        int n = nums.length;
        // Base case: If the maximum reachable position `to` is at or beyond the last index.
        if (to >= n - 1) {
            return jumpCount;
        }

        // `nextTo` tracks the farthest reachable index in the next jump.
        int nextTo = -1;
        for (int i = from; i <= to; i++) {
            // Update `nextTo` to include the maximum distance reachable from index `i`.
            nextTo = Math.max(nextTo, nums[i] + i);
        }

        // Recursively call `jump` for the next range of indices with incremented jump count.
        return jump(nums, to + 1, nextTo, jumpCount + 1);
    }

    /**
     * Dynamic Programming approach to calculate the minimum number of jumps.
     *
     * @param nums Array of integers where each element represents the maximum jump length.
     * @return The minimum number of jumps to reach the end.
     */
    public int jump2(int[] nums) {
        int n = nums.length;
        // Initialize a DP array where dp[i] stores the minimum jumps needed to reach the end from index `i`.
        int[] dp = new int[n];
        // Fill with a large number (infinity) to represent uncalculated states.
        Arrays.fill(dp, 1_000_000_007);
        dp[n - 1] = 0; // Base case: 0 jumps needed from the last index.

        // Traverse the array in reverse to compute `dp[i]`.
        for (int i = n - 2; i >= 0; i--) {
            // Check all reachable positions from index `i` within `nums[i]` steps.
            for (int j = i + 1; j <= i + nums[i] && j < n; j++) {
                // Update `dp[i]` with the minimum jumps needed.
                dp[i] = Math.min(dp[i], 1 + dp[j]);
            }
        }
        return dp[0]; // Return the minimum jumps needed from the first index.
    }

    /**
     * Helper function for recursive approach with exponential time complexity.
     * 
     * @param arr Array of integers where each element represents the maximum jump length.
     * @param id Current index in the array.
     * @return The minimum number of jumps needed from index `id` to the end.
     */
    private int helper(int[] arr, int id) {
        // Base case: If the index is at or beyond the last position, no more jumps are needed.
        if (id >= arr.length - 1) return 0;

        // Maximum number of steps that can be taken from the current index.
        int m = arr[id];
        int ans = 1_000_000_007; // Initialize to infinity for comparison.

        // Try all possible jumps from the current position.
        for (int i = 1; i <= m; i++) {
            // Recursively calculate the jumps needed from the next position.
            int res = helper(arr, id + i);
            // Update `ans` with the minimum result.
            ans = Math.min(ans, 1 + res);
        }
        return ans; // Return the minimum jumps needed from index `id`.
    }
}

