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
