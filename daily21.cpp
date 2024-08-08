// Solution 1
class Solution {
public:
    int findTheWinner(int n, int k) {
        auto eliminated = std::unordered_set<int>{};
        auto out = 0;
        while (eliminated.size() < n - 1) {
            auto count = 0;
            while (count < k) {
                out = (out + 1) % n;
                if (out == 0)
                    out = n;
                if (!eliminated.contains(out))
                    count++;
            }

            eliminated.insert(out);
        }

        for (int winner = 1; winner <= n; ++winner) {
            if (!eliminated.contains(winner)) {
                return winner;
            }
        }

        return -1;
    }
};

// Solution 2
class Solution {
public:
    int solve(int n, int k){
        if (n == 1)
            return 0;
        return (solve(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return solve(n, k) + 1;
    }
};
