// Solution 1 - FAIL
class Solution {
public:
    int maxUniqueSplit(string s) {
        /*
        greedy approach
            if substring not seen before, add it
            if seen before, add characters until unique
        */

        auto unique = std::unordered_set<std::string>{};
        auto curr = std::string{};

        for (auto& c : s) {
            curr += c;

            if (!unique.contains(curr)) {
                unique.insert(curr);
                curr.clear();
            }
        }

        return unique.size();
    }
};


// Solution 2 - FAIL
class Solution {
public:
    int maxUniqueSplit(string s) {
        /*
        greedy approach
            if substring not seen before, add it
            if seen before, add characters until unique
            doesn't work
        
        backtracking solution
        */

        s_ = s;
        unique = std::unordered_set<std::string>{};
        auto seen = std::vector<int>(s.size(), 0);
        
        backtrack("", seen);

        return unique.size();
    }

private:
    void backtrack(std::string curr, std::vector<int>& seen) {
        if (curr.size() == s_.size())
            return;

        if (!curr.empty())
            unique.insert(curr);

        for (auto i = 0; i < s_.size(); ++i) {
            if (!seen[i]) {
                seen[i] = 1;
                backtrack(curr + s_[i], seen);
                seen[i] = 0;
            }

        }
    }

    std::string s_;
    std::unordered_set<std::string> unique;
}


// Solution 3
class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> unique;
        return backtrack(s, 0, unique);
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& unique) {
        if (start == s.size()) {
            // If we've reached the end, return the current size of the unique set.
            return unique.size();
        }

        int maxSplits = 0;
        
        // Try every possible split starting from `start`.
        for (int end = start + 1; end <= s.size(); ++end) {
            string substr = s.substr(start, end - start);  // Get the substring from [start, end).

            if (unique.find(substr) == unique.end()) {  // If it's unique, proceed.
                unique.insert(substr);  // Add it to the unique set.
                maxSplits = max(maxSplits, backtrack(s, end, unique));  // Recursively search for more splits.
                unique.erase(substr);  // Backtrack by removing the substring.
            }
        }

        return maxSplits;
    }
};
