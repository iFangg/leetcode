// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    if (nums.length === 1) return nums[0];
    let unique = [];
    for (let i = 0; i < nums.length; i++) {
        if (unique.includes(nums[i])) {
            const index = unique.indexOf(nums[i]);
            unique.splice(index, 1);
        } else {
            unique.push(nums[i]);
        }
    }

    return unique[0];
};

// Solution 2
var singleNumber = function(nums) {
    let result = 0;
    for (let num of nums) {
        result ^= num;
    }
    
    return result;
};
