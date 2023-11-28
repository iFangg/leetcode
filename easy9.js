/// Solution 1
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var getMinimumDifference = function(root) {
    if (root === null) return 0;
    const values = [];
    getAllValues(root, values);
    values.sort((a, b) => a - b);
    let min = Math.abs(values[1] - values[0]);
    for (let i = 1; i < values.length - 1; i++) {
        const curr = Math.abs(values[i + 1] - values[i]);
        min = Math.min(min, curr);
    }
    return min;
};

function getAllValues(node, values) {
    if (node === null) return;
    values.push(node.val);
    getAllValues(node.left, values);
    getAllValues(node.right, values);
}

// Solution 2
var getMinimumDifference = function(root) {
    let min = Infinity
    let prevVal = -Infinity
    function dfs(node){ 
        if(!node) return null

        dfs(node.left)
        min = Math.min(min, node.val-prevVal)
        prevVal = node.val
        dfs(node.right)
    }


    dfs(root)

    return min === Infinity ? null : min
};
