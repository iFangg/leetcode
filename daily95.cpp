// Solution 1 - unfinished
class Solution {
public:
    string shortestPalindrome(string s) {
        /*
        determine if palindrome
        start from centre of string to find what needs to be added
            how do I tell what is the centre of the string?
            iterate from center of string and find centre point with (index with most equal characters)
            if max similar is 0, add the n-1 characters (in reverse order) to the beginning of the string

        iterate until we reach either end of the string
        */

        auto l = s.size() / 2 - 1;
        if (s.size() % 2 == 0)
            l++;
        auto r = l;
        auto max_sim = 0;
        auto index = 0;

        while (l >= 0 and r < s.size()) {
            auto l_palin = palindrome_letters(l);
            auto r_palin = palindrome_letters(r);
            auto max_sim = std::max(max_sim, l_palin);
            max_sim = std::max(max_sim, r_palin);

            l--;
            r++;
        }

        return "";
    }

private:
    int palindrome_letters(int centre) {
        
        return 0;
    }

};


// Solution 2
class Solution {
public:
    string shortestPalindrome(string s) {
        int count = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }

private:
    int kmp(const string &txt, const string &patt) {
        string newString = patt + '#' + txt;
        vector<int> pi(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                pi[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = pi[k - 1];
                } else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi.back();
    }
};

