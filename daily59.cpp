// Solution 1
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        auto fives = 0;
        auto tens = 0;
        for (auto i : bills) {
            if (i == 5)
                fives++;
            
            if (i == 10) {
                if (fives == 0)
                    return false;

                fives--;
                tens++;
            }
            
            if (i == 20) {
                if (tens == 0) {
                    if (fives < 3)
                        return false;

                    fives -= 3;
                } else {
                    if (fives == 0)
                        return false;

                    fives--;
                    tens--;
                }
            }
        }
        return true;
    }
};

