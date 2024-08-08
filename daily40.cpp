// Solution 1 - FAIL
class Solution {
public:
    unordered_map<char, char> dijkstra(unordered_map<char, vector<pair<char, int>>>& edges, char source, char target, string original) {
        auto dist = unordered_map<char, long>{};
        auto preds = unordered_map<char, char>{};
        auto cmp = [](pair<long, char> left, pair<long, char> right) { return left.first > right.first; };
        auto pq = priority_queue<pair<long, char>, vector<pair<long, char>>, decltype(cmp)>(cmp);

        dist[source] = 0;
        for (auto& c : original) {
            if (c == source)
                continue;
            dist[c] = numeric_limits<long>::max();
        }
        pq.push({0, source});

        while (!pq.empty()) {
            auto [current_dist, u] = pq.top();
            pq.pop();

            if (u == target)
                break;

            for (auto& edge : edges[u]) {
                char v = edge.first;
                int weight = edge.second;
                long alt = dist[u] + weight;

                if (alt < dist[v]) {
                    dist[v] = alt;
                    preds[v] = u;
                    pq.push({alt, v});
                }
            }
        }

        return preds;
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // weighted graph, edge is cost, nodes are letters
        // hashmap for nodes -> letter: change, cost
        // keep track of which letters to change
        // dijkstra's to find shortest path (and path cost)?
        auto to_change = std::vector<int>{};
        for (auto i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                to_change.push_back(i);
            }
        }

        if (to_change.size() > original.size())
            return -1;

        auto edges = std::unordered_map<char, std::vector<std::pair<char, int>>>{};
        for (auto i = 0; i < original.size(); ++i) {
            if (!edges.count(original[i])) {
                edges[original[i]] = std::vector<std::pair<char, int>>{};
            }

            edges[original[i]].push_back(std::make_pair(changed[i], cost[i]));
        }

        auto total = int{0};
        for (auto& i : to_change) {
            auto shortest_path = dijkstra(edges, source[i], target[i], source);
            auto node = target[i];
            for (auto& [k, v] : shortest_path) {
                std::cout << "curr: " << k << ", predecessor: " << v << std::endl;
            }
            while (node != source[i] and node != '\0') {
                std::cout << "curr node is " << node << std::endl;
                auto weight = 0;
                for (auto& e : edges[shortest_path[i]]) {
                    if (e.first == i) {
                        weight = e.second;
                        break;
                    }
                }
                total += weight;

                node = shortest_path[node];
            }

        }

        return total;
    }
};

// Solution 2 - Floyd Warshall
class Solution {
public:
    // Function to find the minimum cost to transform source to target
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int inf = 1 << 29; // Define a large constant to represent infinity (sufficiently large number)
        int g[26][26]; // Adjacency matrix to store minimum transformation costs between characters

        // Initialize the adjacency matrix
        for (int i = 0; i < 26; ++i) {
            fill(begin(g[i]), end(g[i]), inf); // Set all values to infinity
            g[i][i] = 0; // The cost to transform a character to itself is 0
        }

        // Populate the adjacency matrix with given transformation costs
        for (int i = 0; i < original.size(); ++i) {
            int x = original[i] - 'a'; // Convert character to index (0-25)
            int y = changed[i] - 'a'; // Convert character to index (0-25)
            int z = cost[i]; // Transformation cost
            g[x][y] = min(g[x][y], z); // Take the minimum cost if multiple transformations are given
        }

        // Apply the Floyd-Warshall algorithm to find the shortest path between all pairs of characters
        for (int k = 0; k < 26; ++k) { // Intermediate character
            for (int i = 0; i < 26; ++i) { // Start character
                for (int j = 0; j < 26; ++j) { // End character
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]); // Update with the minimum cost
                }
            }
        }

        long long ans = 0; // Variable to store the total minimum cost
        int n = source.length(); // Length of the source (and target) string

        // Calculate the total minimum cost to transform source to target
        for (int i = 0; i < n; ++i) {
            int x = source[i] - 'a'; // Convert source character to index
            int y = target[i] - 'a'; // Convert target character to index
            if (x != y) { // If characters are different
                if (g[x][y] >= inf) { // If no valid transformation path exists
                    return -1; // Return -1 indicating the transformation is not possible
                }
                ans += g[x][y]; // Add the cost of transforming source[i] to target[i]
            }
        }
        return ans; // Return the total minimum cost
    }
};


// Solution 3 - Dijkstra's
class Solution {
public:
    using int2 = pair<int, int>;
    array<vector<int2>, 26> adj;
    int D[26][26];

    void Dijkstra(int x) {
        int* dist=D[x];
        // minHeap pq  initializing  with all adj[x]
        priority_queue<int2, vector<int2>, greater<int2>> pq(adj[x].begin(), adj[x].end());
        while (!pq.empty()) {
            auto [d, i] = pq.top();
            pq.pop();
            if (d > dist[i])
                continue;
            for (auto& [w, j] : adj[i]) {
                int d2 = d + w;
                if (d2 < dist[j]) {
                    dist[j] = d2;
                    pq.emplace(d2, j);
                }
            }
        }
    }

    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Initialize D with infinity
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX);
        for (int i=0; i<26; i++) D[i][i]=0;

        const int sz = original.size();
        for (int i = 0; i < sz; i++) {
            int row=original[i]-'a';
            int col=changed[i]-'a';
            D[row][col]=min(D[row][col], cost[i]);
        }

        for (int i=0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (D[i][j] != INT_MAX && i!= j) {
                    adj[i].emplace_back(D[i][j], j);
                }
            }
        }

        for (int i= 0; i< 26; i++) {
            Dijkstra(i);
        }

        const int n = source.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int row = source[i] - 'a';
            int col = target[i] - 'a';
            if (D[row][col] == INT_MAX) return -1;
            ans += D[row][col];
        }
        return ans;
    }
};
