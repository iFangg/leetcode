#include <queue>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <array>

// Solution 1
class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        /*
            visited array for seen islands
            topological sort nodes?
            bfs traversal for each starting node of islands (topo-sort unnecessary if we're looking at all the nodes anyways)
        */

        auto islands = 0;
        auto visited = std::vector<std::vector<int>>(grid.size(), std::vector<int>(grid[0].size(), 0));
        auto queue = std::queue<std::pair<int, int>>{};
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0')
                    continue;

                if (!visited[i][j]) {
                    visited[i][j] = 1;
                    queue.push(std::make_pair(i, j));
                    islands++;
                } else
                    continue;

                while (!queue.empty()) {
                    auto node = queue.front();
                    auto& row = node.first;
                    auto& col = node.second;
                    queue.pop();

                    auto neighbours = std::vector<std::pair<int, int>>{};
                    if (row - 1 >= 0 and grid[row - 1][col] == '1') {
                        neighbours.push_back(std::make_pair(row - 1, col));
                    }
                    
                    if (row + 1 < grid.size() and grid[row + 1][col] == '1') {
                        neighbours.push_back(std::make_pair(row + 1, col));
                    }

                    if (col - 1 >= 0 and grid[row][col - 1] == '1') {
                        neighbours.push_back(std::make_pair(row, col - 1));
                    }
                    
                    if (col + 1 < grid[0].size() and grid[row][col + 1] == '1') {
                        neighbours.push_back(std::make_pair(row, col + 1));
                    }

                    for (auto& n : neighbours) {
                        auto& r = n.first;
                        auto& c = n.second;
                        if (!visited[r][c]) {
                            visited[r][c] = 1;
                            queue.push(n);
                        }
                    }
                }
            }
        }

        return islands;
    }
};

// Solution 2
class Solution {
public:

    // DFS from grid (i, j) and marked the connected grids as 0 (for visited)
    void DFS(std::vector<std::vector<char>>& grid, int i, int j){
        if(grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        if(i - 1 >= 0)
            DFS(grid, i - 1, j);
        if(i + 1 < grid.size())
            DFS(grid, i + 1, j);
        if(j - 1 >= 0)
            DFS(grid, i, j - 1);
        if(j + 1 < grid[i].size())
            DFS(grid, i, j + 1);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int numIsland = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == '1'){
                    DFS(grid, i, j);
                    numIsland += 1;
                }
            }
        }
        return numIsland;
    }
};

// Solution 3 - wizard
#pragma GCC optimize("O3,unroll-loops")

static const bool Booster = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return true;
}();

constexpr int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
static std::array<std::bitset<300>, 300> grid;
static std::array<std::bitset<300>, 300> visited;
static int rows;
static int cols;

void parse_input_data_string(const std::string& s) {
    const int N = s.size();
    rows = 0;
    cols = 0;

    int col;
    for (int i = 1; i < N - 1; ++i) {
        switch (s[i]) {
            case '[':
                col = 0;
                break;
            case ']':
                cols = col;
                ++rows;
                break;
            case '0':
                grid[rows].reset(col);
                ++col;
                break;
            case '1':
                grid[rows].set(col);
                ++col;
                break;
        }
    }
    for (int i = 0; i < rows; ++i) {
        visited[i].reset();
    }
}

void visitIsland(int i, int j) {
    if(grid[i][j] == 0 || visited[i][j] == 1) {
        return;
    }
    visited[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        const int in = i + d[k][1];
        const int jn = j + d[k][0];
        if (in >= 0 && in < rows && jn >= 0 && jn < cols) {
            visitIsland(in, jn);
        }
    }
}

int numIslands() {       
    int res = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 0 || visited[i][j] == 1) {
                continue;
            }
            visitIsland(i, j);
            res++;
        }
    }
    return res;
}

bool Solve = [](){
    std::ofstream out("user.out");
    for (std::string s; std::getline(std::cin, s);) {
        parse_input_data_string(s);
        out << numIslands() << "\n";
    }
    out.flush();
    exit(0);
    return true;
}();

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        return 0;
    }
};
