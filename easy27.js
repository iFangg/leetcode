// Solution 1
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    function happy(nStr) {
        let result = 0;
        for (let i = 0; i < nStr.length; i++) {
            result += parseInt(nStr[i]) ** 2;
        }

        return result;
    }

    while (n !== 1) {
        if (n < 10 && n % 2 === 0) return false;
        let num = String(n).split('');
        n = happy(num);
    }

    return true;
};
