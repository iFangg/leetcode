// Solution 1
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length != t.length) return false;
    s = Array.from(s.split('')).sort();
    t = Array.from(t.split('')).sort();
    for (let i = 0; i < s.length; i++) {
        if (s[i] !== t[i]) return false;
    }

    return true;
};


// Solution 2
var isAnagram = function(s, t) {
    if (s.length != t.length) return false;
    s = Array.from(s.split('')).sort().join('');
    t = Array.from(t.split('')).sort().join('');
    return s === t
};
