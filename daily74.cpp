// Solution 1 - FAIL
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        /*
        map nodes and edges to graph
        dijkstras to find shortest path between start and end nodes
        track target and minus edge weights for all non -1 edges
        */

        visited_ = std::vector<int>(n, 0);
        distances_ = std::vector<int>(n, INT_MAX);
        edges_ = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        prev_ = std::vector<int>(n, -1);
        neighbours_ = std::vector<std::unordered_set<int>>(n, std::unordered_set<int>{});
        distances_[source] = 0;

        for (auto& e : edges) {
            edges_[e[0]][e[1]] = e[2];
            edges_[e[1]][e[0]] = e[2];

            neighbours_[e[0]].insert(e[1]);
            neighbours_[e[1]].insert(e[0]);
        }

        auto unset_edges = std::vector<std::vector<int>>{};
        dijkstra(source, target, unset_edges);
        std::cout << "remaining target is: " << target << std::endl;

        auto in_path = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        auto node = destination;
        auto& prev = prev_[node];
        auto new_edges = std::vector<std::vector<int>>{};
        if (prev != -1 and node == source) {
            in_path[prev][node] = 1;

            while (prev != -1) {
                in_path[prev][node] = 1;
                if (edges_[prev][node] != -1) {
                    target -= edges_[prev][node];
                    new_edges.push_back(std::vector<int>{node, prev, edges_[prev][node]});
                }

                auto temp = prev;
                prev = prev_[prev];
                node = temp;
            }
        }

        if (!unset_edges.empty()) {
            if (target < unset_edges.size())
                return {};

            if (target % unset_edges.size() == 0) {
                for (auto& e : unset_edges) {
                    new_edges.push_back(std::vector<int>{e[0], e[1], static_cast<int>(target / unset_edges.size())});
                }
            } else {
                for (auto i = 0; i < unset_edges.size() - 1; ++i) {
                    new_edges.push_back(std::vector<int>{unset_edges[i][0], unset_edges[i][1], 1});
                    target--;
                }

                auto last = unset_edges.back();
                new_edges.push_back(std::vector<int>{last[0], last[1], target});
            }
        }


        if (node != destination)
            return {};
        
        return new_edges;
    }

private:
    void dijkstra(int source, int target, std::vector<std::vector<int>>& unset) {
        auto node_distances = distances_;
        auto cmp = [&node_distances](std::pair<int, int> l, std::pair<int, int> r) {
            return node_distances[l.first] > node_distances[r.first];
        };
        
        // auto q = std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)>{};
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> q(cmp, std::vector<std::pair<int, int>>());
        q.push(std::make_pair(source, target));

        while (!q.empty()) {
            auto node = q.top();
            auto curr = node.first;
            q.pop();

            std::cout << "current node is: " << curr << std::endl;
            for (auto& n : neighbours_[curr]) {
                // std::cout << "neighbour of " << curr << " is " << n << std::endl;
                if (!visited_[n]) {
                    // std::cout << "unvisited\n";
                    if (edges_[curr][n] == -1) {
                        distances_[n] = distances_[curr];
                        prev_[n] = curr;
                        unset.push_back(std::vector<int>{curr, n});
                        q.push(std::make_pair(n, target));
                    } else {
                        auto dist = distances_[curr] + edges_[curr][n];
                        std::cout << "total distance from source to " << n << " - " << dist << std::endl;
                        if (dist < distances_[n]) {
                            std::cout << "hi\n";
                            distances_[n] = dist;
                            prev_[n] = curr;
                        }
                        
                        q.push(std::make_pair(n, target - dist));
                    }
                }
            }

            visited_[curr] = 1;
        }
    }

    std::vector<int> visited_;
    std::vector<int> distances_;
    std::vector<std::vector<int>> edges_;
    std::vector<int> prev_;
    std::vector<std::unordered_set<int>> neighbours_;
};


// Solution 2
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < edges.size(); i++) {
            int nodeA = edges[i][0], nodeB = edges[i][1];
            adjacencyList[nodeA].emplace_back(nodeB, i);
            adjacencyList[nodeB].emplace_back(nodeA, i);
        }

        vector<vector<int>> distances(n, vector<int>(2, INT_MAX));
        distances[source][0] = distances[source][1] = 0;

        runDijkstra(adjacencyList, edges, distances, source, 0, 0);
        int difference = target - distances[destination][0];
        if (difference < 0) return {}; 
        runDijkstra(adjacencyList, edges, distances, source, difference, 1);
        if (distances[destination][1] < target) return {}; 

        for (auto& edge : edges) {
            if (edge[2] == -1) edge[2] = 1;
        }
        return edges;
    }

private:
    void runDijkstra(const vector<vector<pair<int, int>>>& adjacencyList, vector<vector<int>>& edges, vector<vector<int>>& distances, int source, int difference, int run) {
        int n = adjacencyList.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> priorityQueue;
        priorityQueue.push({0, source});
        distances[source][run] = 0;

        while (!priorityQueue.empty()) {
            auto [currentDistance, currentNode] = priorityQueue.top();
            priorityQueue.pop();

            if (currentDistance > distances[currentNode][run]) continue;

            for (auto& neighbor : adjacencyList[currentNode]) {
                int nextNode = neighbor.first, edgeIndex = neighbor.second;
                int weight = edges[edgeIndex][2];

                if (weight == -1) weight = 1; 

                if (run == 1 && edges[edgeIndex][2] == -1) {
                    int newWeight = difference + distances[nextNode][0] - distances[currentNode][1];
                    if (newWeight > weight) {
                        edges[edgeIndex][2] = weight = newWeight;
                    }
                }

                if (distances[nextNode][run] > distances[currentNode][run] + weight) {
                    distances[nextNode][run] = distances[currentNode][run] + weight;
                    priorityQueue.push({distances[nextNode][run], nextNode});
                }
            }
        }
    }
};
static const auto mynameisbarryallen = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
