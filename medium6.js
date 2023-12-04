// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let largest = -Infinity;
    let current = 0;

    for (let num of nums) {
        current = Math.max(num, current + num);
        largest = Math.max(current, largest);
    }

    return largest;
};


// Solution 2
var maxSubArray = function(nums) {
    let max = nums[0];
    for (let i = 1; i < nums.length; i++) {
        nums[i] = Math.max(nums[i], nums[i] + nums[i - 1]);
        max = Math.max(nums[i], max);
    }
    return max;
};
