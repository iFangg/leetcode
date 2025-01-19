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
    public int jump(int[] nums) {
        return jump(nums, 0, 0, 0);
    }

    public int jump(int[] nums, int from, int to, int jumpCount) {
        int n = nums.length;
        if (to >= n-1) {
            return jumpCount;
        }
        int nextTo = -1;
        for (int i=from; i<=to; i++) {
            nextTo = Math.max(nextTo, nums[i]+i);
        }
        return jump(nums, to+1, nextTo, jumpCount+1);
    }
    
    public int jump2(int[] nums) {
        int n = nums.length;
        int[]dp = new int[n];
        Arrays.fill(dp, 1_000_000_007);
        dp[n-1] = 0;

        for(int i = n-2; i>=0; i--){
            for(int j = i+1; j <= i+nums[i] && j<n; j++){
               dp[i] = Math.min(dp[i], 1 +dp[j]);
            }
        }
        return dp[0];
    }

    private int helper(int[] arr, int id){
        if(id >= arr.length-1) return 0;

        int m = arr[id];
        int ans = 1_000_000_007;
        for(int i = 1; i<=m; i++){
            int res = helper(arr, id + i);
            ans = Math.min(ans, 1 + res);
        }
        return ans;
    }
}
