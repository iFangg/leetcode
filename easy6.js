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
var maxDepth = function(root) {
    let max = [0];
    reachDepth(root, max, 1);

    return max[0];
};

function reachDepth(node, max, currDepth) {
    // console.log(`max - ${max}, currDepth ${currDepth}`);
    if (node == null) return;
    if (node.left != null) reachDepth(node.left, max, currDepth + 1);
    if (node.right != null) reachDepth(node.right, max, currDepth + 1);
    max[0] = max[0] >= currDepth ? max[0] : currDepth;
}

// Solution 2 - super fast, time and memory efficient
var maxDepth = function(root) {
    if (!root) {
        return 0
    }
    return 1 + Math.max(maxDepth(root.left), maxDepth(root.right))
};
