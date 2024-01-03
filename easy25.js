// Solution 1
/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    s = s.split(' ');
    if (pattern.length != s.length) return false;
    const charMap = {};
    for (let i = 0; i < pattern.length; i++) {
        const char = pattern[i];
        if (char in charMap) {
            if (charMap[char] != s[i]) return false;
        } else {
            if (Object.values(charMap).includes(s[i])) return false
            charMap[char] = s[i];
        }
    }

    return true;
};

