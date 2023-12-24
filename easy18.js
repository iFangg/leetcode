// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    if (nums.length === 1) return nums[0];
    const len = nums.length;
    let count = 1;
    nums.sort((a, b) => a - b);
    for (let i = 1; i < len; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
            if (count > len / 2) {
                return nums[i];
            }
        }
    }

    return 0;
};

// Solution 2
function majorityElement(nums) {
    let count = 0;
    let candidate = null;

    for (const num of nums) {
        if (count === 0) {
            candidate = num;
        }
        count += (num === candidate) ? 1 : -1;
    }

    return candidate;
}

