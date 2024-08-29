// Solution 1 - FAIL
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        /*
            store all rocks in a hashmap, keeping track of all stones in each row and col
            if more than one stone in this row
                remove current stone
                set current stone to next stone in same row
            else if more than one stone in this column
                remove current stone
                set current stone to next stone in same column
            
            increment removed stones if entered into if/else/if statement
        */ 

        auto row_stones = std::unordered_map<int, std::vector<std::vector<int>>>{};
        auto col_stones = std::unordered_map<int, std::vector<std::vector<int>>>{};

        for (auto& s : stones) {
            if (!row_stones.count(s[0]))
                row_stones[s[0]] = std::vector<std::vector<int>>{};
            
            if (!col_stones.count(s[1]))
                col_stones[s[1]] = std::vector<std::vector<int>>{};
            
            row_stones[s[0]].push_back(s);
            col_stones[s[1]].push_back(s);
        }

        for (auto& [k ,v] : row_stones) {
            std::sort(v.begin(), v.end(), [](std::vector<int> a, std::vector<int> b) {
                return a[1] < b[1];
            });
        }

        for (auto& [k ,v] : col_stones) {
            std::sort(v.begin(), v.end(), [](std::vector<int> a, std::vector<int> b) {
                return a[1] < b[1];
            });
        }

        auto& curr_stone = stones[0];
        auto& curr_row = row_stones[curr_stone[0]];
        auto& curr_col = col_stones[curr_stone[1]];
        auto total = int{0};

        while (curr_row.size() > 1 or curr_col.size() > 1) {
            if (curr_row.size() > 1) {
                for (auto i = curr_row.begin(); i != curr_row.end();) {
                    if (*i == curr_stone)
                        i = curr_row.erase(i);
                    else
                        ++i;
                }

                for (auto i = curr_col.begin(); i != curr_col.end();) {
                    if (*i == curr_stone)
                        i = curr_col.erase(i);
                    else
                        ++i;
                }

                curr_stone = curr_row.back();
                curr_row = row_stones[curr_stone[0]];
                curr_col = col_stones[curr_stone[1]];
                ++total;
            } else if (curr_col.size() > 1) {
                for (auto i = curr_row.begin(); i != curr_row.end();) {
                    if (*i == curr_stone)
                        i = curr_row.erase(i);
                    else
                        ++i;
                }

                for (auto i = curr_col.begin(); i != curr_col.end();) {
                    if (*i == curr_stone)
                        i = curr_col.erase(i);
                    else
                        ++i;
                }

                curr_stone = curr_col.back();
                curr_row = row_stones[curr_stone[0]];
                curr_col = col_stones[curr_stone[1]];
                ++total;
            }
        }

        return total;
    }
}

// Solution 2
class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        unordered_map<int, int> row_map, col_map;
        for (int i = 0; i < n; i++) {
            int row = stones[i][0], col = stones[i][1];
            if (row_map.count(row)) {
                unite(i, row_map[row]);
            } else {
                row_map[row] = i;
            }
            if (col_map.count(col + 10001)) {  // offset to avoid collision with row
                unite(i, col_map[col + 10001]);
            } else {
                col_map[col + 10001] = i;
            }
        }
        
        unordered_set<int> unique_parents;
        for (int i = 0; i < n; i++) {
            unique_parents.insert(find(i));
        }
        
        return n - unique_parents.size();
    }
};


// Solution 3
class Disjoint {
public:
    vector<int> size, parent;
    Disjoint(int n) {
        for(int i = 0; i <= n; ++i) {
            size.push_back(1);
            parent.push_back(i);
        }
    }

    int findPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionn(int a, int b) {
        a = findPar(a);
        b = findPar(b);

        if(a == b) return;
        if(size[a] < size[b]) {
            parent[a] = b;
            size[b] += size[a];
        } else {
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0, maxCol = 0;
        for(int i = 0; i < n; ++i) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }

        Disjoint *dsu = new Disjoint(maxRow + maxCol + 1);

        for(int i = 0; i < n; ++i) {
            int col = stones[i][1];
            int row = stones[i][0] + maxCol + 1;
            dsu -> unionn(row, col);
        } 
        set<int> numComp;
        for(int i = 0; i < n; ++i) {
            int row = stones[i][0] + maxCol + 1;
            int col = stones[i][1];
            numComp.insert(dsu -> findPar(row));
            numComp.insert(dsu -> findPar(col));
        }

        return n - (int)numComp.size();

    }
};
