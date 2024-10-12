// Solution 1
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        /*
            N^2 APPROACH
            sort array on left side of interval
            for current interval
                loop through array to find next possible interval
                after next interval found, change curr to next
            
            sort array on left side of interval
                then lesser right side if left side is ==
            loop through sorted array
            from starting index, set next starting index to next element not in current group
        */
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) {
            if (a[0] == b[0])
                return a[1] < b[1];

            return a[0] < b[0];
        });

        auto totals = 0;
        auto visited = std::unordered_set<int>{};
        visited.insert(0);
        auto starting = 0;
        auto begin = intervals[0][0];
        auto end = intervals[0][1];
        auto index = 1;
        auto found = false;

        while (visited.size() < intervals.size()) {
            if (visited.count(index))
                continue;

            if (intervals[index][0] > end) {
                visited.insert(index);
                end = intervals[index][1];
            } else {
                if (!found)
                    starting = index;

                found = true;
            }

            ++index;
            if (index == intervals.size()) {
                found = false;
                index = starting;
                begin = intervals[index][0];
                end = intervals[index][1];
                totals++;
            }
        }

        return totals;
    }
}


// Solution 2
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
        
        // Min-heap to store end times of groups
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for (const auto& interval : intervals) {
            if (!pq.empty() && pq.top() < interval[0]) {
                // If there's a group that ends before this interval starts,
                // use that group
                pq.pop();
            }
            // Add this interval's end time to the heap
            pq.push(interval[1]);
        }
        
        // The size of the heap is the minimum number of groups needed
        return pq.size();
    }
};
