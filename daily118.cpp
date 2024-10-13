// Solution 1 - somehow wrong?
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        /*
        use min heap to keep track of elements in ascendign order
        then sliding window to find smallest range which contains a number from every list

        claude:
        Initialize a min-heap with the first element from each list.
            Each element in the heap should be a pair: (value, list index).
        Initialize a vector to keep track of the current index for each list.
        Initialize variables for the maximum element, and the result range.
        While the heap is not empty:
        a. Pop the smallest element from the heap.
        b. Update the result range if the current range (max - min) is smaller.
        c. If we've reached the end of any list, we're done.
        d. Otherwise, push the next element from the same list onto the heap.
        e. Update the maximum element if necessary.
        */
        
         auto ascending_nums = std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>, std::greater<>>{};
        auto max_n = INT_MIN;
        auto range = std::vector<int>{-100000, 100000};

        for (auto i = 0; i < nums.size(); ++i) {
            ascending_nums.push({nums[i][0], {0, i}});
            max_n = std::max(max_n, nums[i][0]);
        }

        while (!ascending_nums.empty()) {
            auto min_n = ascending_nums.top();
            auto min = min_n.first;
            auto& index = min_n.second.first;
            auto& list = min_n.second.second;
            ascending_nums.pop();

            if (max_n - min < range[1] - range[0])
                range = {min, max_n};
            
            index++;
            if (index == nums[list].size())
                break;
            
            ascending_nums.push({nums[list][index], {index, list}});
            max_n = std::max(max_n, min);
        }


        return range;
    }
};

// Solution 2
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        /*
        use min heap to keep track of elements in ascendign order
        then sliding window to find smallest range which contains a number from every list

        claude:
        Initialize a min-heap with the first element from each list.
            Each element in the heap should be a pair: (value, list index).
        Initialize a vector to keep track of the current index for each list.
        Initialize variables for the maximum element, and the result range.
        While the heap is not empty:
        a. Pop the smallest element from the heap.
        b. Update the result range if the current range (max - min) is smaller.
        c. If we've reached the end of any list, we're done.
        d. Otherwise, push the next element from the same list onto the heap.
        e. Update the maximum element if necessary.
        */
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<int> next(nums.size(), 0);
        int max_val = INT_MIN;
        
        // Initialize the heap with the first element from each list
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i][0], {i, 0}});
            max_val = max(max_val, nums[i][0]);
        }
        
        vector<int> result = {-100000, 100000};
        
        while (true) {
            auto [min_val, indices] = pq.top();
            pq.pop();
            
            // Update result if current range is smaller
            if (max_val - min_val < result[1] - result[0]) {
                result = {min_val, max_val};
            }
            
            // If we've reached the end of any list, we're done
            if (++next[indices.first] == nums[indices.first].size()) {
                break;
            }
            
            // Push next element from the same list
            int next_val = nums[indices.first][next[indices.first]];
            pq.push({next_val, {indices.first, next[indices.first]}});
            
            // Update max_val if necessary
            max_val = max(max_val, next_val);
        }
        
        return result;
    }
};
