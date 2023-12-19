// Solution 1 - FAIL
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length <= 1) return s;
    const strings = new Set();

    for (let i = 0; i < s.length; i++) {
        let str = "";
        let left = i;
        for (let j = s.length - 1; j >= 0; j--) {
            let right = j;
            while (left < right) {
                console.log(`${s[left]}, ${left} - ${s[right]}, ${right}`);
                if (s[left] === s[right]) {
                    str += s[left];
                } else if (str !== "") {
                    // console.log(str);
                    let final = str;
                    for (let i = str.length - 1; i >= 0; i--) {
                        final += str[i];
                    }
                    
                    strings.add(final);
                    str = "";
                }

                left++;
                right--;
            }

            if (str.length > 0) {
                let final = str + s[left];
                for (let i = str.length - 1; i >= 0; i--) {
                    if (!s.includes(final + str[i])) {
                        break;
                    }
                    
                    final += str[i];
                }

                strings.add(final);
            }
            
        }
    }

    if (strings.size === 0) return s[0];
    console.log(strings);
    const ordered = Array.from(strings);
    ordered.sort((a, b) => b.length - a.length);
    return ordered[0];
};


// Soilution 2
var longestPalindrome = function(s) {
    if (s.length <= 1) {
        return s;
    }

    let Max_Len = 1;
    let Max_Str = s[0];
    s = '#' + Array.from(s).join('#') + '#';
    const dp = Array(s.length).fill(0);
    let center = 0;
    let right = 0;

    for (let i = 0; i < s.length; i++) {
        if (i < right) {
            dp[i] = Math.min(right - i, dp[2 * center - i]);
        }

        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length && s[i - dp[i] - 1] === s[i + dp[i] + 1]) {
            dp[i] += 1;
        }

        if (i + dp[i] > right) {
            center = i;
            right = i + dp[i];
        }

        if (dp[i] > Max_Len) {
            Max_Len = dp[i];
            Max_Str = s.substring(i - dp[i], i + dp[i] + 1).replace(/#/g, '');
        }
    }

    return Max_Str;
};


// Solution 3
var longestPalindrome = function(s) {
    if (s === [...s].reverse().join('')) {
        return s;
    }

    let result = s[0];
    

    for (let i = 0; i < s.length; i += 1) {
        let l1 = i;
        let r1 = i;
        let oddStr = '';

        let l2 = i;
        let r2 = i+1;
        let evenStr = '';

        while (l1 >= 0 && r1 < s.length && s[l1] === s[r1]) {
            l1--
            r1++
        }

        while (l2 >= 0 && r2 < s.length && s[l2] === s[r2]) {
            l2--
            r2++
        }

        oddStr = s.slice(l1 + 1, r1);
        evenStr = s.slice(l2 + 1, r2);

        if (oddStr.length > result.length) {
            result = oddStr;
        }
        
        if (evenStr.length > result.length) {
            result = evenStr;
        }
    }

    return result;
};

