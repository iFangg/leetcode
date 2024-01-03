// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let k = 1; // Count for non-duplicate elements
    let count = 1; // Count for consecutive occurrences of the same element

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] === nums[i - 1]) {
            count++;
        } else {
            count = 1; // Reset count for a new element
        }

        if (count <= 2) {
            nums[k++] = nums[i]; // Copy the element to the new position
        }
    }

    return k;
};


// Solution 2
var removeDuplicates = function(nums) {
    for (let i = 0; i < nums.length - 2; i++) {
        if (nums[i] === nums[i + 1] && nums[i + 1] === nums[i + 2]) {
            nums.splice(i, 1);
            i--;
        }
    }
  
    return nums.length;
};
