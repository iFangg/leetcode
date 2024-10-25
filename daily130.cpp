#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Solution 1 - FAIL
class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        /*
        edit vector in place?
        use seen array/set
            if current folder is not in set
                add to set
            else
                idk
        
        translate into graph structure
        find longest connection of nodes with only one child (for each tree)
            for each root node of tree in forest
                traverse until a split in the path is found

            if longest connection is not original array
                decrease connection by one until folder found in array
            if we decrease until the until connection is nothing
                the path is what we started with + child node
        */

        folders_ = folder;
        graph = std::unordered_map<std::string, std::vector<std::string>>{};
        in_out = std::unordered_map<std::string, std::pair<int, int>>{};
        auto root_folders = std::vector<std::string>{};

        for (auto& f : folder) {
            auto curr = std::string{};
            auto prev = std::string{};

            for (auto i = 0; i < f.size(); ++i) {
                if (f[i] == '/') {
                    if (!curr.empty()) {
                        if (!graph.contains(curr)) {
                            root_folders.push_back(curr);
                            graph[curr] = {};
                        }
                        
                        if (!in_out.contains(curr))
                            in_out[curr] = {0, 0};
                        
                        if (!prev.empty()) {
                            if (!graph.contains(prev))
                                graph[prev] = {};
                            
                            if (!in_out.contains(prev))
                                in_out[prev] = {0, 0};
                            
                            graph[prev].push_back(curr);
                            in_out[prev].second++;
                            in_out[curr].first++;
                        }
                        
                        prev = curr;
                    }

                    curr.clear();
                } else {
                    curr += f[i];
                }
            }

            if (!curr.empty()) {
                if (!graph.contains(curr)) {
                    root_folders.push_back(curr);
                    graph[curr] = {};
                }
                
                if (!in_out.contains(curr))
                    in_out[curr] = {0, 0};
                
                if (!prev.empty()) {
                    if (!graph.contains(prev))
                        graph[prev] = {};
                    
                    if (!in_out.contains(prev))
                        in_out[prev] = {0, 0};
                    
                    graph[prev].push_back(curr);
                    in_out[prev].second++;
                    in_out[curr].first++;
                }
            }
        }

        super_folders = std::vector<std::string>{};

        std::sort(root_folders.begin(), root_folders.end(), [this](std::string a, std::string b) {
            return this->in_out[a].second < this->in_out[b].second;
        });


        for (auto& f : root_folders) {
            auto seen = std::unordered_set<std::string>{};
            dfs(f, seen, "/" + f);
        }

        return {};
    }

private:
    void dfs(std::string node, std::unordered_set<std::string>& seen, std::string path) {
        if (seen.contains(node))
            return;
        
        seen.insert(node);
        auto common_path = false;

        if (graph[node].size() > 1) {
            // split in path found
            while (std::find(folders_.begin(), folders_.end(), path) == folders_.end()) {
                if (path.empty())
                    break;

                path = path.substr(0, path.size() - 2);
            }

            if (path.empty())
                common_path = true;
            else {
                super_folders.push_back(path);
                return;
            }
        }

        for (auto& n : graph[node]) {
            if (common_path)
                super_folders.push_back(path + "/" + n);
            else
                dfs(n, seen, path + "/" + n);
        }
    }

    std::vector<std::string> folders_;
    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, std::pair<int, int>> in_out;
    std::vector<std::string> super_folders;
};


// Solution 2
class Solution {
public:
    std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
        // Sort folders lexicographically
        std::sort(folder.begin(), folder.end());
        
        // Vector to store the result
        std::vector<std::string> result;
        
        // Add the first folder to the result as it's always a root folder
        result.push_back(folder[0]);
        
        // Iterate through the folders and check if each is a subfolder of the previous one
        for (int i = 1; i < folder.size(); ++i) {
            // Check if the current folder starts with the last folder in result followed by a '/'
            if (folder[i].substr(0, result.back().size()) != result.back() || folder[i][result.back().size()] != '/') {
                result.push_back(folder[i]);
            }
        }
        
        return result;
    }
};