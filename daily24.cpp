// Solution 1
class Solution {
public:
    std::string recurse(string& s, int& pos) {
        // every time you exit a level of brackets, flip the current string and add to final
        auto curr = std::string{""};
        while (pos < s.size()) {
            if (s[pos] == '(') {
                pos++;
                auto next = recurse(s, pos);
                curr += next;
            } else if (s[pos] == ')') {
                reverse(curr.begin(), curr.end());
                return curr;
            } else {
                curr += s[pos];
            }

            pos++;
        }

        return curr;
    }

    string reverseParentheses(string s) {
        auto pos = 0;

        return recurse(s, pos);
    }
};


// Solution 2 - space efficient solution
class Solution {
public:
    // Method to recursively resolve and reverse substrings within parentheses
    string::iterator resolve(string::iterator begin, string &st) {
        string::iterator cur = begin; // Initialize cur to the beginning iterator
        while (cur != st.end() and *cur != ')') { // Loop until end of string or closing parenthesis
            if (*cur == '(') { // If opening parenthesis found
                st.erase(cur); // Erase the opening parenthesis
                cur = resolve(cur, st); // Recursively process the substring within parentheses
            } else {
                cur = cur + 1; // Move to the next character
            }
        }
        if (cur == st.end()) return cur; // If end of string is reached, return current iterator
        st.erase(cur); // Erase the closing parenthesis
        reverse(begin, cur); // Reverse the substring from 'begin' to 'cur'
        return cur; // Return the current iterator
    }

    // Method to initiate the reverseParentheses operation
    string reverseParentheses(string s) {
        string::iterator begin = s.begin(); // Initialize begin to the start of the string
        begin = resolve(begin, s); // Start resolving from the beginning of the string
        return s; // Return the modified string
    }
};


