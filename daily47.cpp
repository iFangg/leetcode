// Solution 1
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // if all elements in arr exist in target, return true;
        auto to_find = std::unordered_map<int, int>{};
        for (auto n : target) {
            if (!to_find.count(n))
                to_find[n] = 0;
            
            to_find[n]++;
        }

        for (auto n : arr) {
            if (!to_find.contains(n))
                return false;
            else
                to_find[n]--;
            
            if (to_find[n] < 0)
                return false;
        }

        return true;
    }
};
