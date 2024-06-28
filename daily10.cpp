// Solution 1
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // start at any node, traverse to the other side and take middle node as centre
        auto path = std::vector<int>{edges[0][0]};
        auto curr = edges[0][1];
        for (auto i = 1; i < edges.size(); ++i) {
            if (edges[i][0] != curr and edges[i][1] != curr) continue;
            if (edges[i][0] == curr) {
                path.push_back(edges[i][0]);
                curr = edges[i][1];
            } else if (edges[i][1] == curr) {
                path.push_back(edges[i][1]);
                curr = edges[i][0];
            }
        }
        path.push_back(curr);

        // std::cout << "path through graph is: ";
        // for (auto i = path.begin(); i != path.end(); ++i) {
        //     std::cout << *i << " ";
        // }
        // std::cout << "\n";
        // std::cout << path[(path.size() / 2)] << "\n";
        
        if (path.size() % 2 == 1) return path[(path.size() / 2)];
        else return path[0];
    }
};


// Solution 2
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};
