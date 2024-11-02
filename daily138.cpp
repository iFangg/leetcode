// Solution 1
 class Solution {
public:
    bool isCircularSentence(string sentence) {
        auto words = std::vector<std::string>{};

        auto w = std::string{};
        for (auto i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                words.push_back(w);
                w.clear();
            } else
                w += sentence[i];
        }

        if (!w.empty())
            words.push_back(w);

        if (words.size() == 1) {
            if (words[0][0] != words[0].back())
                return false;
            
            return true;
        } 

        if (words[0][0] - words.back().back() != 0)
            return false;

        for (auto i = 1; i < words.size(); ++i) {
            if (words[i][0] - words[i - 1].back() != 0)
                return false;
        }
        
        return true;
    }
};


// Solution 2
class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence[0] != sentence[sentence.size() -1]){
            return false;
        }
        for(int i = 1; i<sentence.size()-1; i++){
            if(sentence[i] == ' ' and sentence[i-1] != sentence[i+1]){
                return false;
            }
        }
        return true;
    }
};
