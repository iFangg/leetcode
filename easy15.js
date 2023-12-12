// Solution 1
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    const unique = Array.from(new Set(nums));
    const len = unique.length;
    for (let i = 0; i < len; i++) {
        nums[i] = unique[i];
    }
    
    return len;
};

// Solution 2
var removeDuplicates = function(nums) {
   let k = 1;
   for(let i = 1; nums.length> i; i++) {
      if(nums[i] !== nums[i-1]) {
       nums[k] = nums[i]
       k++
      }
   }
   return k
};
