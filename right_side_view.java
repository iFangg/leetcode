/**
 * Definition for a binary tree node.
 */

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int maxDepth;
    List<Integer> rightView;

    public List<Integer> rightSideView(TreeNode root) {
        /*
         * dfs right side first (right to left), keep track of max depth
         * if curr depth is bigger than max depth, add v to array 
         */
        if (root == null) {
            return new ArrayList<>();
        }

        maxDepth = 0;
        rightView = new ArrayList<>();

        dfs(root, 1);
        return rightView;

    }

    public void dfs(TreeNode v, int currDepth) {
        if (v == null) {
            return;
        }

        if (currDepth > this.maxDepth) {
            this.rightView.add(v.val);
            this.maxDepth = currDepth;
        }


        dfs(v.right, currDepth + 1);
        dfs(v.left, currDepth + 1);
    }
}
