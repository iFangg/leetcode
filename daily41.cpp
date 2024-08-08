// Solution 1 - FAIL
class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& graph, unordered_map<int, vector<int>>& preds, int& time, int& change, int& n, vector<int>& times, int node, int curr_time, unordered_set<int>& visited) {
        std::cout << "curr node is: " << node << std::endl;
        if (node == n) {
            times.push_back(curr_time);
            for (auto i = 0; i < 2; ++i) {
                if ((curr_time / change) % 2 == 1) {
                    curr_time += change - (curr_time % change);
                    curr_time += time;
                }
            }
            
            times.push_back(curr_time);
            return;
        }

        if (visited.count(node))
            return;
        
        visited.insert(node);
        if ((curr_time / change) % 2 == 1) {
            curr_time += change - (curr_time % change);
        }

            std::cout << "neighbours of " << node << " are:";
        for (auto& neighb : graph[node]) {
            std::cout << neighb << " ";
            dfs(graph, preds, time, change, n, times, neighb, curr_time + time, visited);
        }
    }

    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // dfs, keeping track of current time and if light has changed from green to red
        // change -> if current time / change is even or 0 its green, if its odd its red
        // if red, add remaining time til next change and then keep traversing
        // keep total time of shortest path (from dfs)
        // base case of only one path, traverse once more between target and target's predecessor.

        auto neighbours = std::unordered_map<int, std::vector<int>>{};
        auto preds = std::unordered_map<int, std::vector<int>>{};
        for (auto& e : edges) {
            if (!neighbours.count(e[0]))
                neighbours[e[0]] = std::vector<int>{};

            if (!preds.count(e[1]))
                preds[e[1]] = std::vector<int>{};
            
            neighbours[e[0]].push_back(e[1]);
            preds[e[1]].push_back(e[0]);
        }
        
        for (const auto& pair : neighbours) {
            // Print the key
            std::cout << "Node " << pair.first << ": ";
            // Iterate over the vector
            for (const int& neighbour : pair.second) {
                std::cout << neighbour << " ";
            }
            std::cout << std::endl;
        }

        for (const auto& pair : preds) {
            // Print the key
            std::cout << "Predecessors of Node " << pair.first << ": ";
            // Iterate over the vector
            for (const int& neighbour : pair.second) {
                std::cout << neighbour << " ";
            }
            std::cout << std::endl;
        }

        auto times = std::vector<int>{};
        auto visited = std::unordered_set<int>{1};
        dfs(neighbours, preds, time, change, n, times, 1, 0, visited);

        std::cout << times.size() << std::endl;
        std::sort(times.begin(), times.end());

        return times[1];
    }
};


// Solution 2
// This lambda function is used to optimize the input/output speed
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false); // Disable synchronization between C++ and C I/O streams
    std::cin.tie(nullptr); // Untie cin from cout, so cin doesn't wait for cout to flush
    std::cout.tie(nullptr); // Untie cout from cin, so cout doesn't wait for cin to flush
    return 0;
}();

// Solution class encapsulating the problem solution
class Solution {
    // Helper function to calculate the total time to travel 'needed' segments considering traffic light changes
    static constexpr int howLong(int needed, int time, int change) {
        int ans = 0; // Initialize total time
        for (int i = 0; i < needed; i++) {
            int turn = ans / change; // Calculate the current "turn" based on change interval
            if ((turn % 2) != 0) // If it's a red light (odd turn)
                ans += change - (ans % change); // Wait until green light

            ans += time; // Add the time to travel one segment
        }
        return ans; // Return the total time
    }
public:
    // Main function to find the second minimum time to travel from node 1 to node N
    static int secondMinimum(int N, const vector<vector<int>>& edges, int time, int change) {
        // Build the adjacency list for the graph
        std::vector<std::vector<int>> G(N);
        for (const auto& edge : edges) {
            G[edge[0] - 1].push_back(edge[1] - 1);
            G[edge[1] - 1].push_back(edge[0] - 1);
        }

        // Deque for BFS traversal, initialized with the starting node
        std::deque<int> Q;
        // Vector to track if a node has been seen at even or odd waves
        std::vector<char> seen(N * 2);
        Q.push_front(0); // Start from node 0 (which is node 1 in the problem statement)
        seen[0] = true;

        // Maximum length initialized to a large value
        int maxLength = std::numeric_limits<int>::max();

        int wave = 0; // Initialize wave counter
        bool odd = true; // Start with the odd wave (true -> odd, false -> even)
        while (!Q.empty()) {
            const int thisRound = Q.size(); // Number of nodes to process in this wave
            odd = !odd; // Toggle between odd and even wave
            for (int i = 0; i < thisRound; i++) {
                auto pos = Q.front();
                Q.pop_front();

                if (pos == N - 1) { // If we've reached the last node
                    if (maxLength == std::numeric_limits<int>::max()) {
                        maxLength = wave + 2; // Set initial maxLength
                        continue;
                    } else {
                        maxLength = std::min(maxLength, wave); // Update maxLength if current path is shorter
                        return howLong(maxLength, time, change); // Calculate and return the travel time
                    }
                }

                for (const auto next : G[pos]) { // Traverse all neighbors
                    if (seen[next * 2 + !odd]) // Skip if already seen in this wave type
                        continue;

                    seen[next * 2 + !odd] = true; // Mark as seen for this wave type
                    Q.push_back(next); // Add neighbor to the deque
                }
            }
            wave++; // Increment wave counter

            if (maxLength < wave) // If wave exceeds maxLength, exit the loop
                break;
        }

        return howLong(maxLength, time, change); // Calculate and return the travel time
    }
};


// Solution 3
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create the graph using an unordered_map of lists
        unordered_map<int, list<int>> g;
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 1});  // (time, node)

        vector<int> uniqueVisit(n + 1, 0);  // To track the number of unique visits
        vector<int> dis(n + 1, -1);  // To store the minimum time to reach each node
        
        while (!q.empty()) {
            auto [t, node] = q.top();
            q.pop();  // Get the node with the smallest time
            
            if (dis[node] == t || uniqueVisit[node] >= 2) {
                continue;  // Skip if already visited or relaxed twice
            }
            
            uniqueVisit[node]++;
            dis[node] = t;
            
            if (node == n && uniqueVisit[node] == 2) {
                return dis[node];
            }
            
            // Calculate the leaving time (waiting for the green light)
            if ((t / change) % 2 != 0) {
                t = (t / change + 1) * change;
            }
            
            for (int nei : g[node]) {
                q.push({t + time, nei});
            }
        }
        
        return -1;
    }
};
