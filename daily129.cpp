// Solution 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    if current nodes aren't equal
        return false
    else if equal
        nodes' children are also equal, keep traversing
        not equal, check 1.left = 2.right and 1.right = 2.left
    */
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr and root2 == nullptr)
            return true;
        
        if (root1 == nullptr or root2 == nullptr)
            return false;

        if (root1->val != root2->val)
            return false;
        else {
            auto left_1 = root1->left != nullptr ? root1->left->val : -1;
            auto left_2 = root2->left != nullptr ? root2->left->val : -1;
            auto right_1 = root1->right != nullptr ? root1->right->val : -1;
            auto right_2 = root2->right != nullptr ? root2->right->val : -1;

            if (left_1 == left_2 and right_1 == right_2)
                return flipEquiv(root1->left, root2->left) and flipEquiv(root1->right, root2->right);
            
            if (left_1 == right_2 and right_1 == left_2)
                return flipEquiv(root1->left, root2->right) and flipEquiv(root1->right, root2->left);
        }
        
        return false;
    }
};


// Solution 2
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr and root2 == nullptr) return true;
        if(root1 == nullptr or root2 == nullptr) return false;
        if(root1->val != root2->val) return false;
        return ((flipEquiv(root1->left, root2->left) or flipEquiv(root1->left, root2->right)) and (flipEquiv(root1->right, root2->left) or flipEquiv(root1->right, root2->right)));
    }
};
