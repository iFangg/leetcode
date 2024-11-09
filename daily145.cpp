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
        // Initialize the result with the value of x.
        long result = x;
        
        // Calculate the "remaining" bits we need to consider from n, subtracting 1 initially.
        long remaining = n - 1;
        
        // Start with the first bit position.
        long position = 1;
        
        // Loop until remaining becomes 0, meaning all bits have been processed.
        while (remaining) {
            // Check if the current bit in x is 0 at 'position'
            if (!(x & position)) {
                // If the current bit in x is 0, use a bit from 'remaining' (if it is 1)
                // to set this bit in 'result'. We set this bit if the corresponding bit in 'remaining' is 1.
                result |= (remaining & 1) * position;
                
                // Shift 'remaining' right by 1 to process the next bit in the next iteration.
                remaining >>= 1;
            }
            // Shift 'position' left by 1 to move to the next bit position.
            position <<= 1;
        }
        
        // Return the computed result.
        return result;
    }
};
