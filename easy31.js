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
 * @param {number} targetSum
 * @return {boolean}
 */
var hasPathSum = function(root, targetSum) {
    if (root === null) return false;
    const sums = [];
    
    function findSums(root, sum) {
        if (root === null) return;
        if (root.left === null && root.right === null) {
            sums.push(sum + root.val);
            return;
        }

        findSums(root.left, sum + root.val);
        findSums(root.right, sum + root.val);
    }

    findSums(root, 0);

    return sums.includes(targetSum);
};


// Solution 2
var hasPathSum = function(root, targetSum) {
    if (root == null) return false
    if (root.left == null && root.right == null) return (targetSum - root.val == 0)
    return (hasPathSum(root.left, targetSum - root.val) || hasPathSum(root.right, targetSum - root.val))
};
