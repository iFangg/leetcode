// Solution 1 - FAIL
class Solution {
public:
    int nthUglyNumber(int n) {
        /*
            recursion
            next ugly num_ber from n - 1th num_ner
        */
        if (n <= 5)
            return n;

        auto num_ = nthUglyNumber(n - 1) + 1;

        while (!is_ugly(num_)) {
            ++num_;
        } 

        return num_;
    }
private:
    bool is_ugly(int n) {
        auto factors = std::vector<int>{};

        for (auto i = 1; i < n / 2; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
                if (isPrime(i)) {
                    if (i != 2 and i != 3 and i != 5)
                        return false;
                }

                factors.push_back(n / i);
                if (isPrime(n / i)) {
                    if (n / i != 2 and n / i != 3 and n / i != 5)
                        return false;
                }
            }
        }

        return true;
    }

    bool isPrime(int n) {
        // Handle edge cases
        if (n <= 1) return false;  // 0, 1, and negative num_bers are not prime
        if (n == 2) return true;   // 2 is the only even prime num_ber
        if (n % 2 == 0) return false; // Even num_bers greater than 2 are not prime

        // Check divisibility from 3 up to the square root of n
        for (int i = 3; i <= std::sqrt(n); i += 2) {
            if (n % i == 0) return false;
        }

        return true;
    }

    int num_ = 0;
};


// Solution 2
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> uglyNumbers(n);
        uglyNumbers[0] = 1;
        
        int i2 = 0, i3 = 0, i5 = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        
        for (int i = 1; i < n; ++i) {
            int nextUgly = std::min({next2, next3, next5});
            uglyNumbers[i] = nextUgly;
            
            if (nextUgly == next2) {
                i2++;
                next2 = uglyNumbers[i2] * 2;
            }
            if (nextUgly == next3) {
                i3++;
                next3 = uglyNumbers[i3] * 3;
            }
            if (nextUgly == next5) {
                i5++;
                next5 = uglyNumbers[i5] * 5;
            }
        }
        
        return uglyNumbers[n - 1];
    }
};

