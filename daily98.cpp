#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
// Solution 1 - FAIL
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        /*
        dp, min characters remain if we try break from the i-th char
        if current string up to i-th char includes a word from the dictionary, 
            remove longest match in dictionary
        */

        auto dp = vector<int>(s.size());
        dp[0] = s.size();

        auto curr = std::string{};
        curr += s[0];
        
        auto index = 1;
        while (curr.size() < s.size()) {
            auto maxLenStr = -1;
            auto maxStr = std::string{};

            for (auto& w : dictionary) {
                if (w.size() > curr.size())
                    continue;
                
                auto found = std::find(curr.begin(), curr.end(), w);
                if (found == curr.end())
                    continue;
                
                if (maxLenStr < w.size()) {
                    maxLenStr = w.size();
                    maxStr = w;
                }
            }
            

            dp[index] = std::min(dp[index - 1], curr.size() - maxLenStr);

            curr += s[index];
            if (index < s.size()) {
                index++;
            }
        }


        return dp[s.size()];
    }
};

// Solution 2
class Solution {
public:
    int minExtraChar(std::string s, std::vector<std::string>& dictionary) {
        int n = s.size();  // Get the length of the string 's'
        
        // Create a DP array where dp[i] represents the minimum number of extra characters 
        // required for the substring s[0:i] (i.e., the first i characters of the string)
        std::vector<int> dp(n + 1, 0);
        
        // Convert the dictionary into an unordered_set for fast word lookup
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());

        // Iterate through all indices of the string 's', from 1 to n
        for (int i = 1; i <= n; ++i) {
            
            // By default, assume the current character at s[i-1] is extra, 
            // so dp[i] is at least dp[i-1] + 1 (i.e., one more extra character than before).
            dp[i] = dp[i - 1] + 1;

            // Now, check if any substring ending at position i-1 matches a word in the dictionary.
            // We do this by trying all possible starting points 'j' from 0 to i-1 and checking 
            // if the substring s[j:i] is in the dictionary.
            for (int j = 0; j < i; ++j) {
                
                // Extract the substring s[j:i] (from index j to i-1)
                std::string current_substr = s.substr(j, i - j);
                
                // Check if this substring exists in the dictionary
                if (dict.find(current_substr) != dict.end()) {
                    // If the substring is a valid word, update dp[i].
                    // dp[i] should be the minimum of its current value and dp[j], because dp[j]
                    // represents the number of extra characters up to index j, and since s[j:i] is 
                    // a valid word, we don't add any extra characters for this part.
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

        // Return dp[n], which contains the minimum number of extra characters for the entire string 's'
        return dp[n];
    }
};

// Solution 3
int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        int const n = s.size();
        std::vector<int> dp(n+1);

        for(int i = 1; i < n+1; ++i) {
            dp[i] = dp[i-1] + 1;
            for(std::string const &word: dictionary) {
                int const m = word.length();
                if(i >= m) {
                    bool flag = true;
                    for(int j = i-m; j < i; ++j) {
                        if(s[j] != word[j-i+m]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) { dp[i] = std::min(dp[i], dp[i-m]); }
                }
            }
        }
        return dp[n];
    }
};
