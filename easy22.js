// Solution 1
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 1) return strs[0];
    let common = "";
    let start = strs[0];
    for (let i = 0; i < start.length; i++) {
        let char = start[i];
        for (let j = 1; j < strs.length; j++) {
            if (char !== strs[j][i]) return common
        }

        common += char;
    }

    return common;
};
