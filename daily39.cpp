// Solution 1 - FAIL
class Solution {
public:
    void dfs(int& n, vector<vector<int>>& edges, int& threshold, unordered_map<int, vector<int>>& neighbours, unordered_map<int, int>& reachable, int& city, int curr, int curr_dist, vector<int>& visited) {
        if (city == 1) {
            std::cout << "curr path: ";
            for (auto& c : visited) {
                std::cout << c << " ";
            }
            std::cout << "total dist is " << curr_dist << std::endl;
        }
        
        if (curr_dist > threshold) {
            return;
        } else {
            if (city != curr)
                reachable[city]++;
        }

        
        for (auto i = 0; i < n; ++i) {
            if (i == curr)
                continue;
            
            if (!neighbours[curr][i])
                continue;
            

            if (std::find(visited.begin(), visited.end(), i) == visited.end()) {
                visited.push_back(i);
                dfs(n, edges, threshold, neighbours, reachable, city, i, curr_dist + neighbours[curr][i], visited);
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // map all cities reachable within threshold to a city
        // traverse (dfs/bfs) from each node to determine which cities are within threshold
        // keep track of max cities reachable within threshold
            // -> how many cities are accessible in one path/spanning tree
            // keep track of max reachable cities from city C in any one path
        
        auto neighbours = std::unordered_map<int, std::vector<int>>{};
        auto reachable = std::unordered_map<int, int>{};

        for (auto i = 0; i < n; ++i) {
            neighbours[i] = std::vector<int>(n, 0);
            reachable[i] = 0;
        }

        for (auto& e : edges) {
            neighbours[e[0]][e[1]] = e[2];
            neighbours[e[1]][e[0]] = e[2];
        }

        for (auto i = 0; i < n; ++i) {
            auto dist = int{0};
            auto travelled = std::vector<int>{i};
            dfs(n, edges, distanceThreshold, neighbours, reachable, i, i, dist, travelled);
        }

        auto min = INT_MAX;
        for (auto& [k, v] : reachable) {
            std::cout << "city " << k << ", most cities reachable is " << v << std::endl;
            min = std::min(min, v);
        }

        auto max = int{0};
        for (auto& [k, v] : reachable) {
            if (v != min)
                continue;
            
            max = std::max(max, k);
        }
        return max;
    }
}


// Solution 2
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // first convert graph to adjacency list representation
        vector<vector<pair<int, int>>> graph(n); // i-th nodes will have graph[i] neighbors
        for (const auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1], distance = edge[2];
            graph[node1].emplace_back(node2, distance);
            graph[node2].emplace_back(node1, distance);
        }

        auto get_number_of_neighbors_in_distance = [&](int source) -> int {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> queue;
            queue.emplace(0, source); // distance to node itself is 0
            set<int> visited;

            while (!queue.empty()) {
                auto [distance_to_this_node, cur_node] = queue.top();
                queue.pop();
                if (!visited.count(cur_node)) {
                    visited.insert(cur_node);
                    for (const auto& [neighbor, distance] : graph[cur_node]) {
                        int distance_from_source = distance_to_this_node + distance;
                        if (distance_from_source <= distanceThreshold) { // ensure that we're allowed to go to this node
                            queue.emplace(distance_from_source, neighbor);
                        }
                    }
                }
            }
            // actually you can return visited.size() and with math there will be nothing wrong but actually we have visited.size() - 1 neighbors since we're not neighbor of ourselves
            return visited.size() - 1;
        };

        int minimum_number = n;
        int res = -1;

        for (int source = 0; source < n; ++source) {
            int neighbors = get_number_of_neighbors_in_distance(source);
            // we iterate source from smaller to bigger this ensures that we choose node with greater value if they have equal number of neighbors
            if (neighbors <= minimum_number) {
                minimum_number = neighbors;
                res = source;
            }
        }

        return res;
    }
};


// Solution 3
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            matrix[u][v]=w;
            matrix[v][u]=w;
        }
        for(int i=0;i<n;i++){
            matrix[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        vector<int>dist(n,0);
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                 if(matrix[i][j]<=distanceThreshold){
                    c++;
                 }
            }
            dist[i]=c;
        }
        int min=dist[0],node=0;
        for(int i=1;i<n;i++){
          if(dist[i]<=min){
            min=dist[i];
            node=i;
          }
        }
        return node;
    }
};

