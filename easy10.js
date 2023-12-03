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
 * @param {number[]} nums
 * @return {TreeNode}
 */
var sortedArrayToBST = function(nums) {
    if (nums.length === 0) return null;

    return constructBST(nums, 0, nums.length - 1);
};

function constructBST(nums, start, end) {
    if (start > end) {
        return null;
    }

    const middle = Math.floor((start + end) / 2);
    const root = new TreeNode(nums[middle]);

    root.left = constructBST(nums, start, middle - 1);
    root.right = constructBST(nums, middle + 1, end);

    return root;
}


// Solution 2
var sortedArrayToBST = function(nums) {
    let mid;
    mid = Math.floor(nums.length / 2);
    if (!nums.length) {
        return null;
    }
    let node = new TreeNode(nums[mid])
    node.left = sortedArrayToBST(nums.slice(0, mid));
    node.right = sortedArrayToBST(nums.slice(mid + 1, nums.length));
    return node;
};
