// Solution 1
class Solution {
public:
    int minSwaps(string s) {
        /*
         store in a stack
         every valid pair of [ ] is removed from the stack
         every 1 mismatch, you replace 1
            2- 1
            3-2
            4-2
            5-3
            6-3
            7-4 etc
        */

        auto remaining = std::stack<char>{};

        for (auto i = 0; i < s.size(); ++i) {
            if (s[i] == '[')
                remaining.push(s[i]);
            
            else {
                if (remaining.empty())
                    remaining.push(s[i]);
                else if (remaining.top() == '[')
                    remaining.pop();
                else
                    remaining.push(s[i]);
            }

            // std::cout << "curr stack size: " << remaining.size() << std::endl;
        }

        auto divisor = remaining.size() < 4 ? 2.0 : 4.0;
        // std::cout << divisor;
        return static_cast<int>(std::ceil(remaining.size() / divisor));
    }
};


// Solution 2
static const int __ = []() { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); return 0; }();
class Solution {
public:
    int minSwaps(string s) {
        int count = 0;
        for(auto& c : s){
            if(c  == '[') {
                ++count;
            } else if(count) {   
                --count;
            }
        }
      
        bool b = count & 1;
        return (b + count >> 1);
    }
};
