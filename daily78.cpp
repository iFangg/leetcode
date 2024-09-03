// Solution 1 - FAIL (kinda?)
class Solution {
public:
    int getLucky(string s, int k) {
        /*
        loop thru and find sum k times

        map string to hashmap
        calculate length of string after transformation
        repeat k times
        */

        auto convert_map = std::unordered_map<int, int>{};
        auto sum = 0;

        for (auto i = 0; i < s.size(); ++i) {
            if (!std::isdigit(s[i])) {
                convert_map[i] = s[i] - 'a' + 1;
            }
            
            sum += convert_map[i];  
        }

        auto transforms = 1;
        
        while (transforms < k) {
            sum = 0;
            auto len = 0;
            for (auto& [k, v] : convert_map) {
                if (v < 10) {
                    sum += v;
                    ++len;
                } else {
                    auto digits = numDigits(v);
                    len += digits;

                    auto tens = std::pow(10, digits - 1);
                    while (v % static_cast<int>(tens) != v) {
                        sum += v % static_cast<int>(tens);
                        tens /= 10;
                    }
                }
            }

            auto num = std::to_string(sum);
            for (auto i = 0; i < len; ++i) {
                convert_map[i] = num[i];
            }

            ++transforms;
        }

        return sum;
    }

private:
    int numDigits(int number)
    {
        int digits = 0;
        // if (number < 0) digits = 1; // remove this line if '-' counts as a digit
        while (number) {
            number /= 10;
            digits++;
        }
        return digits;
    }
}


// Solution 2
class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert the string to its numeric equivalent
        int sum = 0;
        for (char c : s) {
            int num = c - 'a' + 1;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
        }

        // Step 2: Perform the summation k-1 more times
        for (int i = 1; i < k; ++i) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }

        return sum;
    }
};


