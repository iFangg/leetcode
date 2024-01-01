// Solution 1
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const words = s.split(' ').filter(w => w.length > 0);
    return words[words.length - 1].length;
};


// Solution 2
var lengthOfLastWord = function(s) {
    var sArr=s.trim().split(' ');
    return sArr.pop().length;
};
