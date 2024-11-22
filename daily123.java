// Solution 1 - FAIL (couldn't figure out implementation)
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        /*
        maximum possible bitwise OR is OR of every element
        meaning we need at least one element with same left bit as max OR
        first find all subsets of 1, then 2, then 3 ...
            base needs to be this same left bit as max OR
        */

        int max_or = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            max_or |= nums[i];
        }

        ArrayList<int> base_elems = new ArrayList<int>();
        int max_l_bit = Integer.highestOneBit(max_or);

        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            int left_bit = Integer.highestOneBit(n);

            if (max_l_bit == left_bit)
                base_elems.add(i);
        }

        int total = 0;
        for (int k = 1; k <= nums.length; k++) {
            for (int e : base_elems) {
                int curr = nums[e];
                int len = 1;

                while (len < k) {
                    do;
                }

                if (curr == max_or)
                    total++;
            }
        }

        return total;
    }
}


// Solution 2
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        int max_or = nums[0];

        for (int i = 1; i < nums.length; ++i) {
            max_or |= nums[i];
        }

        return countSubsets(nums, 0, 0, max_or);
    }

    private int countSubsets(int[] nums, int index, int current_or, int max_or) {
        // Base case: If we've processed all elements
        if (index == nums.length) {
            return current_or == max_or ? 1 : 0;
        }

        // Recursive case:
        // 1. Include the current element in the subset
        int include = countSubsets(nums, index + 1, current_or | nums[index], max_or);

        // 2. Exclude the current element from the subset
        int exclude = countSubsets(nums, index + 1, current_or, max_or);

        // Return the total count of valid subsets
        return include + exclude;
    }
}


// Solution 3
class Solution {
    public int countMaxOrSubsets(int[] nums) {
        // Step 1: Calculate the maximum possible OR (max)
        int[] tail = new int[16]; // To store the "tail ORs" for optimization.
        int max = nums[0];        // Initialize max OR with the first number.

        // Calculate the overall max OR by OR-ing all elements in nums.
        for (int i = 1; i < nums.length; i++) {
            max |= nums[i];
        }

        // Step 2: Precompute "tail ORs" for optimization.
        int v = 0;
        // Starting from the last element, calculate the OR of the "tail" of the array.
        for (int i = nums.length - 1; i > -1; i--) {
            v |= nums[i];      // Accumulate the OR value from the end of the array.
            tail[i] = v;       // Store the OR of the tail starting at index i.
        }

        // Step 3: Recursively count the subsets with OR equal to max.
        return recursion(nums, 0, 0, tail, max);
    }

    private int recursion(int[] nums, int i, int partial, int[] tail, int max) {
        // Base Case 1: If the partial OR equals max:
        // Any subset of the remaining elements will also have OR == max.
        if (partial == max) {
            return 1 << (nums.length - i); // 2^(remaining elements) subsets.
        }

        // Base Case 2: If we've processed all elements, or it's impossible to reach max:
        // Return 0 as there are no valid subsets.
        if (i == nums.length || (partial | tail[i]) != max) {
            return 0;
        }

        // Recursive Step:
        // 1. Include the current element in the subset (partial | nums[i]).
        // 2. Exclude the current element from the subset (partial remains unchanged).
        return recursion(nums, i + 1, partial | nums[i], tail, max) + 
               recursion(nums, i + 1, partial, tail, max);
    }
}

