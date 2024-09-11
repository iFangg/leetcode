// Solution 1
class Solution {
public:
    int minBitFlips(int start, int goal) {
        auto start_bit = std::bitset<32>(start).to_string();
        auto result_bit = std::bitset<32>(goal).to_string();
        auto diff = 0;
        for (auto i = 0; i < 32; ++i) {
            if (start_bit[i] != result_bit[i])
                ++diff;
        }

        return diff;
    }
};


// Solution 2
class Solution {
public:
    int getBit(int n, int pos){
        if(n & (1 << (pos - 1))){
            return 1;
        }
      
        return 0;
    }

    int minBitFlips(int start, int goal) {
        int count = 0;
        for(int i = 1; i < 32; i++){
            if(getBit(start, i) ^ getBit(goal, i)){
                count++;
            }
        }
      
        return count;
    }
};
