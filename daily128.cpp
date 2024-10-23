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
    TreeNode* replaceValueInTree(TreeNode* root) {
        /*
        track depth
        track each node and parents
            1 - no parent
            2 - 1 parent
            3 -  max 2 parents
            4 - max 4 parents
        
        traverse using bfs

        keep total sum of all children nodes
        each child gets assigned (sum - parent sum)
        c++ memory weird, this doesn't work
        ____
        if previous level has one or less nodes
            nodes of current level are all 0
        else
            map each parent node to the sums of their immediate children
                but add sum of children values to every other parent instead
            for each other parent, add the sum of this parents children to their nodes
            store vector of children? 
                children nodes to parent nodes
        ----

        if current level has more than one node
            update children scores
                (sum - children sum)
        else
            nodes of current level are all 0
        */

        auto q = std::queue<std::pair<TreeNode*, int>>{};
        auto num = 0;

        if (root != nullptr) {
            q.push({root, num});
            ++num;
        }
    
        while (!q.empty()) {
            int lvl = q.size();
            auto temp = lvl;
            auto sum = 0;

            // child, parent
            auto parents = std::unordered_map<int, std::vector<TreeNode*>>{};

            while (lvl--) {
                auto next = q.front();
                auto *node = next.first;
                q.pop();

                // std::cout << "current node: " << node->val << std::endl;

                if (!parents.contains(next.second) and node->left != nullptr and node->right != nullptr)
                    parents[next.second] = {};

                if (node->left != nullptr) {
                    parents[next.second].push_back(node->left);
                    q.push({node->left, num++});
                    sum += node->left->val;
                }

                if (node->right != nullptr) {
                    parents[next.second].push_back(node->right);
                    q.push({node->right, num++});
                    sum += node->right->val;
                }

                std::cout << sum << std::endl;
                std::cout << parents.size() << std::endl;
                if (temp <= 1) {
                    // std::cout << "different parents found!\n";
                    node->val = 0;
                }
            }

            for (auto& [p, c] : parents) {
                auto local_sum = sum;
                for (auto& child : c) {
                    local_sum -= child->val;
                    // std::cout << "child: " << child->val << std::endl;
                }

                for (auto& child : c) {
                    child->val = local_sum;
                }
            }
        }

        return root;
    }
};

// Solution 2
class Solution {
public:
    // Vector to store the sum of node values at each depth level.
    // Index 'i' will store the sum of all node values at depth 'i'.
    vector<int> depthSum;

    // First DFS (Depth-First Search) to calculate the sum of values at each depth.
    // Parameters:
    // - root: pointer to the current TreeNode.
    // - d: current depth level of the node.
    void dfs1(TreeNode* root, int d) {
        // Base case: If the node is null (i.e., no node exists at this position), return.
        if (!root) return;
        
        // If 'd' (current depth) is greater than or equal to the current size of depthSum,
        // it means this is the first node we're encountering at this depth.
        // We need to add this node's value to depthSum by pushing it back.
        if (d >= depthSum.size()) 
            depthSum.push_back(root->val);
        else 
            // If we have already visited this depth, simply add the node's value
            // to the sum stored at this depth (depthSum[d]).
            depthSum[d] += root->val;
        
        // Recursively call dfs1 for the left child, with depth incremented by 1.
        dfs1(root->left, d + 1);
        // Recursively call dfs1 for the right child, with depth incremented by 1.
        dfs1(root->right, d + 1);
    }

    // Second DFS to modify the values in the tree.
    // This DFS replaces each node's value based on the sum of nodes at the next depth level.
    // Parameters:
    // - root: pointer to the current TreeNode.
    // - val: the new value to assign to the current node.
    // - d: current depth level of the node.
    void dfs2(TreeNode* root, int val, int d) {
        // Base case: If the node is null, return (do nothing).
        if (!root) return;

        // Set the current node's value to 'val', which is passed from its parent.
        root->val = val;

        // Calculate the sum of values at the next depth level (d + 1).
        // If depth (d + 1) exists in depthSum, use it; otherwise, use 0 (no nodes at next level).
        int c = d + 1 < depthSum.size() ? depthSum[d + 1] : 0;

        // Adjust the sum by subtracting the values of the left and right children, if they exist.
        // This prevents double counting the values of the node's children when we replace the node's value.
        c -= (root->left != nullptr ? root->left->val : 0);  // Subtract the left child's value if it exists.
        c -= (root->right != nullptr ? root->right->val : 0); // Subtract the right child's value if it exists.

        // Recursively process the left child, passing the updated value 'c' and incrementing depth by 1.
        if (root->left) dfs2(root->left, c, d + 1);
        // Recursively process the right child, passing the updated value 'c' and incrementing depth by 1.
        if (root->right) dfs2(root->right, c, d + 1);
    }

    // Main function to replace the values in the tree.
    // Parameters:
    // - root: pointer to the root of the tree.
    // Returns the root of the modified tree.
    TreeNode* replaceValueInTree(TreeNode* root) {
        // First DFS to compute the sum of node values at each depth.
        // This populates the depthSum vector.
        dfs1(root, 0);
        
        // Second DFS to replace the values in the tree based on the depth sums.
        // Initially, we start at the root with value 0 and depth 0.
        dfs2(root, 0, 0);
        
        // Return the modified tree.
        return root;
    }
};

