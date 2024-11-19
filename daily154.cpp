// Solution 1 - FAIL
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        /*
        0 case, return array of 0
        find sum of array
        add (sum - ith number) to the ith index
            THIS IS WRONG, PLS READ THE QUESTION SLOWER
        

        */

        auto n = code.size();
        auto res = std::vector<int>(n, 0);
        if (k == 0)
            return res;
        
        auto count = std::abs(k);

        for (int i = 0; i < n; ++i) {
            int dir = k > 0 ? 1 : -1;
            auto pos = (i + dir) % n;
            for (int j = 0; j < count; j++) {
                res[i] += code[pos];
                pos = (pos + dir) % n;
            }
        }

        return res;
    }
};


// Solution 2
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        auto n = code.size();
        auto res = std::vector<int>(n, 0);
        if (k == 0)
            return res;
        
        auto count = std::abs(k);

        for (int i = 0; i < n; ++i) {
            int dir = k > 0 ? 1 : -1;
            auto pos = i + dir;
            if (pos < 0)
                pos = n + pos;
            else
                pos %= n;

            for (int j = 0; j < count; j++) {
                res[i] += code[pos];
                pos += dir;

                if (pos < 0)
                    pos = n + pos;
                else
                    pos %= n;
            }
        }

        return res;
    }
};


// Solution 3
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if (k == 0)
            return vector<int>(n, 0);

        // Build the prefix array with duplicated code values
        vector<int> prefix(2 * n);
        prefix[0] = code[0];
        for (int i = 1; i < 2 * n; ++i)
            prefix[i] = prefix[i - 1] + code[i % n];

        vector<int> res(n);
        calculateSum(res, k, prefix);

        return res;
    }

private:
    void calculateSum(vector<int>& res, int k, vector<int>& prefix) {
        int n = res.size();
        if (k > 0) {
            // Right Sum
            for (int i = 0; i < n; ++i)
                res[i] = prefix[i + k] - prefix[i];
        } else {
            // Left Sum
            k = abs(k);
            for (int i = n; i < 2 * n; ++i)
                res[i - n] = prefix[i - 1] - prefix[i - k - 1];
        }
    }

};
/*
//JAVA
import java.util.*;

class Solution {
    private void calculateSum(int[] res, int k, int[] prefix) {
        int n = res.length;
        if (k > 0) {
            // Right Sum
            for (int i = 0; i < n; ++i)
                res[i] = prefix[i + k] - prefix[i];
        } else {
            // Left Sum
            k = Math.abs(k);
            for (int i = n; i < 2 * n; ++i)
                res[i - n] = prefix[i - 1] - prefix[i - k - 1];
        }
    }

    public int[] decrypt(int[] code, int k) {
        int n = code.length;
        if (k == 0)
            return new int[n]; // Array filled with 0

        // Build the prefix array with duplicated code values
        int[] prefix = new int[2 * n];
        prefix[0] = code[0];
        for (int i = 1; i < 2 * n; ++i)
            prefix[i] = prefix[i - 1] + code[i % n];

        int[] res = new int[n];
        calculateSum(res, k, prefix);

        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] code = {5, 7, 1, 4};
        int k = 3;
        System.out.println(Arrays.toString(solution.decrypt(code, k)));
    }
}

#Python
class Solution:
    def calculate_sum(self, res, k, prefix):
        n = len(res)
        if k > 0:
            # Right Sum
            for i in range(n):
                res[i] = prefix[i + k] - prefix[i]
        else:
            # Left Sum
            k = abs(k)
            for i in range(n, 2 * n):
                res[i - n] = prefix[i - 1] - prefix[i - k - 1]

    def decrypt(self, code, k):
        n = len(code)
        if k == 0:
            return [0] * n

        # Build the prefix array with duplicated code values
        prefix = [0] * (2 * n)
        prefix[0] = code[0]
        for i in range(1, 2 * n):
            prefix[i] = prefix[i - 1] + code[i % n]

        res = [0] * n
        self.calculate_sum(res, k, prefix)

        return res


# Example usage
solution = Solution()
code = [5, 7, 1, 4]
k = 3
print(solution.decrypt(code, k))  # Output: [12, 10, 16, 13]

*/

