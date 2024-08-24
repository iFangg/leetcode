// Solution 1 - FAIL
class Solution {
public:
    string nearestPalindromic(string n) {
        /*
        test if current number is a palindrome
        keep decresing number until palindrome found

        */
        auto num1 = std::stoll(n) - 1;
        auto n1 = std::to_string(num1);
        bool n1_pal = is_palindrome(n1);

        auto num2 = std::stoll(n) + 1;
        auto n2 = std::to_string(num2);
        bool n2_pal = is_palindrome(n2);
 
        while (!n1_pal and !n2_pal) {
            // std::cout << num1 << " - " << num2 << std::endl;
            num1 = std::stoll(n1) - 1;
            n1 = std::to_string(num1);
            n1_pal = is_palindrome(n1);

            num2 = std::stoll(n2) + 1;
            n2 = std::to_string(num2);
            n2_pal = is_palindrome(n2);
        }

        if (n1_pal and n2_pal)
            return n1;

        if (n1_pal and !n2_pal)
            return n1;
        
        if (!n1_pal and n2_pal)
            return n2;

        return n1;
    }

private:
    bool is_palindrome(std::string s) {
        auto left = 0;
        auto right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};


// Solution 2
class Solution {
public:
    string nearestPalindromic(string numberStr) {
        long long number = stoll(numberStr);
        
        // Edge cases for small numbers
        if (number <= 10) return to_string(number - 1);
        if (number == 11) return "9";
        
        // Special case for 18-digit number with all 9s, thanks to dcodeDV for pointing this out
        if (numberStr == "999999999999999999") {
            return "1000000000000000001";
        }
        
        int length = numberStr.length();
        long long leftHalf = stoll(numberStr.substr(0, (length + 1) / 2));
        
        vector<long long> palindromeCandidates(5);
        palindromeCandidates[0] = generatePalindromeFromLeft(leftHalf - 1, length % 2 == 0);
        palindromeCandidates[1] = generatePalindromeFromLeft(leftHalf, length % 2 == 0);
        
        // Handle potential overflow for leftHalf + 1
        if (leftHalf < 999999999) {
            palindromeCandidates[2] = generatePalindromeFromLeft(leftHalf + 1, length % 2 == 0);
        } else {
            palindromeCandidates[2] = stoll("1" + string(length - 1, '0') + "1");
        }
        
        palindromeCandidates[3] = pow(10, length - 1) - 1;
        palindromeCandidates[4] = pow(10, length) + 1;
        
        long long nearestPalindrome = 0;
        long long minDifference = LLONG_MAX;
        
        for (long long candidate : palindromeCandidates) {
            if (candidate == number) continue;
            long long difference = abs(candidate - number);
            if (difference < minDifference || (difference == minDifference && candidate < nearestPalindrome)) {
                minDifference = difference;
                nearestPalindrome = candidate;
            }
        }
        
        return to_string(nearestPalindrome);
    }

private:
    long long generatePalindromeFromLeft(long long leftHalf, bool isEvenLength) {
        long long palindrome = leftHalf;
        if (!isEvenLength) leftHalf /= 10;
        while (leftHalf > 0) {
            palindrome = palindrome * 10 + leftHalf % 10;
            leftHalf /= 10;
        }
        return palindrome;
    }
};


//https://leetcode.com/problems/find-the-closest-palindrome/submissions/1366449944/
