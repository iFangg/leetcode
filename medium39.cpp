// Solution 1
class Solution {
public:
    bool dfs(const int& curr, std::unordered_map<int, std::unordered_set<int>>& graph, std::unordered_map<int, std::unordered_set<int>>& pred, std::unordered_set<int>& visited, std::unordered_set<int> path) {
        visited.insert(curr);
        path.insert(curr);
        for (auto& post_req : graph[curr]) {
            // std::cout << "post req is " << post_req << "\n";
            if (!visited.contains(post_req)) {
                visited.insert(post_req);
                // if (!pred.contains(post_req)) pred[post_req] = {curr};
                // else pred[post_req].insert(curr);
                if (!dfs(post_req, graph, pred, visited, path)) return false;
            } else {
                // std::cout << "cycle?\n";
                // if predecessors of neighbour does not include the current node, it's not a cycle
                // back track to find cycle?
                if (!path.contains(post_req)) return true;
                return false;
            }
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.empty()) return true;
        auto prereqs = std::unordered_map<int, std::unordered_set<int>>{};
        auto pred = std::unordered_map<int, std::unordered_set<int>>{};
        auto courses = std::vector<int>{};
        for (auto const& p : prerequisites) {
            auto& c = p.at(0);
            auto& pre = p.at(1);
            courses.push_back(c);
            courses.push_back(pre);
            if (!pred.contains(c)) pred[c] = {pre};
            else pred[c].insert(pre);
            if (!prereqs.contains(pre)) prereqs.insert({pre, {c}});
            else prereqs[pre].insert(c);
            // std::cout << "pre: " << pre << ", post courses: [ ";
            // for (auto& co : prereqs[pre]) {
            //     std::cout << co << " ";
            // }
            // std::cout << "]\n";
        }

        auto visited = std::unordered_set<int>{};
        auto queue = std::queue<int>{};
        std::sort(courses.begin(), courses.end());
        for (auto const& course : courses) {
            if (visited.contains(course)) continue;
            // std::cout << "current course (outer loop): " << course << "\n";
            if (!dfs(course, prereqs, pred, visited, {})) return false;
        }

        return true;
    }
};


// Solution 2
class Solution {
public:
    void getGraph(vector<vector<int>>& prereq, int numCourses, vector<vector<int>>& graph) {
        for (auto& edge : prereq) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
        }
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // BFS
        vector<vector<int>> graph(numCourses);
        getGraph(prerequisites, numCourses, graph);
        // Kahn's algo for topological sort
        // 1. Calculate indegree of each node
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto& neighbor : graph[i]) {
                indegree[neighbor] += 1;
            }
        }
        queue<int> Q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                Q.push(i);
            }
        }
        // BFS start
        int nodesCount = 0;
        while (!Q.empty()) {
            auto front = Q.front();
            Q.pop();
            nodesCount += 1;
            for (auto& neighbor : graph[front]) {
                indegree[neighbor] -= 1;
                if (indegree[neighbor] == 0) {
                    // all dependencies of the neighbor resolved meaning we can append it into the Q
                    Q.push(neighbor);
                }
            }
        }
        return nodesCount == numCourses;
    }
};
