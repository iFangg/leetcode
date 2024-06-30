// Solution INVALID
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // create separate graphs for alice and bob
        auto alice_edges = std::vector<vector<int>>{};
        auto alice_nodes = std::unordered_set<int>{};
        auto bob_edges = std::vector<vector<int>>{};
        auto bob_nodes = std::unordered_set<int>{};
        auto total = int{0};
        auto extras = int{0};
        for (auto e : edges) {
            auto edge = std::vector<int>{e[1], e[2]};
            if (e[0] == 3) {
                total++;
                if (std::find(alice_edges.begin(), alice_edges.end(), edge) == alice_edges.end())
                    alice_edges.push_back(edge);
                else
                    extras++;
                if (std::find(bob_edges.begin(), bob_edges.end(), edge) == bob_edges.end())
                    bob_edges.push_back(edge);
                else
                    extras++;
                alice_nodes.insert(edge[0]);
                alice_nodes.insert(edge[1]);
                bob_nodes.insert(edge[0]);
                bob_nodes.insert(edge[1]);
            }

            if (e[0] == 1) {
                if (std::find(alice_edges.begin(), alice_edges.end(), edge) == alice_edges.end())
                    alice_edges.push_back(edge);
                else
                    extras++;
                alice_nodes.insert(edge[0]);
                alice_nodes.insert(edge[1]);
            }
            if (e[0] == 2) {
                if (std::find(bob_edges.begin(), bob_edges.end(), edge) == bob_edges.end())
                    bob_edges.push_back(edge);
                else
                    extras++;
                bob_nodes.insert(edge[0]);
                bob_nodes.insert(edge[1]);
            }
        }

        std::cout << "blue edges: " << total << "\n";
        std::cout << "redundant edges: " << extras << "\n";
        // std::cout << "alice has how many edges? " << alice_edges.size() << "\n";
        // std::cout << "bob has how many edges? " << bob_edges.size() << "\n";

        if (bob_nodes.size() != n or alice_nodes.size() != n) return -1;

        auto similar_edges = int{0};
        for (auto edge : alice_edges) {
            // std::cout << "edge: [" << edge[0] << ", " << edge[1] << "]\n";
            if (std::find(bob_edges.begin(), bob_edges.end(), edge) != bob_edges.end()) similar_edges++;
        }
        std::cout << "similar edges " << similar_edges << "\n";

        if (similar_edges == alice_edges.size()) return extras;

        return similar_edges;
    }
};


// Solution 1 - Union Find/Disjoint Set Union
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        class UnionFind {
        public:
            vector<int> parent, size;
            int components;
            UnionFind(int n) {
                components = n;
                parent.resize(n + 1);
                size.resize(n + 1, 1);
                for (int i = 0; i <= n; ++i) {
                    parent[i] = i;
                }
            }

            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }

            bool unite(int x, int y) {
                int rootX = find(x), rootY = find(y);
                if (rootX == rootY) return false;
                if (size[rootX] < size[rootY]) swap(rootX, rootY);
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                components--;
                return true;
            }

            bool isConnected() {
                return components == 1;
            }
        };
        
        UnionFind alice(n), bob(n);
        int edgesRequired = 0;
        
        // Process type 3 edges first
        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (alice.unite(edge[1], edge[2]) | bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Process type 1 and type 2 edges
        for (const auto& edge : edges) {
            if (edge[0] == 1) {
                if (alice.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            } else if (edge[0] == 2) {
                if (bob.unite(edge[1], edge[2])) {
                    edgesRequired++;
                }
            }
        }
        
        // Check if both are fully connected
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edgesRequired;
        }
        
        return -1;
    }
};
