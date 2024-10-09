// Solution 1
class Solution {
public:
    int minAddToMakeValid(string s) {
        /*
        if string is empty, return 0
        only consider parentheses - stack approach
        push next bracket to be closed, return size of stack
        */ 

        // auto brackets = std::queue<char>{};
        // auto pairs = std::unordered_map<char, char>{
        //     {'(': ')'},
        //     {')': '('},
        // };

        auto total = 0;
        auto lefts = 0;

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                lefts++;
            
            if (s[i] == ')') {
                if (lefts > 0)
                    lefts--;
                else
                    total++;
            }
        }

        return lefts + total;
    }
};


// Solution 2
class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0; // addtions required
        int numOpen=0;
        for(char c:s){
            if(c=='('){
                ++numOpen;
            } else {
                numOpen >0? numOpen-- : res++;
            }
        }
        return numOpen+res;
        
    }
};
