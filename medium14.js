// Solution 1
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const len = s.length;
    if (len <= 1) return len;
    let max = 1;
    let substring = [];
    let next = 0;
    for (let i = 0; i <= len; i++) {
        if (i === len || substring.includes(s[i])) {
            max = Math.max(max, substring.length);
            substring = [];
            i = next++;
        } else {
            substring.push(s[i]);
        }
    }

    return max;
};


// Solution 2
var lengthOfLongestSubstring = function(s) {
    let max = 0;
    let sb = '';

    for(let i = 0; i < s.length; i++) {
        if (!sb.includes(s[i])) {
            sb = sb + s[i];
        } else {
            max = Math.max(max, sb.length);
            let index = sb.indexOf(s[i])
            sb = sb.slice(index + 1, sb.length) + s[i];
        }
    }

    max = Math.max(max, sb.length);
    return max;
};
