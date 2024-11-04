// Solution 1
class Solution {
public:
    string compressedString(string word) {
        auto comp = std::string{};
        char curr_char = word[0];
        auto count = 1;

        for (auto i = 1; i < word.size(); ++i) {
            if (curr_char == word[i] and count < 9)
                count++;
            else {
                comp += std::to_string(count) + curr_char;
                curr_char = word[i];
                count = 1;
            }
        }

        return comp + std::to_string(count) + curr_char;
    }
};


// Solution 2
class Solution {
public:
    string compressedString(string word) {
        string temp;
        char last=word[0];
        int cnt=1;
        for(int i=1; i<word.size(); i++){
            if(last==word[i]){
                if(cnt<9){
                    ++cnt;
                    continue;
                }else{
                    temp.push_back(cnt+'0');
                    temp.push_back(last);
                    cnt=1;
                }
            }else{
                temp.push_back(cnt+'0');
                temp.push_back(last);
                cnt=1;
                last=word[i];
            }
        }
        temp.push_back(cnt+'0');
        temp.push_back(last);
        return temp;
    }
};