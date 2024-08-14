#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

// Solution 1 - FAIL
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        /*
        sort vector
        two pointer approach for largest and smallest elements,
            if largest is ==, add that to results
            if right + left is ==, add both elements to results, decrement right
            if right + left is >, decrement right
            if right + left is <,
                keep track of current sum and increment left until
                    if sum <, add left to sum, increment left,
                    if sum ==, add vector of elements to results, increment left
                    if sum >, exit and increment left
            -> quadratic time complexity (worst case)
        
        backtracking?
        */

        if (candidates.size() == 1 and target == candidates[0])
            return std::vector<std::vector<int>>{std::vector<int>{candidates[0]}};

        std::sort(candidates.begin(), candidates.end());

        int left = 0, right = candidates.size() - 1;
        auto results = std::vector<std::vector<int>>{};
        auto curr_sum = std::vector<int>{};
        
        while (left < right) {
            std::cout << "left and right at the beginning is: " << left << " - " << right << std::endl;
            auto sum = std::vector<int>{};
            auto right_v = candidates[right];
            auto left_v = candidates[left];
            auto rl_sum = left_v + right_v;


            if (right_v == target) {
                sum.push_back(right_v);
                
                if (std::find(results.begin(), results.end(), sum) == results.end())
                    results.push_back(sum);
                
                --right;
                continue;
            }

            if (left_v == target) {
                sum.push_back(left_v);

                if (std::find(results.begin(), results.end(), sum) == results.end())
                    results.push_back(sum);

                ++left;
                continue;
            }

            if (right_v > target or rl_sum > target) {
                --right;
                continue;
            }

            if (rl_sum == target) {
                sum.push_back(left_v);
                sum.push_back(right_v);

                if (std::find(results.begin(), results.end(), sum) == results.end())
                    results.push_back(sum);

                --right;
                if (left >= right)
                    break;
                left = 0;
                continue;
            }

            if (rl_sum < target) {
                int temp_l = left;

                while (left < right and rl_sum < target) {
                    std::cout << "current sum is (while in loop): " << rl_sum << ", ";
                    sum.push_back(left_v);
                    ++left;
                    left_v = candidates[left];
                    rl_sum += left_v;
                }
                // std::cout << "and once outside of loop: " << rl_sum << std::endl;

                // std::cout << "left - right: " << left << " - " << right << std::endl;

                sum.push_back(left_v);
                sum.push_back(right_v);

                if (rl_sum == target) {
                    if (std::find(results.begin(), results.end(), sum) == results.end())
                        results.push_back(sum);
                    
                    ++left;
                } else if (right == left) {
                    --right;
                    left = 0;
                } else if (rl_sum > target) {
                    left = temp_l + 1;
                }

                // std::cout << "current sum is : ";
                // for (auto& n : sum) {
                //     std::cout << n << " ";
                // }
                // std::cout << std::endl;
            }
        }

        std::sort(results.begin(), results.end(), [](std::vector<int> a, std::vector<int> b) {
            if (a.size() == b.size())
                return a < b;

            return a.size() > b.size();
        });

        return results;
    }
};

// Solution 2
class Solution {
public:
    // Public method to find all unique combinations of candidates that sum up to the target
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        // Sort the candidates to handle duplicates and to facilitate the pruning of branches
        std::sort(candidates.begin(), candidates.end());
        
        // Vector to store the final results
        std::vector<std::vector<int>> ans;
        
        // Vector to store the current combination
        std::vector<int> ds;
        
        // Call the helper function to find combinations starting from index 0
        findCombination(0, target, candidates, ans, ds);
        
        // Return the final results
        return ans;
    }

    // Helper method to find combinations using backtracking
    void findCombination(int ind, int target, std::vector<int>& arr, std::vector<std::vector<int>>& ans, std::vector<int>& ds) {
        // If the target is 0, we have found a valid combination
        if (target == 0) {
            // Add the current combination to the results
            ans.push_back(ds);
            return;
        }
        
        // Loop through the array starting from the current index
        for (int i = ind; i < arr.size(); i++) {
            // Skip duplicates by ensuring we only take the first occurrence of a number in this position
            if (i > ind && arr[i] == arr[i - 1]) continue;
            
            // If the current number is greater than the target, we can stop further exploration
            if (arr[i] > target) break;
            
            // Include the current number in the combination
            ds.push_back(arr[i]);
            
            // Recur with the remaining target and the next index
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            
            // Backtrack by removing the last added number to explore other combinations
            ds.pop_back();
        }
    }
};
