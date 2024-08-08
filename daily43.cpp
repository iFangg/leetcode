// Solution 1 - FAIL
class Solution {
public:
    int minimumDeletions(string s) {
        // check for balanced takes O(n) time
        // two pointer
            // if found head = a, tail = a, move both +
            // if found head = a, tail = b, move tail
            // if found head = b, tail = a, move both +
            // if found head = b, tail = b, move head
        // dp approach
            // dp(i) is how many characters needed to change for the string to be balanced up to ith index
            // seems slow?
        auto one_letter = std::unordered_set<char>(s.begin(), s.end());
        if (one_letter.size() == 1)
            return 0;

        auto l = 0;
        auto r = s.size() - 1;
        auto total = 0;

        while (l < r) {
            if (s[l] == 'a') {
                if (s[r] == 'a') {
                    l++;
                    r--;
                    total++;
                } else {
                    r--;
                }
            } else if (s[l] == 'b') {
                if (s[r] == 'a') {
                    l++;
                    r--;
                    total++;
                } else {
                    l++;
                }
            }
        }

        return total;
    }
}


// Solution 2 DP WAS FINE
class Solution {
public:
    int minimumDeletions(string s) {
        int a_count = 0;
        int b_count = 0;
        
        for (char c : s) {
            if (c == 'a') {
                // if it's 'a', we can delete previous 'b's to make the substring balanced
                // or leave it, hence the minimum between the two options
                b_count = min(a_count, b_count + 1);
            } else {
                // if it's 'b', increment the count of 'a's we have seen so far
                // this is because we might need to delete this 'b' in the future
                a_count++;
            }
        }
        
        return b_count;
    }
};
