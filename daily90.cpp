// Solution 1 - FAIL
class Solution {
public:
    int findTheLongestSubstring(string s) {
        /*
        prefix sum for number of even vowels up to index i AND total vowels
        doesn't work because recalculating number of even vowels for sliding window would take too long

        prefix sum of total vowels
        sliding window, if substring has uneven number of vowels, it could potentially be the longest substring containing vowels
        
        */

        auto total_vowels = std::vector<int>(s.size(), 0);
        auto no_vowels = true;
        auto vowels = std::unordered_map<char, std::vector<int>>{
            {'a', std::vector<int>(s.size(), 0)},
            {'e', std::vector<int>(s.size(), 0)},
            {'i', std::vector<int>(s.size(), 0)},
            {'o', std::vector<int>(s.size(), 0)},
            {'u', std::vector<int>(s.size(), 0)}
        };

        for (auto i = 0; i < s.size(); ++i) {
            auto c = s[i];
            if (vowels.contains(c)) {
                no_vowels = false;
                if (i == 0) {
                    total_vowels[i] = 1;
                    vowels[c][i] = 1;
                } else {
                    total_vowels[i] = total_vowels[i - 1] + 1;
                    vowels[c][i] = vowels[c][i - 1] + 1;
                }
                
            } else {
                total_vowels[i] = i == 0 ? 0 : total_vowels[i - 1];
                for (auto& [k, v] : vowels) {
                    for (auto j = i + 1; j < s.size(); ++j) {
                        vowels[k][j] = vowels[k][j - 1];
                    }
                }
            }
        }

        int end = s.size() - 1;
        auto res = 0;

        while (end >= 0) {
            for (auto i = 0; i < end; ++i) {
                auto num_vowels = total_vowels[end] - total_vowels[i];
                if (num_vowels % 2 != 0)
                    continue;
                else {
                    auto even = true;
                    for (auto& [c, n] : vowels) {
                        if ((n[end] - n[i]) % 2 != 0) {
                            even = false;
                            break;
                        }
                    }

                    if (even) {
                        res = std::max(res, end - i);
                    }
                }
            }

            end--;
        }

        if (no_vowels)
            return s.size();
        
        return res;
    }
};


// Solution 2
class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> seen(32, -1);
        int result = 0, status = 0;
        seen[0] = 0;
        
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'a': status ^= 1; break;
                case 'e': status ^= 2; break;
                case 'i': status ^= 4; break;
                case 'o': status ^= 8; break;
                case 'u': status ^= 16; break;
            }
            
            if (seen[status] >= 0) {
                result = max(result, i + 1 - seen[status]);
            } else {
                seen[status] = i + 1;
            }
        }
        
        return result;
    }
};
