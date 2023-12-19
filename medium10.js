// Solution 1
/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    const h = grid.length;
    const w = grid[0].length;
    const dp = Array.from({length: h}, () => Array(w).fill(0));

    for (let i = h - 1; i >= 0; i--) {
        for (let j = w - 1; j>= 0; j--) {
            dp[i][j] = grid[i][j];
            if (i === h - 1 && j === w - 1) continue;
            if (i === h - 1) dp[i][j] = dp[i][j + 1] + grid[i][j];
            else if (j === w - 1) dp[i][j] = dp[i + 1][j] + grid[i][j];
            else dp[i][j] = grid[i][j] + Math.min(dp[i + 1][j], dp[i][j + 1])
        }
    }


    return dp[0][0];
};


// Solution 2
var minPathSum = function(grid) {
    if (!grid || grid.length === 0 || grid[0].length === 0) {
        return 0
    }

    const m = grid.length;
    const n = grid[0].length;
    const dp = new Array(m).fill(0).map(() => new Array(n).fill(0))
    /** dp will look like this
        [
         [0, 0, 0],
         [0, 0, 0],
         [0, 0, 0],
        ]
    */ 
    dp[0][0] = grid[0][0]
    /** so now dp looks like this,
        [
         [1, 0, 0],
         [0, 0, 0],
         [0, 0, 0],
        ]
    */
    // so we fill the first element of each row
    for (let i = 1; i < m; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    // we fill the first column
    for (let j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j]
    }
    /** so now dp looks like this,
        [
         [1, 4, 5],
         [2, 0, 0],
         [6, 0, 0],
        ]
    */

    // so now we go ahead and fill out the rest of dp array.
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            dp[i][j] = grid[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // The bottom-right cell of dp contains the minimum sum of paths
    return dp[m - 1][n - 1];
};
