// Solution 1 - FAIL
class Solution {
    private int moves = Integer.MAX_VALUE;
    private int[] target = {1, 2, 3, 4, 5, 0};
    private int[][] board_;

    public int slidingPuzzle(int[][] board) {
        /**
        brute force swaps?
        backtracking swaps until you reach solution?
        with each possible move
            how to account for cycles?
                store seen configurations
                store configurations in a flattened map
                store position of 0
                up/down = +- 3 positions
                left/right = +- 1 position
                    double check position as to not transcend dimensions
                    index 2 and 3 are different planes
            match corrent config to result
         */
        
        
        board_ = board;
        ArrayList<Integer> starting = Arrays.stream(board)
        .flatMapToInt(Arrays::stream)
        .toArray();
        ArrayList<ArrayList<Integer>> seen = new ArrayList<>();
        int zero_r = 0;
        int zero_c = 0;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == 0) {
                    zero_r = i;
                    zero_c = j;
                    break;
                }
            }
        }


        bt(0, zero_r, zero_c, starting, seen);
        
        if (moves == Integer.MAX_VALUE)
            return -1;

        return moves;
    }

    private void bt(int n_moves, int r, int c, ArrayList<Integer> config, ArrayList<ArrayList<Integer>> seen) {
        if (seen.contains(config))
            return;

        if (Arrays.equals(config, target)) {
            moves = Math.min(moves, n_moves);
            return;
        }

        int index = r * board_[0].length + c;
        seen.add(config);

        if (r - 1 >= 0) {
            int row = (r - 1) * board_[0].length + c;
            config[index] = config[row];
            config[row] = 0;
            bt(n_moves, r - 1, c, config, seen);

            config[row] = config[index];
            config[index] = 0;
        }

        if (r + 1 < board_.length) {
            int row = (r + 1) * board_[0].length + c;
            config[index] = config[row];
            config[row] = 0;
            bt(n_moves, r - 1, c, config, seen);

            config[row] = config[index];
            config[index] = 0;
        }

        if (c - 1 >= 0) {
            int col = r * board_[0].length + c - 1;
            config[index] = config[col];
            config[col] = 0;
            bt(n_moves, r, c - 1, config, seen);

            config[col] = config[index];
            config[index] = 0;
        }

        if (c + 1 < board_[0].length) {
            int col = r * board_[0].length + c + 1;
            config[index] = config[col];
            config[col] = 0;
            bt(n_moves, r, c + 1, config, seen);

            config[col] = config[index];
            config[index] = 0;
        }
        
        return;
    }
}


// Solution 2 - FAIL
import java.util.*;

class Solution {
    private int moves = Integer.MAX_VALUE;
    private final int[] target = {1, 2, 3, 4, 5, 0}; // Use an array for target configuration
    private int[][] board_;

    public int slidingPuzzle(int[][] board) {
        board_ = board;

        // Flatten the board into a 1D array
        int[] starting = new int[6];
        int zeroIndex = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                starting[i * 3 + j] = board[i][j];
                if (board[i][j] == 0) {
                    zeroIndex = i * 3 + j; // Record the position of zero
                }
            }
        }

        // Use a Set to track visited configurations
        Set<String> seen = new HashSet<>();

        // Start backtracking
        backtrack(0, zeroIndex, starting, seen);

        return moves == Integer.MAX_VALUE ? -1 : moves;
    }

    private void backtrack(int n_moves, int zeroIndex, int[] config, Set<String> seen) {
        // Serialize the config as a string for efficient Set operations
        String serialized = Arrays.toString(config);

        // If this configuration has been seen, skip further processing
        if (seen.contains(serialized)) {
            return;
        }

        // If the target configuration is reached, update the minimum moves
        if (Arrays.equals(config, target)) {
            moves = Math.min(moves, n_moves);
            return;
        }

        // Mark this configuration as seen
        seen.add(serialized);

        // Possible moves for the zero position
        int[][] moves = {
            {1, 3},        // For index 0: can move to 1 or 3
            {0, 2, 4},     // For index 1: can move to 0, 2, or 4
            {1, 5},        // For index 2: can move to 1 or 5
            {0, 4},        // For index 3: can move to 0 or 4
            {1, 3, 5},     // For index 4: can move to 1, 3, or 5
            {2, 4}         // For index 5: can move to 2 or 4
        };

        // Try all valid moves for the current zero position
        for (int newIndex : moves[zeroIndex]) {
            // Swap zero with the target position
            swap(config, zeroIndex, newIndex);

            // Recursive call with updated configuration
            backtrack(n_moves + 1, newIndex, config, seen);

            // Undo the swap (backtracking)
            swap(config, zeroIndex, newIndex);
        }
    }

    // Helper method to swap two elements in the array
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}


// Solution 3
class Solution {
    public int slidingPuzzle(int[][] board) {
        // Directions for possible swaps based on '0' position
        int[][] dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        String target = "123450";
        Set<String> vis = new HashSet<>(); // Track visited configurations
        Queue<String> q = new LinkedList<>();
        String start = "";

        // Convert 2D board to a single string
        for (int[] row : board) {
            for (int col : row) {
                start += col;
            }
        }

        q.offer(start);
        vis.add(start);
        int step = 0;

        // Perform BFS
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                String current = q.poll();

                // Check if target is reached
                if (current.equals(target)) return step;

                int zero = current.indexOf('0'); // Find position of '0'

                // Generate next moves
                for (int move : dir[zero]) {
                    StringBuilder next = new StringBuilder(current);
                    char temp = next.charAt(zero);
                    next.setCharAt(zero, next.charAt(move));
                    next.setCharAt(move, temp);

                    if (!vis.contains(next.toString())) { // Add unvisited states to the queue
                        vis.add(next.toString());
                        q.offer(next.toString());
                    }
                }
            }
            step++;
        }
        return -1; // Return -1 if target is unreachable
    }
}
