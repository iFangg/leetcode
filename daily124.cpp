// Solution 1
class Solution {
public:
    char findKthBit(int n, int k) {
        n_ = n;

        s = std::vector<std::string>(n + 1);
        s[1] = "0";

        getNextString(2);

        return s[n][k - 1];
    }

private:
    void getNextString(int curr) {
        if (curr - 1 == n_)
            return;

        s[curr] = s[curr - 1] + "1" + revInv(s[curr - 1]);

        getNextString(curr + 1);
    }

    std::string revInv(std::string b_str) {
        auto res = std::string{""};
        
        for (auto i = 0; i < b_str.size(); ++i) {
            res += b_str[i] == '1' ? "0" : "1";
        }
        
        std::reverse(res.begin(), res.end());
        return res; 
    }

    int n_;
    std::vector<std::string> s;
};


// Solution 2
class Solution {
public:
    // Function to find the k-th bit in the n-th binary string S(n).
    char findKthBit(int n, int k) {
        // Base Case: When n is 1, the only string is "0". 
        if (n == 1) {
            return '0';  // Return the 1st bit which is '0'.
        }

        // Calculate the length of the binary string S(n).
        // Length of S(n) = 2^n - 1.
        int len = (1 << n) - 1;  // (1 << n) means 2^n.

        // Calculate the middle position (1-based index).
        int mid = len / 2 + 1;

        // If the k-th bit is exactly the middle bit, return '1'.
        if (k == mid) {
            return '1';  // The middle bit is always '1'.
        }

        // If k is less than the middle, recursively search in the first half (S(n-1)).
        if (k < mid) {
            return findKthBit(n - 1, k);
        }

        // If k is greater than the middle, search in the second half.
        // The second half is the reverse(invert(S(n-1))).
        // Find the corresponding bit in the first half and invert it.
        char bit = findKthBit(n - 1, len - k + 1);  // Corresponding bit in S(n-1).
        return bit == '0' ? '1' : '0';  // Invert the bit.
    }
};
