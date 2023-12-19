// Solution 1 - FAIL
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    if (s.length <= 1) return s;
    let maxLen = 1;
    let maxStr = s[0];
    s = '#' + s.split('').join('#') + '#';
    console.log(s);
    const dp = Array.from(s.length);
    let centre = 0;
    let right = 0;
    for (let i = 0; i < s.length; i++) {
        if (i < right) dp[i] = Math.min(right - i, dp[2 * centre - i]);
        while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < s.length && s[i - dp[i] - 1] === s[i + dp[i] + 1]) {
            dp[i]++;
        }
        if (i + dp[i] > right) {
            centre = i;
            right = i + dp[i];
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxStr = s.substring(i - dp[i], i + dp[i] + 1).replace('#', '');
        }

    }

    return maxStr;
};
