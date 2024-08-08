// Solution 1
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        // compare current time to time of customer entry
        // add wait time to current time
        // add total wait time for current customer for overall wait time
        auto total = double{0};
        auto curr = 0;
        for (auto c = customers.begin(); c != customers.end(); ++c) {            
            if (curr < (*c)[0]) {
                curr = (*c)[0] + (*c)[1];
                total += curr - (*c)[0];
            } else {
                curr += (*c)[1];
                total += curr - (*c)[0];
            }
        }
        
        return total / customers.size();
    }
};

