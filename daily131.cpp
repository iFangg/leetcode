// Solution 1 - FAIL
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        /*
        sort queries list based on how early they appear in the tree (maybe not needed)
        keep track of current height
        if child of node is in queries, sever link from the node
        return current height when we reach a leaf node and/or remove all in queries
        */

        auto heights = std::vector<int>(queries.size(), -1);

        for (auto i = 0; i < queries.size(); ++i) {
            auto q = std::queue<TreeNode*>{};
            q.push(root);

            while (!q.empty()) {
                auto count = q.size();
                heights[i]++;

                while (count--) {
                    auto node = q.front();
                    q.pop();

                    if (node->left != nullptr) {
                        if (queries[i] != node->left->val)
                            q.push(node->left);
                    }

                    if (node->right != nullptr) {
                        if (queries[i] != node->right->val)
                            q.push(node->right);
                    }
                }
            }

        }

        return heights;
    }
};


// Solution 2
class Solution {
public:
    vector<int> depth, levelArr, max1, max2;

    int height(TreeNode* root, int level) {
        if (!root) return 0;
        levelArr[root->val] = level;
        depth[root->val] = 1 + max(height(root->left, level + 1), height(root->right, level + 1));

    
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level];
            max1[level] = depth[root->val];
        } else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val];
        }

        return depth[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // Compute depths and max depths for each level
        height(root, 0);

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            int level = levelArr[q];
            queries[i] = (max1[level] == depth[q] ? max2[level] : max1[level]) + level - 1;
        }

        return queries;
    }
};
