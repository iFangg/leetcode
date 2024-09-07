/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

// Solution 1 - FAIL
class Solution {
public:
    bool isSubPath(ListNode head, TreeNode* root) {
        curr_node = head;
        if (root == nullptr)
            return true;

        if (head == nullptr)
            return true;

        if (root->val == head->val) {
            seen_ = true;

            auto left = isSubPath(head->next, root->left);        
            auto right = isSubPath(head->next, root->right);

            if (!left and !right)
                return false;
        } else if (seen) {
            seen = false;
            return false;
        } else {
            auto left = isSubPath(head, root->left);        
            auto right = isSubPath(head, root->right);

            if (!left and !right)
                return false;
        }

        if (curr_node != nullptr)
            std::cout << curr_node->val << std::endl;
        return true;
    }

private:
    bool seen_ = false;
    ListNode* curr_node;
};

// Solution 2
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;  // Empty list is always a subpath
        if (root == nullptr) return false; // Empty tree can't contain a non-empty list
        
        // Check if the current root starts a matching path
        if (isMatchingPath(head, root)) return true;
        
        // If not, check left and right subtrees
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool isMatchingPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;  // Reached end of list, full match found
        if (root == nullptr) return false; // Reached end of tree branch without full match
        
        if (head->val != root->val) return false; // Values don't match
        
        // Current values match, check next nodes in both structures
        return isMatchingPath(head->next, root->left) || isMatchingPath(head->next, root->right);
    }
};
