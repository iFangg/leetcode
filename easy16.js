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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
var isSameTree = function(p, q) {
    return treeTraverse(p, q);
};

function treeTraverse(n1, n2) {
    if (n1 === null && n2 === null) return true;
    if (n1 === null || n2 === null) return false;
    if (n1.val !== n2.val) return false;
    return treeTraverse(n1.left, n2.left) && treeTraverse(n1.right, n2.right);
}


// Solution 2
var isSameTree = (p, q) => {
    if (p === null && q === null) return true
    if (p === null || q === null ) return false 
    if (p.val !== q.val) return false 

    let left = isSameTree(p.left, q.left)
    let right= isSameTree(p.right, q.right)

    return  left && right
}
