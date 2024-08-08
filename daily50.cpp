// Solution 1
class Solution {
public:
    int minimumPushes(string word) {
        // 8 most used chars get placed first
        // 8 next most used chars get placed second, 
        // etc
        auto sorted_counts = std::vector<int>(26 + 1, 0);
        for (auto c : word) {
            auto char_index = c - 'a' + 1;
            // std::cout << char_index << "/" << c << " ";
            sorted_counts[char_index]++;
        }

        auto letters = std::vector<int>(26 + 1, 0);
        for (auto i = 0; i <= 26; ++i) {
            letters[i] = i;
        }

        std::sort(letters.begin(), letters.end(), [&sorted_counts](int a, int b) {
            return sorted_counts[a] > sorted_counts[b];
        });

        // std::cout << "letters sorted by frequency: ";
        // for (auto l : letters) {
        //     std::cout << l << " ";
        // }
        // std::cout << std::endl;

        auto total = 0;
        auto presses = 1;
        auto index = 0;
        auto letters_seen = 0;
        while (sorted_counts[letters[index]] != 0) {
            // std::cout << "letter: " << 'a' + letters[index] - 1 << " - " << sorted_counts[letters[index]] << " ";
            if (letters_seen == 8) {
                presses++;
                letters_seen = 0;
            }

            total += sorted_counts[letters[index]] * presses;
            letters_seen++;
            ++index;
        }

        return total;
    }
};


// Solution 2
#include <execution>
auto f = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minimumPushes(string word) {
        array<int, 26> f {};
        for (char c : word) {
            f[c - 'a']++;
        }
        sort(execution::par_unseq, f.begin(), f.end(), greater{});
        return transform_reduce(execution::par_unseq, f.begin(), f.end(), 0, plus{}, [f = &f[0]](int const& x) { 
            int i = &x - f;
            return x * (i / 8 + 1);
        });
    }
};
