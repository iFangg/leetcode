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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // traverse to find all nodes to delete and their parents/children
        // find all new potential heads
        auto heads = std::vector<TreeNode*>{};
        auto queue = std::queue<std::pair<TreeNode*, TreeNode*>>{};
        auto to_delete_set = std::unordered_set<int>(to_delete.begin(), to_delete.end());
        auto targets = std::unordered_map<TreeNode*, std::vector<TreeNode*>>{};
        queue.push({root, nullptr});
        while (!queue.empty()) {
            auto node_ptr = queue.front();
            auto node = node_ptr.first;
            auto parent = node_ptr.second;
            queue.pop();

            if (to_delete_set.contains(node->val)) {
                targets[node] = {parent, node->left, node->right};
            }

            if (node->left != nullptr)
                queue.push({node->left, node});
            if (node->right != nullptr)
                queue.push({node->right, node});
        }

        if (!to_delete_set.contains(root->val)) {
            heads.push_back(root);
        }

        for (auto& [node, their] : targets) {
            auto parent = their[0];
            auto left = their[1];
            auto right = their[2];
            if (parent != nullptr) {
                if (parent->left == node)
                    parent->left = nullptr;
                
                if (parent->right == node)
                    parent->right = nullptr;
            }

            if (left != nullptr and !targets.contains(left)) {
                heads.push_back(left);
            }

            if (right != nullptr and !targets.contains(right)) {
                heads.push_back(right);
            }
        }

        return heads;
    }
};


// Solution 2 (more accurate)
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> rst;
        unordered_set<int> removeSet(to_delete.begin(), to_delete.end());

        root = dfs(root, removeSet, rst);
        if (root) rst.push_back(root);
        return rst;
    }


    TreeNode* dfs(TreeNode* root, unordered_set<int>& removeSet, vector<TreeNode*>& rst){
        if (root==nullptr) return nullptr;
        auto leftNode = dfs(root->left, removeSet, rst);
        auto rightNode = dfs(root->right, removeSet, rst);

        root->left = leftNode;
        root->right = rightNode;

        if (removeSet.count(root->val)){
            if (root->left) rst.push_back(root->left);
            if (root->right) rst.push_back(root->right);
            delete root;
            return nullptr;
        }
        return root;
    }
};
