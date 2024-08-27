// Solution 1 - too slow FAIL
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // dfs from any starting node to find all possible paths
        // compute graph
        // iterate through all immediate neighbours for 2nd point
            //  and traverse thru graph to find all probabilities 
        
        for (auto i = 0; i < edges.size(); ++i) {
            auto& to = edges[i][0];
            auto& from = edges[i][1];
            if (!neighbours_.count(to))
                neighbours_[to] = std::vector<std::pair<int, double>>{};

            if (!neighbours_.count(from))
                neighbours_[from] = std::vector<std::pair<int, double>>{};
            
            neighbours_[to].push_back(std::make_pair(from, succProb[i]));
            neighbours_[from].push_back(std::make_pair(to, succProb[i]));
        }

        probs_.resize(100);

        for (auto& n : neighbours_[start_node]) {
            auto visited = std::unordered_set<int>{start_node};
            dfs(n.first, end_node, visited, n.second);
        }

        return *std::max_element(probs_.begin(), probs_.end());
    }

private:
    void dfs(int node, int target, std::unordered_set<int>& visited, double prob) {
        // std::cout << "current node is " << node << std::endl;
        if (node == target) {
            probs_.push_back(prob);
            return;
        }
        
        for (auto& n : neighbours_[node]) {
            // std::cout << "neighbour: " << n.first << std::endl;
            if (!visited.count(n.first)) {
                visited.insert(n.first);
                dfs(n.first, target, visited, prob * n.second);
                visited.erase(n.first);
            }
        }
    }

    std::vector<double> probs_;
    std::unordered_map<int, std::vector<std::pair<int, double>>> neighbours_;
};


// Solution 2 - bfs
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build the graph
        for (auto i = 0; i < edges.size(); ++i) {
            int to = edges[i][0];
            int from = edges[i][1];
            neighbours_[to].emplace_back(from, succProb[i]);
            neighbours_[from].emplace_back(to, succProb[i]);
        }

        // Perform BFS
        return bfs(start_node, end_node);
    }

private:
    double bfs(int start_node, int target) {
        std::queue<std::pair<int, double>> q;
        q.push({start_node, 1.0});

        std::unordered_map<int, double> maxProb;  // To store the maximum probability to reach each node
        maxProb[start_node] = 1.0;

        while (!q.empty()) {
            auto [curr_node, curr_prob] = q.front();
            q.pop();

            if (curr_node == target) {
                continue;
            }

            for (auto& [neighbor, edge_prob] : neighbours_[curr_node]) {
                double new_prob = curr_prob * edge_prob;
                if (new_prob > maxProb[neighbor]) {
                    maxProb[neighbor] = new_prob;
                    q.push({neighbor, new_prob});
                }
            }
        }

        if (maxProb.contains(target))
            return maxProb[target];

        return 0.0;  // Return 0 if there's no path to the target
    }

    std::unordered_map<int, std::vector<std::pair<int, double>>> neighbours_;
};

// Solution 3 - dijkstras
class Solution {
public:
    using v = pair<double, int>;
    vector<vector<v>> adj;

    inline void create_adj(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        adj.resize(n);
        int eN = edges.size();
        for (int i = 0; i < eN; i++) {
            int v0 = edges[i][0], v1 = edges[i][1];
            adj[v0].push_back({succProb[i], v1});
            adj[v1].push_back({succProb[i], v0});
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);
        create_adj(n, edges, succProb);
        priority_queue<v, vector<v>> pq;
       
        pq.push({1.0, start});
        prob[start] = 1.0;

        while (!pq.empty()) {
            auto [cur_prob, i] = pq.top();
            pq.pop();
            if (i == end) 
                return cur_prob;

            for (auto [next_prob, j] : adj[i]) {
                double new_prob = cur_prob * next_prob;
                if (new_prob > prob[j]) {
                    prob[j] = new_prob;
                    pq.push({new_prob, j});
                }
            }
        }
        return 0.0;
    }
};

