// Solution 1
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        /*
        sliding window? max OR value kept

        note: 
            max bitwise OR is bitwose OR of whole array


        n^something:
            test every subset to see which ones can sum to the max bitwise or

        recursive solution (n^2?):
            backtrack
        */

        max_ = nums.front();
        for (auto i = 1; i < nums.size(); ++i) {
            max_ |= nums[i];
        }

        nums_ = nums;

        std::vector seen(nums.size(), 0);
        findSets(0, 0, seen);

        return arrays;
    }

private:
    void findSets(int total, int index, std::vector<int>& seen) {
        if (total == max_) {
            arrays++;
        }

        for (auto i = index; i < nums_.size(); ++i) {
            if (!seen[i]) {
                seen[i] = 1;
                findSets(total | nums_[i], i + 1, seen);
                seen[i] = 0;
            }
        }

    }

    int arrays = 0;
    int max_;
    std::vector<int> nums_;
};


// What I did wrong before the solution:
/*
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        /\*
        sliding window? max OR value kept

        note: 
            max bitwise OR is bitwose OR of whole array


        n^something:
            test every subset to see which ones can sum to the max bitwise or

        recursive solution (n^2?):
            backtrack
        /\*

        max_ = nums.front();
        for (auto i = 1; i < nums.size(); ++i) {
            max_ ^= nums[i];
        }

        nums_ = nums;

        for (auto i = 0; i < nums.size(); ++i) {
            std::vector seen(nums.size(), 0);
            findSets(nums[i], i, seen);
        }

        return arrays;
    }

private:
    void findSets(int total, int index, std::vector<int>& seen) {
        if (total == max_) {
            arrays++;
            return;
        }
        
        seen[index] = 1;

        for (auto i = 0; i < nums_.size(); ++i) {
            if (!seen[i]) {
                findSets(total ^ nums_[i], i, seen);
            }
        }

        seen[index] = 0;
    }

    int arrays = 0;
    int max_;
    std::vector<int> nums_;
};
*/
