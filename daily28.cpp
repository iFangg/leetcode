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
#define MX 100001
#pragma GCC optimize("03")
#pragma GCC target ("avx")
#pragma GCC target ("-fsplit-loops")
TreeNode* Nodes[MX];
TreeNode nodes[MX];
int P[MX];
int V[MX];
int cnt = 0;
int idx = 0;
TreeNode* p;
TreeNode* c;
auto _ = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    return 0;
}();
// WIZARDY
class Solution {
public:
    TreeNode* createBinaryTree(const vector<vector<int>>& descriptions) {
        while(cnt) Nodes[V[--cnt]] = nullptr, P[V[cnt]] = 0;
        idx = cnt;
        for(const vector<int> &desc : descriptions){
            int a = desc[0], b = desc[1];
            p = Nodes[a] ? Nodes[a] : (Nodes[a] = &(nodes[idx++] = TreeNode(V[cnt++] = a)));
            c = Nodes[b] ? Nodes[b] : (Nodes[b] = &(nodes[idx++] = TreeNode(V[cnt++] = b)));
            P[b] = a;
            if(desc[2]) p -> left = c; else p -> right = c;
        }
        for(const vector<int> &desc : descriptions) if(!P[desc[0]]) return Nodes[desc[0]];
        return NULL;
    }
};
