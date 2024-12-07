// Solution 1 - NO ATTEMPTED SOLUTION
class Solution {
    public int minimumSize(int[] nums, int maxOps) {
        /*
        always try to split the bag with most marbles
            if even number, split in half
            if odd, split by  ???
        9 | 2
            4, 5
            4, 2, 3
        */

        return 0;
    }
}


// Solution 2
class Solution {
    public int minimumSize(int[] nums, int maxOps) {
        /*
        always try to split the bag with most marbles
            if even number, split in half
            if odd, split by  ???
        9 | 2
            4, 5
            4, 2, 3
        */

        int low = 1, high = Arrays.stream(nums).max().getAsInt();
        while (low < high) {
            int mid = (low + high) / 2;
            int ops = 0;
            for (int n : nums) {
                ops += (n - 1) / mid;
            }
            if (ops <= maxOps) high = mid;
            else low = mid + 1;
        }
        return high;
    }
}
