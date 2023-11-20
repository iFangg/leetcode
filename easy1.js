// Solution 1
/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function(nums1, m, nums2, n) {
    // index pointers for arrays, keep adding non-zero numbers and check for correct size merged array
    // check for smaller number, append that
    if (n == 0) return nums1;
    
    num1Copy = nums1.slice();
    mIndex = 0;
    nIndex = 0;
    let index = 0;
    let num = 0;
    while (mIndex < m) {
        if (num1Copy[mIndex] <= nums2[nIndex]) { // memory allocation error here!!
            num = num1Copy[mIndex];
            mIndex++;
        } else if (nums2[nIndex] <= num1Copy[mIndex]) {
            num = nums2[nIndex];
            nIndex++;
        }
        nums1[index] = num;
        index++;
    }


    while (index < m + n) {
        nums1[index] = nums2[nIndex];
        nIndex++;
        index++;
    }
};

// Solution 2
var merge = function(nums1, m, nums2, n) {
    // index pointers for arrays, keep adding non-zero numbers and check for correct size merged array
    // check for smaller number, append that
    if (n == 0) return nums1;
    let i = m - 1;
    let j = n - 1;
    let k = m + n - 1;
    
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
};
