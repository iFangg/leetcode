// Solution 1
class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() <= 2)
            return s;

        auto res = std::string{s[0]};
        char prev = s[0];
        int count = 1;
        
        for (auto i = 1; i < s.size(); ++i) {
            if (s[i] == prev) {
                count++;
            } else
                count = 1;

            if (count == 3) {
                count--;
            } else
                res += s[i];
            
            prev = s[i];
        }

        return res;
    }
};


// Solution 2
class Solution {
public:
    string makeFancyString(string s) {
    if(s.length()<3) {
        return s;
    }
    int j = 2;
    for (int i = 2; i < s.size(); ++i)
        if (s[i] != s[j - 1] || s[i] != s[j - 2])
            s[j++] = s[i];
    s.resize(j);
    return s;
}
};
