// Solution 1
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        if (edges.size() == 0) return std::vector<std::vector<int>>(n, std::vector<int>{});
        auto ancestors = std::vector<std::vector<int>>(n, std::vector<int>{});
        auto in_degrees = std::unordered_map<int, int>{};
        auto neighbours = std::unordered_map<int, std::vector<int>>{};
        for (auto edge : edges) {
            auto parent = edge[0];
            auto child = edge[1];
            neighbours[parent].push_back(child);
            in_degrees[child]++;
        }

        auto q = std::queue<int>{};
        for (int i = 0; i < n; ++i) {
            if (in_degrees[i] == 0) q.push(i);
        }
        auto visited = std::unordered_set<int>{};
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (int child : neighbours[node]) {
                // Add the current node to the child's ancestors list if not already present
                if (find(ancestors[child].begin(), ancestors[child].end(), node) == ancestors[child].end()) {
                    ancestors[child].push_back(node);
                }

                // Add all the current node's ancestors to the child's ancestors list
                for (int ancestor : ancestors[node]) {
                    if (find(ancestors[child].begin(), ancestors[child].end(), ancestor) == ancestors[child].end()) {
                        ancestors[child].push_back(ancestor);
                    }
                }

                // Decrement the in-degree and if it becomes zero, push it to the queue
                if (--in_degrees[child] == 0) {
                    q.push(child);
                }
            }
        }

        for (auto& e_p : ancestors) {
            std::sort(e_p.begin(), e_p.end());\
        }

        return ancestors;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Solution 2
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n), ans(n);

        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj,ans,i,i);
        }
        
        return ans;
    }
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& ans, int& parent, int& child) {
        for (auto& ch: adj[child]) {
            if (ans[ch].size() == 0 || ans[ch].back() != parent) {
                ans[ch].push_back(parent);
                dfs(adj,ans,parent,ch);
            }
            
        }
    }
};
