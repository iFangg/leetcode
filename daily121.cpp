// Solution 1 (thanks dylan and sarah)
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        /*
        find order of letters to be placed
            place in max heap? 
                update after every 2 same characters (or 1 if not enough)
                max heap of pairs, char and freq

                while still possible to add characters or max heap isnt empty:
                    take char with highest frequency and add 2 to string
                    pop off heap
                    take the next char add at most 2
                    pop off
                    re add both char's with updated freq
                    repeat until heap is empty or still possible
            
            if placed 2, but no other characters exist return string
        */
        auto char_freq = std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::less<>>{};
        char_freq.push({a, 'a'});
        char_freq.push({b, 'b'});
        char_freq.push({c, 'c'});

        auto res = std::string{};

        while (!char_freq.empty()) {
            // std::cout << "curr str is " << res << std::endl;
            auto first_c = char_freq.top();
            char_freq.pop();

            auto limit = 2;

            // check if last two are the same as current
            if (res.size() >= 2 and first_c.second == res.back() and first_c.second == res[res.size() - 2]) {
                return res;
            }

            if (res.size() and first_c.second == res.back())
                limit = 1;

            for (int i = 0; first_c.first > 0 and i < limit; ++i) {
                res += first_c.second;
                first_c.first--;
            }

            if (char_freq.empty())
                return res;

            auto second_c = char_freq.top();
            char_freq.pop();

            for (int i = 0; second_c.first > 0 and i < 1; ++i) {
                res += second_c.second;
                second_c.first--;
            }

            std::cout << "updated first val: " << first_c.second << " - " << first_c.first << std::endl;
            std::cout << "updated second val: " << second_c.second << " - " << second_c.first << std::endl;

            if (first_c.first > 0)
                char_freq.push(first_c);
            
            if (second_c.first > 0)
                char_freq.push(second_c);
        }

        return res;
    }
};


// Solution 2
class Solution {
public:
    // This function finds the two largest values among a, b, and c.
    pair<int, int> fun(int a, int b, int c) {
        // k1 stores the largest value among a, b, and c.
        int k1 = max(max(a, b), c);
        int k2;

        // k2 stores the second largest value among the remaining two.
        if (k1 == a) k2 = max(b, c); // If a is the largest, compare b and c.
        if (k1 == b) k2 = max(a, c); // If b is the largest, compare a and c.
        if (k1 == c) k2 = max(a, b); // If c is the largest, compare a and b.

        // Return the largest (k1) and second largest (k2) as a pair.
        return make_pair(k1, k2);
    }

    // Main function that generates the longest diverse string.
    string longestDiverseString(int a, int b, int c) {
        string res = "";  // Resultant string to store the output.
        int curr = 0;      // Keeps track of the current length of the result string.

        // Continue until all characters are used (a + b + c > 0).
        while ((a + b + c) > 0) {
            // Print the current values of a, b, c (for debugging).
            cout << a << " " << b << " " << c << "\n";
            cout << res << " " << curr << "\n";

            // Find the largest and second largest counts using the `fun` helper function.
            pair<int, int> p = fun(a, b, c);

            // Check if the largest count corresponds to 'a'.
            if (p.first == a) {
                // Check if the last two characters in the result are 'aa'.
                if (res.size() >= 2 && res[curr - 2] == 'a' && res[curr - 1] == 'a') {
                    // If adding 'a' would result in "aaa", use the second largest character.
                    if (p.second == 0) return res;  // If no second-largest character is available, return the result.
                    if (p.second == b) { 
                        res = res + "b";  // Add 'b' if it is the second largest.
                        b--;
                    } else {
                        res = res + "c";  // Add 'c' if it is the second largest.
                        c--;
                    }
                } else {
                    // If it’s safe to add 'a', add it.
                    res = res + "a";
                    a--;
                }
                curr++;  // Increment the current length.
            } 
            // Check if the largest count corresponds to 'b'.
            else if (p.first == b) {
                // Check if the last two characters in the result are 'bb'.
                if (res.size() >= 2 && res[curr - 2] == 'b' && res[curr - 1] == 'b') {
                    // If adding 'b' would result in "bbb", use the second largest character.
                    if (p.second == 0) return res;  // If no second-largest character is available, return the result.
                    if (p.second == a) { 
                        res = res + "a";  // Add 'a' if it is the second largest.
                        a--;
                    } else {
                        res = res + "c";  // Add 'c' if it is the second largest.
                        c--;
                    }
                } else {
                    // If it’s safe to add 'b', add it.
                    res = res + "b";
                    b--;
                }
                curr++;  // Increment the current length.
            } 
            // If the largest count corresponds to 'c'.
            else {
                // Check if the last two characters in the result are 'cc'.
                if (res.size() >= 2 && res[curr - 2] == 'c' && res[curr - 1] == 'c') {
                    // If adding 'c' would result in "ccc", use the second largest character.
                    if (p.second == 0) return res;  // If no second-largest character is available, return the result.
                    if (p.second == b) { 
                        res = res + "b";  // Add 'b' if it is the second largest.
                        b--;
                    } else {
                        res = res + "a";  // Add 'a' if it is the second largest.
                        a--;
                    }
                } else {
                    // If it’s safe to add 'c', add it.
                    res = res + "c";
                    c--;
                }
                curr++;  // Increment the current length.
            }
        }

        // Return the final generated string.
        return res;
    }
};

