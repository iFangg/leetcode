#include <vector>
#include <unordered_set>
#include <string>

// Solution 1.A - FAIL
class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        /*
        graph representation? 
            treat empty squares and braces as different nodes

        grid representation?
            n values becomes 3n x 3n square
            blanks give 3 blank spaces
            slashes give blank - slash - blank
            find all islands cut off by slashes
        */
        
        auto len = grid[0].size();
        auto sections = std::vector<std::vector<std::string>>(3 * len, std::vector<std::string>(3 * len, ""));
        auto to_visit = std::vector<std::pair<int, int>>{};

        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != ' ') {
                    sections[i][3 * j + 1] = grid[i][j];
                    to_visit.push_back(std::make_pair(i, j - 1));
                    to_visit.push_back(std::make_pair(i, j + 1));
                }
            }
        }

        auto explored = std::unordered_set<std::pair<int, int>>{};
        for (auto& point : to_visit) {
            if (explored.contains(point))
                continue;
            
            dfs(point, sections, explored);
            regions++;
        }

        return regions;
    }

private:
    int regions = 0;
    
    void dfs(std::pair<int, int> point, std::vector<std::vector<std::string>>& sections, std::unordered_set<std::pair<int, int>>& explored) {
        if (sections[point.first][point.second] == "/" or sections[point.first][point.second] == "\\")
            return;
        
        for (auto i = -1; i <= 1; i += 2) {
            if (i + point.first < 0 or i + point.first >= sections.size()) {
                continue;
            }

            auto neighb = std::make_pair(point.first + i, point.second);
            if (!explored.contains(neighb)) {
                explored.insert(neighb);
                dfs(neighb, sections, explored);
            }
        }

        for (auto j = -1; j <= 1; j += 2) {
            if (j + point.second < 0 or j + point.second >= sections[0].size()) {
                continue;
            }

            auto neighb = std::make_pair(point.first, point.second + j);
            if (!explored.contains(neighb)) {
                explored.insert(neighb);
                dfs(neighb, sections, explored);
            }
        }


        return;
    }
};

// Solution 1.B - FAIL
#include <vector>
#include <unordered_set>

class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        auto len = grid[0].size();
        auto sections = std::vector<std::vector<std::string>>(3 * len + 1, std::vector<std::string>(3 * len + 1, ""));
        auto to_visit = std::vector<std::pair<int, int>>{};

        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != ' ') {
                    sections[i][3 * j + 1] = grid[i][j];
                    to_visit.push_back(std::make_pair(i, j - 1));
                    to_visit.push_back(std::make_pair(i, j + 1));
                }
            }
        }

        auto explored_r = std::unordered_set<int>{};
        auto explored_c = std::unordered_set<int>{};
        for (auto& point : to_visit) {
            if (explored_r.contains(point.first) and explored_c.contains(point.second))
                continue;
            
            dfs(std::vector<int>{point.first, point.second}, sections, explored_r, explored_c);
            regions++;
        }

        return regions;
    }

private:
    int regions = 0;
    
    void dfs(std::vector<int> point, std::vector<std::vector<std::string>>& sections, std::unordered_set<int>& explored_r, std::unordered_set<int>& explored_c) {
        if (sections[point[0]][point[1]] == "/" or sections[point[0]][point[0]] == "\\")
            return;
        
        for (auto i = -1; i <= 1; i += 2) {
            if (i + point[0] < 0 or i + point[0] >= sections.size()) {
                continue;
            }

            auto neighb = std::vector<int>{point[0] + i, point[1]};
            if (!explored_r.contains(point[0] + i) or !explored_c.contains(point[1])) {
                explored_r.insert(point[0] + i);
                explored_c.insert(point[1]);
                dfs(neighb, sections, explored_r, explored_c);
            }
        }

        for (auto j = -1; j <= 1; j += 2) {
            if (j + point[1] < 0 or j + point[1] >= sections[0].size()) {
                continue;
            }

            auto neighb = std::vector<int>{point[0], point[1] + j};
            if (!explored_r.contains(point[0]) or !explored_c.contains(point[1] + j)) {
                explored_r.insert(point[0]);
                explored_c.insert(point[1] + j);
                dfs(neighb, sections, explored_r, explored_c);
            }
        }


        return;
    }
};


// Solution 2 - unfinished
class Solution {
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        /*
        map grid to coordinates - where edges of slashes are coordinates 
        traverse slash path until edge of grid reached or cycle
            if edge reached, add region
            if cycle reached, add region
        */

        auto slash_map = std::vector<std::vector<std::string>>(grid[0].size() + 1, std::vector<std::string>(grid[0].size()));
        auto slashes_visited = std::vector<std::pair<int, int>>{};

       	for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '/') {
                    slash_map[i][j + 1];
                }
            }
        }

        for (auto i = 0; i < slash_map.size(); ++i) {
            for (auto j = 0; j < slash_map[0].size(); ++j) {
                auto& curr = slash_map[i][j];
                if (curr == " ")
                    continue;
                
                if (std::find(slashes_visited.begin(), slashes_visited.end(), std::make_pair(i, j)) != slashes_visited.end())
                    continue;

                // visit bottom adjacent
                // visit bottom right adjacent
                // visit right adjacent

                if (j + 1 < slash_map[0].size()) {
                    if (curr == "/" and slash_map[i][j + 1] == "\\") {
                        break;
                    }
                }

                if (i + 1 < slash_map[0].size()) {

                }
                
            }
        }

       return regions;
    }
private:
    int regions = 1;
};


// Solution 3
class Solution {
    std::vector<int> parent;
    std::vector<int> rank;
    int count;
    
public:
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        int dots = n + 1;
        parent.resize(dots * dots);
        rank.resize(dots * dots, 1);
        count = 0;

        // Initialize Union-Find structure
        for (int i = 0; i < parent.size(); ++i) {
            parent[i] = i;
        }

        // Connect boundaries to the top-left corner (0,0)
        for (int i = 0; i < dots; ++i) {
            for (int j = 0; j < dots; ++j) {
                if (i == 0 || j == 0 || i == n || j == n) {
                    int cell = i * dots + j;
                    unionSets(0, cell);
                }
            }
        }

        // Process each cell and connect regions based on slashes
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '\\') {
                    int cell1 = i * dots + j;
                    int cell2 = (i + 1) * dots + (j + 1);
                    unionSets(cell1, cell2);
                } else if (grid[i][j] == '/') {
                    int cell1 = (i + 1) * dots + j;
                    int cell2 = i * dots + (j + 1);
                    unionSets(cell1, cell2);
                }
            }
        }

        return count;
    }
    
private:
    void unionSets(int a, int b) {
        int parentA = find(a);
        int parentB = find(b);
        if (parentA == parentB) {
            count++;
        } else {
            if (rank[parentA] > rank[parentB]) {
                parent[parentB] = parentA;
            } else if (rank[parentA] < rank[parentB]) {
                parent[parentA] = parentB;
            } else {
                parent[parentB] = parentA;
                rank[parentA]++;
            }
        }
    }
    
    int find(int a) {
        if (parent[a] == a) {
            return a;
        }
        return parent[a] = find(parent[a]);
    }
};

// Solution 4
class Solution {
public:
    void dfs(int i, int j, std::vector<std::vector<int>>&mat, std::vector<std::vector<int>>&vis){
        vis[i][j] = 1;
        int n = mat.size(),m=mat[0].size();
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        for(int k=0; k<4; k++){
            int nrow = i+delr[k], ncol=j+delc[k];
            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || mat[nrow][ncol]!=0 
            || vis[nrow][ncol]) continue;
            dfs(nrow,ncol,mat,vis);
        }
    }
    int regionsBySlashes(std::vector<std::string>& grid) {
        int n = grid.size();
        std::vector<std::vector<int>>mat(n*3, std::vector<int>(n*3,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='/'){
                    mat[i*3][j*3+2] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3] = 1;
                }else if(grid[i][j]=='\\'){
                    mat[i*3][j*3] = 1;
                    mat[i*3+1][j*3+1] = 1;
                    mat[i*3+2][j*3+2] = 1;
                }
            }
        } // till here the correct matrix have beem constructed.
        // Now apply dfs to find the number of different islands formed by the 0's.
        int count = 0;
        std::vector<std::vector<int>>vis(n*3,std::vector<int>(n*3,0));
        for(int i=0; i<n*3; i++){
            for(int j=0; j<n*3; j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    count++;
                    dfs(i,j,mat,vis);
                }
            }
        }
        return count;
    }
};
