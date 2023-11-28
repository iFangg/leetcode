// Solution 1
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const opens = ['(', '[', '{'];
    const pairs = {'(': ')', '[':']', '{':'}'};
    const openPar = [];
    let len = s.length;

    if (len == 1) return false;
    for (const char of s.split('')) {
        if (opens.includes(char)) {
            openPar.push(char);
        };
        if (openPar.length === 0) continue;
        const parenth = openPar.pop();
        if (pairs[parenth] !== char) openPar.push(parenth);
        else len -= 2;
    }

    return (openPar.length === 0 && len === 0) ? true : false;
};

// Solution 2
var isValid = function(s) {
    let stack = [];

    const pairs = {
        ')': '(',
        '}': '{',
        ']': '[',
    };

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(' || s[i] === '[' || s[i] === '{') {
            stack.push(s[i]);
        } else {
            if (!stack.length) return false;
            let char = stack.pop();
            if (char !== pairs[s[i]]) {
                return false;
            }
        }
    }

    return stack.length === 0;
};
