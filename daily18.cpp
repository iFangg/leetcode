// Solution 1
class Solution {
public:
    int passThePillow(int n, int time) {
        // if time is 1x, 3x, 5x n then it's going the original direction
        // if time is 2x, 4x, 6x n then it's going in the opposite direction
        // 1 2 3 4 - 5
        // (1) 2 3 4 3 2 1 | 2 3 4 3 2 1 | 2 3 4 3 ... cycles of n - 1 * 2
        auto period = (n - 1) * 2;
        auto t = time % period;
        if (t < n)
            return 1 + t;
        else
            return 1 + (period - t);
    }
};

// OR
class Solution {
public:
    int passThePillow(int n, int time) {
        if ((time % ((n - 1) * 2)) < n)
            return 1 + (time % ((n - 1) * 2));
        else
            return 1 + (((n - 1) * 2) - (time % ((n - 1) * 2)));
    }
}
