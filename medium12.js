// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if (nums.length <= 1) return nums.length;
    nums.sort((a, b) => a - b);
    let counter = 1;
    let max = 0;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) continue;
        if (nums[i] - nums[i - 1] === 1) counter++;
        else {
            max = Math.max(max, counter);
            counter = 1;
        }
    }

    return Math.max(max, counter);
};
