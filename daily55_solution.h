#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class Solution {
public:
    int minDays(std::vector<std::vector<int>>& grid) {
        /*
        if there is more than one island initially, the grid is disconnected
        else, disconnect cell C connected to cell with least connected edges ce
        update graph,

        graph:
            with each node (index)
                track island or water
                track how many connections
        */

        // map each grid coordinate to index: (0, 0) - 0, (0, 1) - 1 ... etc
        auto index = 0;
        // coordinate mapped to an index: index - island/water, how many connections, neighbours
        auto index_map = std::unordered_map<int, std::tuple<int, int, std::unordered_set<int>>>{};
        auto island_cells = std::vector<int>{};
        auto cols = grid[0].size();
        for (auto i = 0; i < grid.size(); ++i) {
            for (auto j = 0; j < cols; ++j) {
                auto connections = 0;
                auto neighbours = std::unordered_set<int>{};

                if (grid[i][j] == 1) {
                    island_cells.push_back(index);
                    if (i - 1 >= 0 and grid[i - 1][j] == 1) {
                        connections++;
                        neighbours.insert((i - 1) * cols + j);
                    }

                    if (i + 1 < grid.size() and grid[i + 1][j] == 1) {
                        connections++;
                        neighbours.insert((i + 1) * cols + j);
                    }

                    if (j - 1 >= 0 and grid[i][j - 1] == 1) {
                        connections++;
                        neighbours.insert(index - 1);
                    }

                    if (j + 1 < grid[0].size() and grid[i][j + 1] == 1) {
                        connections++;
                        neighbours.insert(index + 1);
                    }
                }

                index_map[index] = std::make_tuple(grid[i][j], connections, neighbours);

                index++;
            }
        }

        // traverse to find number of islands
        if (num_islands(island_cells, index_map) != 1)
            return 0;

        // try removing one cell
        for (auto& i : island_cells) {
            std::get<0>(index_map[i]) = 0;
            auto neighbours = erase_from_neighbours(index_map, i);
            auto new_cells = std::vector<int>{};
            for (auto& cell : island_cells) {
                if (cell != i)
                    new_cells.push_back(cell);
            }

            if (num_islands(new_cells, index_map) != 1)
                return 1;

            std::get<0>(index_map[i]) = 1;

            for (auto& n : neighbours) {
                std::get<2>(index_map[n]).insert(i);
            }
        }

        // try removing two cells
        auto seen_pairs = std::vector<std::pair<int, int>>{};
        for (auto& first : island_cells) {
            std::get<0>(index_map[first]) = 0;
            auto first_neighbours = erase_from_neighbours(index_map, first);
            for (auto& second : island_cells) {
                if (first == second)
                    continue;
                
                auto index_pair = std::make_pair(first, second);
                auto flipped_index_pair = std::make_pair(second, first);
                if (std::find(seen_pairs.begin(), seen_pairs.end(), index_pair) != seen_pairs.end()) {
                    continue;
                }

                std::get<0>(index_map[second]) = 0;
                auto second_neighbours = erase_from_neighbours(index_map, second);
                auto new_cells = std::vector<int>{};
                for (auto& cell : island_cells) {
                    if (cell != first and cell != second)
                        new_cells.push_back(cell);
                }

                // std::cout << "\ntesting for disjoint in pairs: ";
                if (num_islands(new_cells, index_map) != 1)
                    return 2;

                std::get<0>(index_map[second]) = 1;
                seen_pairs.push_back(index_pair);
                seen_pairs.push_back(flipped_index_pair);
                for (auto& n : second_neighbours) {
                    std::get<2>(index_map[n]).insert(second);
                }   
            }

            std::get<0>(index_map[first]) = 1;
            for (auto& n : first_neighbours) {
                std::get<2>(index_map[n]).insert(first);
            }   
        }

        return 0;
    }
 private:
    void dfs(std::unordered_map<int, std::tuple<int, int, std::unordered_set<int>>>& index_map, int i, std::unordered_set<int>& visited) {
        for (auto& n : std::get<2>(index_map[i])) {
            if (!visited.count(n)) {
                visited.insert(n);
                dfs(index_map, n, visited);
            }
        }
    }

    int num_islands(std::vector<int>& island_cells, std::unordered_map<int, std::tuple<int, int, std::unordered_set<int>>>& index_map) {
        auto islands = 0;
        auto visited = std::unordered_set<int>{};
        // std::cout << "\n--\n";
        for (auto& i : island_cells) {
            // std::cout << "island index: " << i << ", ";
            if (!visited.count(i)) {
                visited.insert(i);
                dfs(index_map, i, visited);
                islands++;
            }
        }

        return islands;
    }

    std::vector<int> erase_from_neighbours(std::unordered_map<int, std::tuple<int, int, std::unordered_set<int>>>& index_map, int cell) {
        auto neighbours_to_add = std::vector<int>{};
        for (auto& [c, info] : index_map) {
            auto& neighbours = std::get<2>(info);
            for (auto n = neighbours.begin(); n != neighbours.end();) {
                if (*n == cell) {
                    neighbours_to_add.push_back(c);
                    n = neighbours.erase(n);
                } else {
                    ++n;
                }
            }
        }

        return neighbours_to_add;
    }
};