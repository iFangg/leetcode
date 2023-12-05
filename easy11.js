// Solution 1
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    let start = 0;
    let end = nums.length - 1;
    while (start < end) {
        if (nums[start] < target) start++;
        if (nums[end] > target) end--;
        if (nums[start] === target) return start;
        if (nums[end] === target) return end;
    }

    return nums[end] < target ? end + 1 : end;
};


// Solution 2 - more space efficient
var searchInsert = function (nums, key) {
    let start = 0;
    let end = nums.length - 1;
    let middle = 0;
    while (start <= end) {
        middle = Math.floor((start + end) / 2);

        if (nums[middle] == key) {
            // found the key
            return middle;
        } else if (nums[middle] < key) {
            // continue searching to the right
            start = middle + 1;
        } else {
            // search searching to the left
            end = middle - 1;
        }
    }
    // key wasn't found
    if (nums[middle]< key) {
        return middle + 1
    } else {
        return middle
    }

};


// Solution 3 - unintended solution
var searchInsert = function(nums, target) {
    nums.push(target)
    let Array=nums.sort((a,b)=>a-b)
    return Array.indexOf(target)
};
