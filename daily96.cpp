// Solution 1
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        auto nums = std::vector<int>(n);

        for (auto i = 1; i <= n; ++i) {
            nums[i - 1] = i;
        }

        std::sort(nums.begin(), nums.end(), [](int a, int b) {
            auto a_str = std::to_string(a);
            auto a_idx = 0;
            auto b_str = std::to_string(b);
            auto b_idx = 0;

            while (a_idx < a_str.size() and b_idx < b_str.size()) {
                if (a_str[a_idx] == b_str[b_idx]) {
                    ++a_idx;
                    ++b_idx;
                } else
                    return a_str[a_idx] < b_str[b_idx];
            }

            return a < b;
        });

        return nums;
    }
};


// Solution 2
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};
