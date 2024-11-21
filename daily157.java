// Solution 1
class Solution {
    public int checkGuards(int[][] grid, int[][] seen, int r, int c) {
        int total = 0;

        for (int i = r + 1; i < grid.length; i++) {
            if (seen[i][c] == 1)
                continue;

            if (grid[i][c] >= 1)
                break;

            seen[i][c] = 1;

            if (grid[i][c] == 0)
                total++;
        }

        for (int i = r - 1; i >= 0; i--) {
            if (seen[i][c] == 1)
                continue;

            if (grid[i][c] >= 1)
                break;

            seen[i][c] = 1;

            if (grid[i][c] == 0)
                total++;
        }

        for (int i = c + 1; i < grid[0].length; i++) {
            if (seen[r][i] == 1) {
                continue;
            }

            if (grid[r][i] >= 1)
                break;

            seen[r][i] = 1;

            if (grid[r][i] == 0) {
                total++;
            }
        }

        for (int i = c - 1; i >= 0; i--) {
            if (seen[r][i] == 1)
                continue;

            if (grid[r][i] >= 1)
                break;

            seen[r][i] = 1;

            if (grid[r][i] == 0)          
                total++;
        }

        return total;
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        /*
        start with mxn as resulting total
        for each guard sightline
            -- total cells until end of grid or encountered wall
            takes g^4 time?
        
        OR

        have hashmaps for each row and column, !!nvm sarah goated!!
        */

        int res = m * n;
        int[][] grid = new int[m][n];

        for (int[] r: grid) {
            Arrays.fill(r, 0);
        }

        for (int[] g : guards) {
            res--;
            grid[g[0]][g[1]] = 1;
        }

        for (int[] w : walls) {
            res--;
            grid[w[0]][w[1]] = 2;
        }

        int[][] seen = new int[m][n];

        for (int[] s : seen) {
            Arrays.fill(s, 0);
        }

        int r = 0;
        int c = 0;

        while (r < m && c < n) {
            if (grid[r][c] == 1) {
                res -= checkGuards(grid, seen, r, c);
            }

            c++;
            if (c == grid[0].length) {
                r++;
                c = 0;
            }
        }

        return res;
    }
}


// Solution 2
class Solution {
    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];
        int x, y;
        for (int[] guard : guards) {
            grid[guard[0]][guard[1]] = 1;
        }
        for (int[] wall : walls) {
            grid[wall[0]][wall[1]] = 1;
        }
        int count = 0;
        for (int[] guard : guards) {
            x = guard[0] - 1;
            y = guard[1];
            while (x >= 0 && grid[x][y] != 1) {
                if (grid[x][y] != -1) {
                    count++;
                    grid[x][y] = -1;
                }
                x--;
            }
            x = guard[0] + 1;
            while (x < m && grid[x][y] != 1) {
                if (grid[x][y] != -1) {
                    count++;
                    grid[x][y] = -1;
                }
                x++;
            }
            x = guard[0];
            y = guard[1] - 1;
            while (y >= 0 && grid[x][y] != 1) {
                if (grid[x][y] != -1) {
                    count++;
                    grid[x][y] = -1;
                }
                y--;
            }
            y = guard[1] + 1;
            while (y < n && grid[x][y] != 1) {
                if (grid[x][y] != -1) {
                    count++;
                    grid[x][y] = -1;
                }
                y++;
            }
        }
        return m * n - guards.length - walls.length - count;
    }
}
