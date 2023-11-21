// Solution 1
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let k = 0;
    let index = 0;
    let numsCopy = nums.slice();
    for (let i = 0; i < numsCopy.length; i++) {
        if (numsCopy[i] != val) {
            nums[index] = numsCopy[i];
            k++;
            index++;
        }
    }

    return k;
};

// Solution 2
var removeElement = function(nums, val) {
    let arr = nums.filter(e => e !== val);
    // or
    let counter = 0;
    let arr = nums.filter(e => {
        if (e === val) {
            // Increment the counter if the element is equal to val
            counter++;
            return false; // Exclude the element from the filtered array
        }
        return true; // Include the element in the filtered array
        });
    nums.splice(0,nums.length);
    nums.push(...arr);

    return counter;
};

// Solution 3
var removeElement = function(nums, val) {
  let count = 0;
  for(let i = 0; i < nums.length; i++){
    if(nums[i] !== val){
      nums[count++] = nums[i];
    }
  }
  return count;
};
