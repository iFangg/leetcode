// Solution 1
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        /*
         sum all rolls, multiply by m
         subtract product from mean * (m + n)
         if difference is greater than 6 * n, answer is impossible
         else
            if difference is divisible by n, answer is the divisor, n times
            if not, add n as many times as possible, then add the remainder for the final missing roll
        */

        auto remainder = (rolls.size() + n) * mean - std::accumulate(rolls.begin(), rolls.end(), 0);
        if (remainder > 6 * n)
            return {};
        
        if (remainder % n == 0)
            return std::vector<int>(n, remainder / n);
        
        if (remainder / n == 0)
            return {};

        auto missing = std::vector<int>(n, remainder / n);
        auto curr_sum = std::accumulate(missing.begin(), missing.end(), 0);
        auto index = 0;

        while (curr_sum < remainder) {
            if (missing[index] == 6)
                index++;

            curr_sum += 1;
            missing[index] += 1;
        }

        return missing;
    }
};
