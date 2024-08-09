// Solution 1
class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        result.push_back({rStart, cStart});
        int steps = 1;  // Number of steps we need to take in a direction
        int count = 1;  // Number of cells visited

        int r = rStart;
        int c = cStart;

        while (count < total) {
            // Move right
            for (int i = 0; i < steps; ++i) {
                c += 1;
                if (c >= 0 && c < cols && r >= 0 && r < rows) {
                    result.push_back({r, c});
                    count++;
                }
            }

            // Move down
            for (int i = 0; i < steps; ++i) {
                r += 1;
                if (c >= 0 && c < cols && r >= 0 && r < rows) {
                    result.push_back({r, c});
                    count++;
                }
            }

            steps++;

            // Move left
            for (int i = 0; i < steps; ++i) {
                c -= 1;
                if (c >= 0 && c < cols && r >= 0 && r < rows) {
                    result.push_back({r, c});
                    count++;
                }
            }

            // Move up
            for (int i = 0; i < steps; ++i) {
                r -= 1;
                if (c >= 0 && c < cols && r >= 0 && r < rows) {
                    result.push_back({r, c});
                    count++;
                }
            }

            steps++;
        }

        return result;
    }
};

