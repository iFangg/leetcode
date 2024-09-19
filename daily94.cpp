// Solution 1 - unfinished
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        /*
        recursive

        every time we come across a sign, recurse for the next possible result
        */
        auto num_str = std::string{};
        for (auto i = 0; i < )

        eval(num_str)
    }

private:
    void eval(string expr) {

    }

    std::vector<int> results_;
};


// Solution 2
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') res.push_back(a + b);
                        else if (oper == '-') res.push_back(a - b);
                        else if (oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};
