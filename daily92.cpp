// Solution 1.1
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        /*
        sort strings alphabetically and create a set of strings
        when current word in set aren't equal, add to vector
        hashmap -> mapping words to seen/unseen
            if words seen once, they have value 1
            if words seen twice, they have value 2
        */

        auto all_words = getWords(s1);
        auto w2 = getWords(s2);
        all_words.insert(all_words.end(), w2.begin(), w2.end());
        auto words = std::unordered_map<std::string, int>{};

        for (auto& w : all_words) {
            // std::cout << w << std::endl;
            if (!words.contains(w))
                words[w] = 0;
            
            words[w]++;
        }

        auto unseen = std::vector<string>{};

        for (auto& [k, v] : words) {
            if (v == 1)
                unseen.push_back(k);
        }

        return unseen;
    }

private:
    std::vector<std::string> getWords(string s) {
        auto words = std::vector<std::string>{};
        auto word = std::string{};

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] != ' ')
                word += s[i];
            else {
                words.push_back(word);
                word.clear();
            }
        }

        if (!word.empty())
            words.push_back(word);

        return words;
    }
};


// Solution 1.2
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        words_ = std::unordered_map<std::string, int>{};
        getWords(s1);
        getWords(s2);

        auto unseen = std::vector<string>{};

        for (auto& [k, v] : words_) {
            if (v == 1)
                unseen.push_back(k);
        }

        return unseen;
    }

private:
    void getWords(string s) {
        auto word = std::string{};

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] != ' ')
                word += s[i];
            else {
                if (!words_.contains(word))
                    words_[word] = 0;
                
                words_[word]++;
                word.clear();
            }
        }

        if (!word.empty()) {
            if (!words_.contains(word))
                words_[word] = 0;
            
            words_[word]++;
        }

    }

    std::unordered_map<std::string, int> words_;
};

// Solution 2
#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution final
{
public:
    std::vector<std::string> uncommonFromSentences(const std::string s1, const std::string s2) const noexcept
    {
        std::unordered_map<std::string, size_t> counter;
        std::stringstream ss1(s1);
        std::string word;
        while (ss1 >> word)
            ++counter[word];
        std::stringstream ss2(s2);
        while (ss2 >> word)
            ++counter[word];
        std::vector<std::string> uncommons;
        uncommons.reserve(counter.size() + 10);
        for (const auto& [word, count] : counter)
            if (count == 1)
                uncommons.push_back(word);
        return uncommons;
    }
};
