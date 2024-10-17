// Solution 1
class Solution {
public:
    int maximumSwap(int num) {
        /*
        n^2:
        set current max to num
        (if numbers are in descending order, you can't swap)
        current number n
        swap number n with m if m > n
        update max

        OR
        have an array of num of digits as length
        every index keeps max number possible (excluding current index)
        */
        auto max_n = num;

        auto digits = std::vector<int>{};
        while (num > 0) {
            int digit = num % 10;
            // std::cout << digit << "\n";
            digits.push_back(digit);

            num /= 10;
        }

        for (int i = digits.size() - 1; i >= 0; --i) {
            for (int j = digits.size() - 1; j >= 0; --j) {
                if (i == j or digits[i] >= digits[j])
                    continue;
                
                // make new num
                auto new_n = 0;
                auto tens = 1;
                for (auto n = 0; n < digits.size(); ++n) {
                    if (n == i)
                        new_n += digits[j] * tens;
                    else if (n == j)
                        new_n += digits[i] * tens;
                    else
                        new_n += digits[n] * tens;

                    tens *= 10;
                }

                max_n = std::max(max_n, new_n);
            }
        }

        return max_n;
    }
};


// Solution 2
class Solution {
public:
    // Function to find the maximum possible number by swapping at most one pair of digits.
    int maximumSwap(int num) {
        int i, n;  // Loop variable 'i' and 'n' for the number of digits.
        int firstGreater = -1;  // Stores the first index where the digits are out of order.
        int tempNum = num;  // Store the original input number to return if no swap is needed.
        int ans = 0;  // Final answer (largest number after potential swap).
        int max;  // Index of the largest digit found to swap.

        // Step 1: Extract all the digits of the input number and store them in a vector.
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % 10);  // Get the last digit of 'num' and store it.
            num /= 10;  // Remove the last digit from 'num'.
        }
        // At this point, the digits are stored in reverse order (least significant to most significant).

        n = digits.size();  // Get the number of digits.

        // Step 2: Find the first index (from right to left) where the digits are not in non-increasing order.
        for (i = n - 2; i >= 0; i--) {
            if (digits[i] > digits[i + 1]) {  // Compare the current digit with the next one.
                firstGreater = i;  // If the current digit is larger, store this index.
                break;  // No need to check further; we found the first "out-of-order" place.
            }
        }

        // If no such index is found, it means the number is already the largest possible.
        if (firstGreater == -1) {
            return tempNum;  // Return the original number as no swap is needed.
        }

        // Step 3: Find the largest digit to the right of the 'firstGreater' index (including itself).
        max = firstGreater;  // Start by assuming the largest digit is at 'firstGreater' index.
        for (i = firstGreater + 1; i >= 0; i--) {  // Check all digits to the left.
            if (digits[i] >= digits[max]) {  // If a larger or equal digit is found.
                max = i;  // Update the index of the largest digit.
            }
        }

        // Step 4: Find the rightmost digit smaller than 'digits[max]' to swap with it.
        for (i = n - 1; i > max; i--) {  // Start from the right end of the vector.
            if (digits[i] < digits[max]) {  // Find the first smaller digit to swap.
                // Swap 'digits[max]' with 'digits[i]'.
                tempNum = digits[max];  // Temporary store the value at 'max' index.
                digits[max] = digits[i];  // Replace 'max' index value with the smaller digit.
                digits[i] = tempNum;  // Place the original 'max' value at 'i' index.
                break;  // Break after the swap; only one swap is allowed.
            }
        }

        // Step 5: Reconstruct the number from the modified digits vector.
        for (i = n - 1; i >= 0; i--) {  // Traverse the digits from most to least significant.
            ans = ans * 10 + (digits[i] % 10);  // Build the final number by adding digits.
        }

        return ans;  // Return the maximum possible number after at most one swap.
    }
};
