// Solution 1
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    const aInt = BigInt(`0b${a}`);
    const bInt = BigInt(`0b${b}`);
    return (aInt + bInt).toString(2)
};
