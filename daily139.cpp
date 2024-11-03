// Solution 1
class Solution {
public:
    bool rotateString(string s, string goal) {
        auto n = s.size();

        if (n != goal.size())
            return false;
        
        auto rotate = s;
        for (auto i = 0; i < n; ++i) {
            if (rotate == goal)
                return true;
            
            rotate = rotate.substr(1, n - 1) + rotate[0];
        }

        return false;
    }
};
