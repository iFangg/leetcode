// Solution 1
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
var countNodes = function(root) {
    visited = []
    function count(total, root) {
        if (root === null) return total;
        if (visited.includes(root)) return total;
        visited.push(root)
        total = count(total + 1, root.left)
        total = count(total, root.right)
        return total;
    }

    return count(0, root);
};


// Solution 2
var countNodes = function(root) {
    if (root === null) {
        return 0;
    }

    return countNodes(root.left) + countNodes(root.right) + 1;
};
