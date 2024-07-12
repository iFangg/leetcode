// Solution 1 - too slow
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // look for most valuable points
        // search for those points first 
        int total = 0;
        auto curr = s;
        auto most_value = x >= y ? x : y;
        auto most_substr = x >= y ? "ab" : "ba";

        while (curr.contains(most_substr)) {
            for (auto i = 0; i < curr.size() - 1; ++i) {
                auto substr = curr.substr(i, 2);
                if (substr == most_substr) {
                    total += most_value;
                    auto begin = curr.substr(0,i);
                    if (i + 2 >= curr.size())
                        curr = begin;
                    else {
                        auto end = curr.substr(i + 2, curr.size() - begin.size() - 2);
                        curr = begin + end;
                    }

                    break;
                }
            }
        }

        auto least_value = y < x ? y : x;
        auto least_substr = y < x ? "ba" : "ab";
        while (curr.contains(least_substr)) {
            for (auto i = 0; i < curr.size() - 1; ++i) {
                auto substr = curr.substr(i, 2);
                if (substr == least_substr) {
                    total += least_value;
                    auto begin = curr.substr(0,i);
                    if (i + 2 >= curr.size())
                        curr = begin;
                    else {
                        auto end = curr.substr(i + 2, curr.size() - begin.size() - 2);
                        curr = begin + end;
                    }
                    
                    break;
                }
            }
        }

        return total;
    }
}


// Solution 2 - too memory inefficient
class Solution {
public:
    int findValue(std::string& s, int val, const std::string& substr) {
        int total = 0;
        std::stack<char> stack;

        for (char c : s) {
            if (!stack.empty() && stack.top() == substr[0] && c == substr[1]) {
                total += val;
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        std::string remaining;
        while (!stack.empty()) {
            remaining = stack.top() + remaining;
            stack.pop();
        }

        s = remaining;

        return total;
    }

    int maximumGain(std::string s, int x, int y) {
        int total = 0;

        // Determine which pair is more valuable and process them
        if (x >= y) {
            total += findValue(s, x, "ab"); // Process "ab" pairs with value x
            total += findValue(s, y, "ba"); // Process "ba" pairs with value y
        } else {
            total += findValue(s, y, "ba"); // Process "ba" pairs with value y
            total += findValue(s, x, "ab"); // Process "ab" pairs with value x
        }

        return total;
    }
};

// Solution 4
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int aCount = 0;
        int bCount = 0;
        int lesser = min(x, y);
        int result = 0;

        for (char c : s) {
            if (c > 'b') {
                result += min(aCount, bCount) * lesser;
                aCount = 0;
                bCount = 0;
            } else if (c == 'a') {
                if (x < y && bCount > 0) {
                    bCount--;
                    result += y;
                } else {
                    aCount++;
                }
            } else {
                if (x > y && aCount > 0) {
                    aCount--;
                    result += x;
                } else {
                    bCount++;
                }
            }
        }

        result += min(aCount, bCount) * lesser;
        return result;
    }
};
