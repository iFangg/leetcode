// Solution 1
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    const sChars = s.split('');
    const filtered = t.split('').filter(char => sChars.includes(char));
    let match = "";
    let index = 0;
    for (let char of filtered) {
        if ((sChars[index] === char)) {
            match += char;
            index++;
        }
    }
    if (match === s) return true;
    return false;
};

// Solution 2
var isSubsequence = function(s, t) {
    t.split("").forEach(char => {
        if (char === s[0]) {
            s = s.slice(1)
        }
    })

    return s === ""
};

// Solution 3
const isSubsequence = (s, t, index = 0) => {

    if (s.length > t.length) return false;

    for (let i = 0; i < t.length; i++) {
        if (s[index] == t[i]) {
            index++;
            if (index == s.length) break;
        }
    }
    return s.length === index;
};
