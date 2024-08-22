// Solution 1
 class Solution {
public:
    int findComplement(int num) {
        /*
        number is binary 1111... length of binary num
        return xor value
        */
        auto rounded = std::ceil(std::log2(num));
        auto num_max_bin = std::pow(2, rounded) - 1;
        if ((num & (num - 1)) == 0) {
            num_max_bin = std::pow(2, rounded + 1) - 1;
        }

        return num ^ static_cast<int>(num_max_bin);
    }
};


// Solution 2
class Solution {
public:

    int findComplement(int num) {
        int m = num;
        int mask = 0;
        if(num == 0){
            return 1;
        }
        while(m != 0){
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        int ans = (~num) & mask;
        return ans;
        
    }
};
