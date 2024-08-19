// Solution 1
class Solution {
public:
    int minSteps(int n) {
        if (n == 1)
            return 0;
        /*
        keep track of number of operations
        clipboard is originally set asnothing
        keep track of the current string and clipboard
        
        two options, copy current string, or paste clipboard (if not empty)
        if pasting the clipboard gives us a longer or equal answer (so long as <=  target) than just adding an 'A'
            paste
        if doubling current string is greater than pasting clipboard or adding an 'A'
            copy and paste
        else 
            just add 'A'
        

        dp(i, j)? - i number of As, j being if we chose to copy or paste
        */

        auto current = 1;
        auto clipboard = 0;
        auto count = 0;
        while (current != n) {
            if (!clipboard) {
                clipboard = 1;
                count++;
                continue;
            }
            // do we add?
            if (current + 1 == n)
                return count + 1;
            
            auto doubled = current * 2;
            auto curr_and_clip = current + clipboard;

            // paste?
            if (curr_and_clip == n)
                return count + 1;

            // or copy?
            if (doubled == n)
                return count + 2;
            
            if (doubled < n) {
                if (curr_and_clip >= doubled) {
                    current = curr_and_clip;
                    count++;
                    continue;
                }

                if (doubled >= current + 1) {
                    clipboard = current;
                    count += 2;
                    current *= 2;
                    continue;
                } 
            }
            
            current++;
            count++;
        }

        return count;
    }
}

// Solution 2
class Solution {
public:
    int minSteps(int n) {
        int count = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                count += i;
                n /= i;
            }
        }
        return count;
    }
};

