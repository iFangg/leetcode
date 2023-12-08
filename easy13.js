// Solution 1
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    const num = BigInt(digits.join('')) + BigInt(1);
    const incremented = num.toString().split('').map(Number);
    return incremented;
};
