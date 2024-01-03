// Solution 1
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    let len = needle.length;
    for (let i = 0; i <= haystack.length - len; i++) {
        let word = haystack.slice(i, i + len);
        if (word === needle) return i;
    }

    return -1;
};


// Solution 2
var strStr = function(haystack, needle) {
    const n = haystack.length;
    const m = needle.length;

    if (m === 0) return 0;

    for (let i = 0; i <= n - m; i++) {
        let j = 0;
        while (j < m && haystack[i + j] === needle[j]) {
            j++;
        }

        if (j === m) {
            return i;
        }
    }

    return -1;
};


// Solution 3
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};
