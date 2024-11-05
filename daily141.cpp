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
