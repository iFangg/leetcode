// Solution 1
class Solution {
    public String minWindow(String s, String t) {
        /*
            have 2 hashmaps for char counts in t and s substr
            start with sliding window size t.len
            if 2 hashmaps equal
                update minimum string
                reduce left
            else
                increase right
            
            stop when left = end of string s
        */

        int t_len = t.length();
        int s_len = s.length();

        if (t_len > s_len)
            return "";

        HashMap<Character, Integer> t_hash = new HashMap<>();
        HashMap<Character, Integer> s_hash = new HashMap<>();

        for (char c : t.toCharArray()) {
            t_hash.put(c, t_hash.getOrDefault(c, 0) + 1);
        }


        String min = "";
        int l = 0;
        int r = t_len;
        for (int i = l; i < r; i++) {
            char c = s.charAt(i);
            if (!t_hash.containsKey(c))
                continue;
            
            if (s_hash.containsKey(c))
                s_hash.put(c, s_hash.get(c) + 1);
            else
                s_hash.put(c, 1);
        }

        while (l < s_len && l <= r) {
            if (hash_geq(t_hash, s_hash)) {
                if (min.isEmpty() || r - l < min.length())
                    min = s.substring(l, r);
                
                char l_c = s.charAt(l);
                if (t_hash.containsKey(l_c)) {
                    s_hash.put(l_c, s_hash.get(l_c) - 1);
                }

                l++;
            } else {
                if (r >= s_len)
                    break;

                char r_c = s.charAt(r);
                if (t_hash.containsKey(r_c))
                    s_hash.put(r_c, s_hash.getOrDefault(r_c, 0) + 1);

                r++;
            }
        }

        return min;
    }

    public boolean hash_geq(HashMap<Character, Integer> t, HashMap<Character, Integer> s) {
        if (t.size() != s.size())
            return false;
        
        if (t.equals(s))
            return true;
        
        for (char k : s.keySet()) {
            if (s.get(k) < t.get(k))
                return false;
        }
        
        return true;
    }
}


// Solution 2
class Solution {
    public String minWindow(String s, String t) {
        // Convert input strings `s` and `t` to character arrays for faster access
        char[] sArray = s.toCharArray();
        char[] tArray = t.toCharArray();
        
        // Initialize variables for the sliding window pointers, the start index of the result,
        // a "balance" counter, and the size of the smallest substring found.
        int start = 0;
        int end = 0;
        int startIndex = 0;  // Start index of the minimum substring
        int balance = 0;     // Number of characters still needed to match `t`
        int size = Integer.MAX_VALUE;  // Track the smallest substring length
        
        // Frequency array to store the count of each character in `t`.
        // Assumes input is ASCII (128 characters).
        int[] freq = new int[128];
        
        // Populate the frequency array with the counts of characters in `t`.
        for (char c : tArray) {
            balance++;       // Increment balance for each character in `t`
            freq[c]++;       // Increase the count for the character
        }

        // Start the sliding window
        while (end < sArray.length) {
            // If the current character reduces the deficit (exists in `t` and is needed), decrement `balance`.
            if (freq[sArray[end]] > 0) {
                balance--;
            }
            
            // Decrease the frequency of the current character (even if it's not in `t`).
            freq[sArray[end]]--;
            
            // Expand the window by moving the `end` pointer.
            end++;

            // When the balance is zero, we have a valid window (contains all characters from `t`).
            while (balance == 0) {
                // Update the size of the minimum window if the current window is smaller.
                if (end - start < size) {
                    size = end - start;  // Update the size of the smallest window
                    startIndex = start;  // Store the start index of this valid window
                }
                
                // Try to shrink the window from the left by moving `start`.
                // If the character at `start` is needed (its count is 0), increasing it will unbalance the window.
                if (freq[sArray[start]] == 0) {
                    balance++;
                }
                
                // Restore the frequency count for the character at `start`.
                freq[sArray[start]]++;
                
                // Move the `start` pointer to the right.
                start++;
            }
        }

        // If no valid window was found, return an empty string. Otherwise, return the substring.
        return size == Integer.MAX_VALUE ? "" : s.substring(startIndex, startIndex + size);
    }
}

