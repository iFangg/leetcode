Rob houses (LEETCODE) solution

/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    function maxVal(index, max, currTotal) {
        const maximum = Math.max(max, currTotal);
        if (index + 2 >= nums.length) {
            if (!vals.includes(maximum)) vals.push(maximum);
            return maximum;
        }

        for (let i = 2; index + i < nums.length; i++) {
            max = maxVal(index + i, max, currTotal + nums[index + i]);  
        }

        return maximum;
    }

    const vals = [];
    for (let i = 0; i < nums.length; i++) {
        maxVal(i, 0, nums[i]);
    }
    
    return vals.sort((a,b) => b - a)[0];
};

// Solution 2
var rob = function(nums) {
  let a = nums[0];
  let b = nums[1] ?? 0;
  let c = a + (nums[2] ?? 0);
  for (let i = 3; i < nums.length; i++) {
    [a, b, c] = [b, c, Math.max(a, b) + nums[i]];
  }
  return Math.max(b, c);
};

// Solution 3
var rob = function(nums, i = 0, memo = {}) {
    if(i in memo) return memo[i]
    if(i >= nums.length) return 0;

    const sumIfSkipped = rob(nums, i + 1, memo);
    const sumIfRobbed = nums[i] + rob(nums, i + 2, memo);

    memo[i] = Math.max(sumIfSkipped, sumIfRobbed)
    return memo[i]
};
