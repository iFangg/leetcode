#include <numeric>
#include <iostream>
#include <string>
#include <vector>

// Solution 1
class Solution {
public:
    std::string fractionAddition(std::string expression) {
         /*
        evaluate the given fractions, append each one to vector for numerators and denominators
        find whole number lcm of all denominators and multiply all numerators by lcm factor,
        sum all numerators
        if numerator sum % denominator == 0, result is result / 1
        result is numerator sum / denominator
         */

        auto numers = std::vector<int>{};
        auto denoms = std::vector<int>{};
        auto curr_num = std::string{};
        auto neg = false;

        for (auto i = 0; i < expression.size(); ++i) {
            if (expression[i] == '/') {
                if (neg)
                    numers.push_back(-std::stoi(curr_num));
                else
                    numers.push_back(std::stoi(curr_num));
                
                curr_num.clear();
                neg = false;
                continue;
            }

            if (expression[i] == '+' or expression[i] == '-') {
                if (curr_num.empty()) {
                    neg = (expression[i] == '-');
                } else {
                    if (neg)
                        denoms.push_back(-std::stoi(curr_num));
                    else
                        denoms.push_back(std::stoi(curr_num));
                    
                    curr_num.clear();
                    neg = (expression[i] == '-');
                }

                continue;
            }

            curr_num += expression[i];
        }
        
        if (!curr_num.empty()) {
            if (neg)
                denoms.push_back(-std::stoi(curr_num));
            else
                denoms.push_back(std::stoi(curr_num));
        }

        auto denom_lcm = denoms[0];
        for (auto d = 0; d < denoms.size(); ++d) {
            std::cout << denoms[d] << " ";
            denom_lcm = std::lcm(denom_lcm, denoms[d]);
        }
        std::cout << std::endl;

        auto sum = 0;
        for (auto n = 0; n < numers.size(); ++n) {
            std::cout << numers[n] << " ";
            sum += numers[n] * (denom_lcm / denoms[n]);
        }

        if (sum % denom_lcm == 0)
            return std::to_string(sum) + "/1";

        int sum_gcd = std::gcd(sum, denom_lcm);

        return std::to_string(sum / sum_gcd) + "/" + std::to_string(denom_lcm / sum_gcd);
    }
};


// Solution 2
#include <string>
#include <vector>
class Solution {
public:
    std::string fractionAddition(std::string expression) {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-') sign = -1;
                i++;
            }

            int num = 0;
            while (i < n && std::isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++;

            int den = 0;
            while (i < n && std::isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            numerator = numerator * den + num * denominator;
            denominator *= den;

            int gcdVal = std::gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};
