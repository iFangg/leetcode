// Solution 1
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    // console.log(n)
    let count = 0;
    let range = Math.min(32, Math.log(n) / Math.log(2) + 1)
    for (let i = 0; i < range; i++) {
        let bit = n >> i;
        if (bit & 1 === 1) count++;
        // console.log(`${bit & 1}, ${count}`)
    }

    return count;
};


// Solution 2 - Doesn't use bitwise operations (SACRILEGE)
var hammingWeight = function(n) {
  return n.toString(2).replaceAll("0", "").length;
};
