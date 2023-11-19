// Maximum Score From Removing Stones
// Solution 1
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
    let rows = [a, b, c].sort((a, b) => b - a);
    let counter = 0;
    while (rows[1] != 0) {
        rows[0]--;
        rows[1]--;
        counter++;
        rows.sort((a, b) => b - a);
    }
    
    return counter;
};

// Solution 2
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var maximumScore = function(a, b, c) {
    let rows = [a, b, c].sort((a, b) => b - a);
    if (rows[2] + rows[1] <= rows[0]) {
        return rows[2] + rows[1];
    } else {
        const min = Math.min(rows[0], Math.floor((rows[1] + rows[2] - rows[0]) / 2));
        return rows[0] + min;
    }
};
