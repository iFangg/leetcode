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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* head = nullptr;
        auto nodes = std::unordered_map<int, TreeNode*>{};
        auto isChild = std::unordered_map<int, bool>{};
        for (auto desc : descriptions) {
            auto& node = desc[0];
            auto& left = desc[2];
            auto& child = desc[1];

            if (!nodes.contains(node))
                nodes[node] = new TreeNode(node);

            TreeNode* curr = nodes[node];

            if (!nodes.contains(child))
                nodes[child] = new TreeNode(child);

            if (left)
                curr->left = nodes[child];
            else
                curr->right = nodes[child];

            isChild[child] = true;
            if (isChild.find(node) == isChild.end())
                isChild[node] = false;
        }

        for (const auto& node : nodes) {
            if (!isChild[node.first]) {
                head = node.second;
                break;
            }
        }

        return head;
    }
};


// Solution 2
#define MAX 100001

#pragma GCC optimize("03")
#pragma GCC target("avx")
#pragma GCC target("-fsplit-loops")

#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x, left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* Nodes[MAX];
TreeNode nodes[MAX];
int parents[MAX];  // Array to keep track of parent-child relationships
int visited[MAX];  // Array to track nodes that have been created
int count = 0;
int index = 0;
TreeNode* parent;
TreeNode* child;

// Initialize I/O optimizations
auto _ = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    TreeNode* createBinaryTree(const std::vector<std::vector<int>>& descriptions) {
        // Reset Nodes and parents arrays
        while (count) {
            Nodes[visited[--count]] = nullptr;
            parents[visited[count]] = 0;
        }
        index = count;
        
        for (const std::vector<int>& desc : descriptions) {
            int a = desc[0];
            int b = desc[1];
            
            // Get or create the parent node
            parent = Nodes[a] ? Nodes[a] : (Nodes[a] = &(nodes[index++] = TreeNode(visited[count++] = a)));
            
            // Get or create the child node
            child = Nodes[b] ? Nodes[b] : (Nodes[b] = &(nodes[index++] = TreeNode(visited[count++] = b)));
            
            // Record the parent of the child node
            parents[b] = a;
            
            // Set the child node as left or right child of the parent
            if (desc[2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        }
        
        // Find and return the root node
        for (const std::vector<int>& desc : descriptions) {
            if (!parents[desc[0]]) {
                return Nodes[desc[0]];
            }
        }
        return nullptr;
    }
};

