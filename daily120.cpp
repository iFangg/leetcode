// Solution 1 - FAIL
class Solution {
public:
    long long minimumSteps(string s) {
        auto nums = std::vector<char>{};
        auto swaps = 0;

        for (auto& c : s)
            nums.push_back(c);

        std::sort(nums.begin(), nums.end(), [&swaps](char a, char b) {
            if (a < b)
                ++swaps;
            
            return a < b;
        });

        return swaps;
    }
};


// Solution 2 - FAIL
class Solution {
public:
    long long minimumSteps(string s) {
        /*
        implementing quick/merge/bubble sorting?
        sort array such that all 0s are to the left of 1s
        start from the right
            if index = 1, continue
            if index = 0
                while current index = 0
                    decrement index
                    increment zero counts

                while current index = 1
                    increment one counts
                
                total swaps = zero counts * one counts
        */

        long long steps = 0;
        int index = s.size() - 1;

        while (index >= 0) {
            if (s[index] == '1') {
                index--;
                continue;
            }
            
            long long zeroes = 0;
            auto init_ind = index;
            while (index >= 0 and s[index] == '0') {
                zeroes++;
                index--;
            }

            long long ones = 0;
            while (index >= 0 and s[index] == '1') {
                ones++;
                index--;
            }

            // update string
            s = s.substr(0, index + 1) + std::string(zeroes, '0') + std::string(ones, '1') + s.substr(init_ind + 1, s.size() - init_ind);
            steps += zeroes * ones;
            if (index > 0)
                index = init_ind;
        }

        return steps;
    }
};


// Solution 3
class Solution {
public:
    long long minimumSteps(std::string s) {
        long long steps = 0;
        long long zeroes = 0;  // Track how many '1's we have encountered

        // Traverse from the end to the start of the string
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') {
                zeroes++;  // Count '0's
            } else {
                // For every '1', calculate the steps needed to move the current '1's past this '0'
                steps += zeroes;
            }
        }

        return steps;
    }
};
