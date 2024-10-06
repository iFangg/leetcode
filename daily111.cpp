// Solution 1 - unfinished
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        /*
        if s1 and s2 are initially equal, return true
        separate s1 and s2 into arrays of substrings/words
        find long and short strings
        loop through long str until first common word is found
            return false if common word is never found
            loop until uncommon word is found
                loop until common word is found
                    loop until uncommon words is found or end of string
                    if any more uncommon words are found, return false
                    else return true
        */
        if (s1 == s2)
            return false;

        auto words1 = std::vector<std::string>{};
        auto curr_word1 = std::string{};
        auto words2 = std::vector<std::string>{};
        auto curr_word2 = std::string{};
        auto longer = s1;
        auto shorter = s2;
        if (s2.size() > s1.size())
            std::swap(longer, shorter);

        for (auto i = 0; i < longer.size(); ++i) {
            if (longer[i] == ' ') {
                words1.push_back(curr_word1);
                curr_word1.clear();
            } else
                curr_word1 += longer[i];
            
            if (i < shorter.size()) {
                if (shorter[i] == ' ') {
                    words2.push_back(curr_word2);
                    curr_word2.clear();
                } else
                    curr_word2 += shorter[i];
            } else if (i == shorter.size() and !curr_word2.empty())
                words2.push_back(curr_word2);
        }

        if (!curr_word1.empty())
            words1.push_back(curr_word1);

        for (auto i = 0; i < words1.size(); ++i) {
            std::cout << words1[i] << ", ";
        }

        std::cout << std::endl;
        for (auto i = 0; i < words2.size(); ++i) {
            std::cout << words2[i] << ", ";
        }

        

        return false;
    }
}


// Solution 2
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Helper function to split the sentence into words
        auto splitWords = [](const string& sentence) {
            vector<string> words;
            string word = "";
            for (char c : sentence) {
                if (c == ' ') {
                    if (!word.empty()) {
                        words.push_back(word);
                        word = "";
                    }
                } else {
                    word += c;
                }
            }
            if (!word.empty()) words.push_back(word);
            return words;
        };

        // Split both sentences into words
        vector<string> words1 = splitWords(sentence1);
        vector<string> words2 = splitWords(sentence2);
        
        // Ensure words1 is the longer sentence
        if (words1.size() < words2.size()) swap(words1, words2);
        
        int start = 0, end = 0;
        int n1 = words1.size(), n2 = words2.size();
        
        // Compare from the start
        while (start < n2 && words1[start] == words2[start]) start++;
        
        // Compare from the end
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        
        // Check if the remaining unmatched part is in the middle
        return start + end >= n2;
    }
};

