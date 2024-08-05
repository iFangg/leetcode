// Solution 1
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        auto k_map = std::unordered_map<std::string, int>{};
        for (auto& s : arr) {
            if (!k_map.count(s))
                k_map[s] = 0;
            
            k_map[s]++;
        }

        auto index = 0;
        for (auto& s : arr) {
            if (k_map[s] == 1)
                index++;

            if (index == k)
                return s;
        }
        
        return "";
    }
};

