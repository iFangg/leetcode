// Solution 1 - FAIL
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        auto min = std::pair<int, int>(INT_MAX, -1);
        auto max = std::pair<int, int>(INT_MIN + 1, -1);
        auto array = 1;

        for (auto& nums : arrays) {
            std::cout << "new array\n";
            for (auto n : nums) {
                std::cout << "min - max: " << min.first << " - " << max.first << std::endl;
                std::cout << n << std::endl;
                // if both are unset, set the min first

                if (n < min.first and array != max.second) {
                    min.first = n;
                    min.second = array;
                } 

                if (n > max.first and array != min.second) {
                    max.first = n;
                    max.second = array;
                }

                std::cout << "changed min - max: " << min.first << " - " << max.first << std::endl;
            }

            array++;
        }

        return max.first - min.first;
    }
}


// Solution  2
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int global_min = arrays[0][0]; // Initialize with the first element of the first array
        int global_max = arrays[0].back(); // Initialize with the last element of the first array
        int max_distance = 0;

        for (int i = 1; i < arrays.size(); ++i) {
            // Calculate the possible max distance using current array and global min/max from previous arrays
            max_distance = std::max(max_distance, std::max(abs(arrays[i].back() - global_min), abs(global_max - arrays[i][0])));
            
            // Update global min and max
            global_min = std::min(global_min, arrays[i][0]);
            global_max = std::max(global_max, arrays[i].back());
        }

        return max_distance;
    }
};
