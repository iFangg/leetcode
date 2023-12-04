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

// Solution 3 - if you'd want to print the subarray as well
var maxSubArray = function(nums) {
    let largest = -Infinity;
    let current = 0;
    let startIdx = 0;  // Start index of the current maximum subarray
    let endIdx = 0;    // End index of the current maximum subarray

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > current + nums[i]) {
            // Start a new subarray
            current = nums[i];
            startIdx = i;
        } else {
            // Extend the current subarray
            current = current + nums[i];
        }

        if (current > largest) {
            // Update the largest sum and end index
            largest = current;
            endIdx = i;
        }
    }

    // The resulting object includes the sum, start index, and end index of the largest subarray
    return nums.slice(startIdx, endIdx + 1);
    // or
    // return {
    //     sum: largest,
    //     start: startIdx,
    //     end: endIdx
    // };
};
