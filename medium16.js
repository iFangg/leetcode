// Solution 1 - TOO SLOW
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubarraySumCircular = function(nums) {
    if (nums.length === 1) return nums[0];
    let largest = -Infinity;
    let curr = 0;
    let sums = [];
    for (let start = 0; start < nums.length; start++) {
        // console.log(`S - ${start}`)
        for (let i = start; i < start + nums.length; i++) {
            // console.log(i)
            let n = (i + 1) % nums.length;
            curr = Math.max(nums[n], curr + nums[n]);
            largest = Math.max(largest, curr);
            // console.log(`l&c ${largest}, ${curr}`)
        }

        sums.push(largest);
        largest = -Infinity;
        curr = 0;
    }

    sums.sort((a, b) => b - a);
    return sums[0];
};

// Solution 2
var maxSubarraySumCircular = function(nums) {
    if (nums.length === 1) return nums[0];

    // Function to find maximum subarray sum using Kadane's algorithm
    function kadane(nums) {
        let maxEndingHere = nums[0];
        let maxSoFar = nums[0];

        for (let i = 1; i < nums.length; i++) {
            maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    let totalSum = 0;
    let maxSum = kadane(nums);

    // Calculate total sum and find minimum subarray sum
    for (let i = 0; i < nums.length; i++) {
        totalSum += nums[i];
        nums[i] = -nums[i];
    }

    // If all elements are negative, return the maximum subarray sum
    if (totalSum + kadane(nums) === 0) {
        return maxSum;
    }

    // Otherwise, return the maximum of the circular subarray sum and the maximum subarray sum
    return Math.max(maxSum, totalSum + kadane(nums));
};


// Solution 3
var maxSubarraySumCircular = function(A) {
    let total = 0;
    let maxSum = -Infinity;
    let curMax = 0;
    let minSum = Infinity;
    let curMin = 0;
    
    for (let i = 0; i < A.length; i++) {
        curMax = Math.max(curMax + A[i], A[i]);
        maxSum = Math.max(maxSum, curMax);
        curMin = Math.min(curMin + A[i], A[i]);
        minSum = Math.min(minSum, curMin);
        total += A[i];
    }
    return maxSum > 0 ? Math.max(maxSum, total - minSum) : maxSum;
};
