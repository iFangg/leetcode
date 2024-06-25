// Solution 1
/**
 * Definition for a binary tree node->
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
    TreeNode* makeTree(int& total, std::unordered_map<int, int>& node_sums, std::unordered_map<int, std::vector<int>>& node_leq, TreeNode* root) {
        int greater_key = total;
        for (auto i = node_leq[root->val].begin(); i != node_leq[root->val].end(); ++i) {
            greater_key -= *i;
        }

        auto new_head = new TreeNode(greater_key);
        if (root->left != nullptr) new_head->left = makeTree(total, node_sums, node_leq, root->left);
        if (root->right != nullptr) new_head->right = makeTree(total, node_sums, node_leq, root->right);

        return new_head;
    }

    TreeNode* bstToGst(TreeNode* root) {
        // traverse once to find total sum (and sum of each specific node?)
        // sum of each specific node: total - all numbers leq
        auto node_sums = std::unordered_map<int, int>{};
        auto node_leq = std::unordered_map<int, std::vector<int>>{};
        auto total = int{0};
        auto queue = std::queue<TreeNode*>{};
        queue.push(root);
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();

            total += node->val;
            if (node->left != nullptr) queue.push(node->left);
            if (node->right != nullptr) queue.push(node->right);

            if (!node_leq.contains(node->val)) node_leq[node->val] = std::vector<int>{};
            for (auto i = node_leq.begin(); i != node_leq.end(); ++i) {
                if (node->val == i->first) continue;
                if (node->val < i->first) node_leq[i->first].push_back(node->val);
                if (node->val > i->first) node_leq[node->val].push_back(i->first);
            }
        }

        return makeTree(total, node_sums, node_leq, root);
    }
};


// Solution 2
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int acc_sum = 0;
        sum_node(root,acc_sum);
        return root;
    }
    
    void sum_node(TreeNode* node, int& acc_sum){
        if (node == NULL)  return;
        sum_node(node->right,acc_sum);
        node->val += acc_sum;
        acc_sum = node->val;
        sum_node(node->left, acc_sum);
    }
};
