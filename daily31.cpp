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
    void dfs(TreeNode* curr, std::unordered_map<std::string, TreeNode*>& leafs, string& path) {
        if (curr == nullptr)
            return;

        if (curr->left == nullptr and curr->right == nullptr) {
            leafs[path] = curr;
            return;
        }
        
        path += "L";
        dfs(curr->left, leafs, path);
        path.pop_back();

        path += "R";
        dfs(curr->right, leafs, path);
        path.pop_back();
       
        return;
    }

    int countPairs(TreeNode* root, int distance) {
        // find all leaf nodes
        // find distance to other leaf nodes given they are within distance
            // compare paths of one leaf node to another
            // = amount of differing nodes in the paths 
            //  + remaining path lengths for both nodes after difference in path is detected
        int pairs = 0;
        auto leafs = std::unordered_map<std::string, TreeNode*>{};
        auto visited = unordered_set<TreeNode*>{};
        std::string path{""};
        dfs(root, leafs, path);
        for (auto [p, n] : leafs) {
            for (auto [o_p, o_n] : leafs) {
                if (visited.contains(o_n))
                    continue;
                if (o_n == n)
                    continue;
                
                auto difference = 0;
                auto index = 0;
                while (index < p.size() and index < o_p.size()) {
                    if (p[index] != o_p[index]) {
                        difference += 2;
                        difference += std::max(p.size(), o_p.size()) - (index + 1);
                        difference += std::min(p.size(), o_p.size()) - (index + 1);
                        break;
                    }

                    index++;
                }

                if (difference <= distance) {
                    pairs++;
                }
            }

            visited.insert(n);
        }

        return pairs;
    }
};


// Solution 2
struct NodePos
{
    int64_t depth;
    int64_t pos;
};

void dfs(TreeNode *node, std::vector<NodePos> &leaves, int64_t depth, int64_t pos)
{
    if(node->left != nullptr)
    {
        dfs(node->left, leaves, depth + 1, pos);
    }

    if(node->right != nullptr)
    {
        dfs(node->right, leaves, depth + 1, pos | (int64_t(1) << depth));
    }

    if(node->left == nullptr && node->right == nullptr)
    {
        NodePos p;
        p.depth = depth;
        p.pos = pos;
        leaves.emplace_back(p);
    }
}

class Solution {
public:
    int countPairs(TreeNode* root, int distance)
    {
        std::vector<NodePos> leaves;

        dfs(root, leaves, 0, 0);

        int result = 0;

        std::cout << "=========" << std::endl;

        for(size_t i = 0; i < leaves.size() - 1; i++)
        {
            for(size_t j = i + 1; j < leaves.size(); j++)
            {
                auto fd = leaves[i].depth;
                auto sd = leaves[j].depth;

                auto fp = leaves[i].pos;
                auto sp = leaves[j].pos;

                auto min = std::min(fd, sd);

                auto depthDiff = __builtin_ctzl(fp ^ sp);
                
                auto diff = (fd - depthDiff) + sd - depthDiff;

                if(diff == 0 && fd != sd)
                {
                    diff = std::abs(fd - sd);
                }

                result += diff <= distance;
            }
        }
        return result;

    }
};
