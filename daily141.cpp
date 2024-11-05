// Solution 1
class Solution {
public:
    int minChanges(string s) {
        /*
        sort and compare differences?
        total min changes = differences / 2?
        incorrect

        decompose string into blocks of size 2
            find the minimum number of changes to make blocks beautiful
            NOT RECURSIVE

            iterate through string in blocks of 2
        */

        auto n = s.size();
        int diff = 0;

        for (auto i = 1; i < n; i += 2) {
            if (s[i] != s[i - 1]) {
                diff++;
            }
        }

        return diff;
    }
};


// Solution 2
class Solution {
public:
    int minChanges(string s) {
        // Initialize with first character of string
        char currentChar = s[0];

        int consecutiveCount = 0;
        int minChangesRequired = 0;

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++) {
            // If current character matches the previous sequence
            if (s[i] == currentChar) {
                consecutiveCount++;
                continue;
            }

            // If we have even count of characters, start new sequence
            if (consecutiveCount % 2 == 0) {
                consecutiveCount = 1;
            }
            // If odd count, we need to change current character
            // to match previous sequence
            else {
                consecutiveCount = 0;
                minChangesRequired++;
            }

            // Update current character for next iteration
            currentChar = s[i];
        }

        return minChangesRequired;
    }
};
