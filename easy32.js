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
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if (root === null) return true;
    
    function isMirror(node, mNode) {
        if (node === null && mNode === null) return true;
        if (node === null || mNode === null) return false;
        return (
            node.val === mNode.val &&
            isMirror(node.left, mNode.right) &&
            isMirror(node.right, mNode.left)
        );
    }

    return isMirror(root.left, root.right);
};


// Solution 2
var isSymmetric = function(root) {
    if(root === null) return null;
    let left = root.left !== null ?  root.left : null
    let right = root.right !== null ?  root.right : null 
    return compare(left, right)
};

const compare = (n1, n2) => {
    if(n1 === null || n2 === null){
        return n1 === null && n2 === null;
    }
    if(n1.val !== n2.val){
        return false;
    }

    
    let n1Left = n1.left !== null ?  n1.left : null;    
    let n2Left = n2.left !== null ?  n2.left : null;
    
    let n1Right = n1.right !== null ?  n1.right : null;
    let n2Right = n2.right !== null ?  n2.right : null;
    return compare(n1Left, n2Right) && compare(n2Left, n1Right);   
}
