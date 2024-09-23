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
        int n = s.size();
        std::vector<int> dp(n + 1, 0);
        std::unordered_set<std::string> dict(dictionary.begin(), dictionary.end());

        for (int i = 0; i <= n; ++i) {
            dp[i] = i; // If no words match, all characters are extra

            for (int j = 0; j < i; ++j) {
                if (dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
        }

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
