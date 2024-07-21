// Solution 1 - FAIL
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> graph;
        for (const auto& edge : rowConditions) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> row_sorting = topo_sort(graph, k);
        graph.clear();
        for (const auto& edge : colConditions) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<int> col_sorting = topo_sort(graph, k);

        if (row_sorting.empty() || col_sorting.empty()) {
            return {};
        }

        unordered_map<int, pair<int, int>> value_position;
        for (int i = 0; i < k; ++i) {
            value_position[row_sorting[i]].first = i;
            value_position[col_sorting[i]].second = i;
        }

        vector<vector<int>> res(k, vector<int>(k, 0));
        for (int value = 1; value <= k; ++value) {
            int row = value_position[value].first;
            int column = value_position[value].second;
            res[row][column] = value;
        }

        return res;
    }

private:
    bool dfs(int src, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, unordered_set<int>& cur_path, vector<int>& res) {
        if (cur_path.count(src)) return false;  // cycle detected
        if (visited.count(src)) return true;  // all okay, but we've already visited this node

        visited.insert(src);
        cur_path.insert(src);

        for (int neighbor : graph[src]) {
            if (!dfs(neighbor, graph, visited, cur_path, res))  // if any child returns false
                return false;
        }

        cur_path.erase(src);  // backtrack path
        res.push_back(src);
        return true;
    }

    vector<int> topo_sort(unordered_map<int, vector<int>>& graph, int k) {
        unordered_set<int> visited;
        unordered_set<int> cur_path;
        vector<int> res;

        for (int src = 1; src <= k; ++src) {
            if (!dfs(src, graph, visited, cur_path, res))
                return {};
        }

        reverse(res.begin(), res.end());  // we will have res as reversed so we need to reverse it one more time
        return res;
    }
};


// Solution 2
class Solution {
public:
    bool buildGraph(vector<vector<int> >& arr, int n, vector<int>& data) {
        vector<int> adj[n + 1];
        vector<int> indeg(n + 1, 0);
        for(auto& curr: arr) {
            adj[curr[0]].push_back(curr[1]);
            indeg[curr[1]]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            data.push_back(node);
            for(auto& x: adj[node]) {
                if(--indeg[x] == 0) {
                    q.push(x);
                }
            }
        }
        return data.size() == n;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> topoRow, topoCol;
        if(!buildGraph(rowConditions, k, topoRow) || !buildGraph(colConditions, k, topoCol)) {
            return {};
        }
        
        int row[k + 1], col[k + 1];
    
        
        for(int i = 0; i < k; i++) {
            row[topoRow[i]] = i;
            col[topoCol[i]] = i;
        }
        
        vector<vector<int> > arr(k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++) {
            arr[row[i]][col[i]] = i;
        }
        return arr;
        
    }
};
