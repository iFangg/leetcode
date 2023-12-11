// Solution 1
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    let first = triangle[0][0];
    const sums = [];

    function bfs(sum, level, curr, index) {
        if (level + 1 >= triangle.length) {
            sums.push(sum + curr);
            return;
        }

        let sumL = bfs(sum + curr, level + 1, triangle[level + 1][index], index);
        let sumR = bfs(sum + curr, level + 1, triangle[level + 1][index + 1], index + 1);

        return;
    }

    bfs(0, 0, first, 0);
    const max = sums.sort((a, b) => a - b)[0];
    return max;
};

// Solution 2
var minimumTotal = function(triangle) {
    const n = triangle.length;

    // Create a copy of the triangle to store the minimum path sums
    const dp = triangle.map(row => [...row]);

    // Start from the second-to-last row and update the minimum path sums
    for (let i = n - 2; i >= 0; i--) {
        for (let j = 0; j <= i; j++) {
            dp[i][j] += Math.min(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    return dp[0][0]; // The top of the triangle contains the minimum path sum
};

// Solution 3
var minimumTotal = function(triangle) {
    let n = triangle.length;
    let data = Array.from({length: n}, () => Array(n).fill(null));

    const find = (i, j) => {
        if(data[i][j] != null) {
            return data[i][j];
        }

        if(i == n - 1) {
            data[i][j] = triangle[i][j];
        } else {
            data[i][j] = triangle[i][j] + Math.min(find(i + 1, j), find(i + 1, j + 1));
        }    
        return data[i][j];
    }

    return find(0, 0);
};
