// Solution 1 - FAIL
class Solution {
public:
    long long minEnd(int n, int x) {
        /*
        create array of nums 0 to n
        find current XOR value
        */
        auto array = std::vector<int>(n);
        auto value = x;
        auto xor_val = x;

        for (auto i = 0; i < n; ++i) {
            array[i] = value++;

            if (i == 0)
                continue;
            
            xor_val ^= value;
        }

        while (xor_val != x) {
            if (xor_val < x) {
                xor_val ^= array.back();
                xor_val ^= ++array.back();
            } else if (xor_val > x) {
                xor_val = array.back() - 1;
                array.back()--;
                for (auto i = n - 2; i >= 0; --i) {
                    if (array[i] == array[i + 1]) {
                        array[i]--;
                        xor_val ^= array[i];
                    }
                }

            }
        }

        return array.back();
    }
}


// Solution 2
class Solution {
public:
    long minEnd(int n, int x) {
        long result = x;
        long remaining = n - 1;
        long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};
