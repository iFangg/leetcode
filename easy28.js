// Solution 1
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    for (let i = 0; i < nums.length; i++) {
        let index = nums.indexOf(nums[i], i + 1);
        if (index !== -1) {
            if (Math.abs(i - index) <= k) return true;
        }
    }

    return false;
};


// Solution 2
var containsNearbyDuplicate = function(nums, k) {
    const numIndices = new Map();

    for (let i = 0; i < nums.length; i++) {
        const currentNum = nums[i];

        if (numIndices.has(currentNum) && (i - numIndices.get(currentNum)) <= k) {
            return true;
        }

        numIndices.set(currentNum, i);
    }

    return false;
};
