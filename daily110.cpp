// Solution 1 - unfinished
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
                /*
        create hashmap for s1, count of each letter
        every first time we come across a common letter,
            start counting until we find every letter in s1 or it's not a letter in s1
        */

        if (s1.size() > s2.size())
            return false;

        auto s1_chars = std::vector<int>(26, 1);
        
        for (auto& c : s1) {
            s1_chars[c - 'a' + 1]++;
        }

        auto matching = false;
        auto substr = s2.subtr(0, s1.size());
        
        
        for (auto i = s1.size() - 1; i < s2.size(); ++i) {
            if (substr == s1)
                return true;
            
            if (i == s1.size() - 1) {
                continue;
            }

            substr -= s2[i - s1.size()];
            substr += s2[i];
        }

        return false;
    }
};


// Solution 2
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Count frequencies of s1 and the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1Count == s2Count) return true;
            // Update the window
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        // Check the last window
        return s1Count == s2Count;
    }
};

