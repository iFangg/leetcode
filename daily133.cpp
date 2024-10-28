// Solution 1 - FAIL
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        /*
        sort array
        track max lenth (default is -1)
        if n ^ 2= n + 1
            curr len +=1
        
        update max len every time a streak ends
        need hashmap for smallest non-square values
        */

        std::sort(nums.begin(), nums.end());
        auto streaks = std::unordered_map<int, int>{};

        for (auto i = 0; i < nums.size(); ++i) {
            auto& n = nums[i];
            if (!streaks.contains(n)) {}
                streaks[n] = 1;
        }

        auto seen = std::unordered_set<int>{};
        int max_len = -1;

        for (auto& n : nums) {
            // std::cout << "new\n";
            int curr_len = 0;
            if (seen.contains(n))
                continue;

            long long next = n;
            while (streaks.contains(next)) {
                // std::cout << next << std::endl;
                seen.insert(next);
                curr_len += streaks[n];
                next *= next;
            }

            max_len = std::max(max_len, curr_len);
        }

        return max_len > 1 ? max_len : -1;
    }
};


// Solution 2
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        /*
        sort array
        track max lenth (default is -1)
        need hashmap for values
            from largest value, sqrt it until we get to a prime number
            add all these to hashmap, set value to 0 for unseen
            if smaller number appears in array, set value to 1
        find longest subsequence from largest value
            if sqrt exists
                increment current length
                we switch to look at that number and keep finding
            else
                update max len
                reset current length
        */

        std::sort(nums.begin(), nums.end());
        auto has = std::unordered_set<double>(nums.begin(), nums.end());
        int max_len = -1;

        for (int i = nums.size() - 1; i >= 0; --i) {
            // std::cout << "new";
            double n = nums[i];
            auto curr_len = 0;

            while (has.contains(n)) {
                // std::cout << n << std::endl;
                ++curr_len;
                n = std::sqrt(n);
            }

            max_len = std::max(max_len, curr_len);
        }

        return max_len > 1 ? max_len : -1;
    }
};


// Solution 3
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        constexpr int N{100'000};
        std::array<bool, N+1> ns{};

        for(const int i : nums) { ns[i] = true; }

        int ans{-1};

        for(size_t i{0}; i<N; ++i) {
            if (ns[i] == false) { continue; }

            int len{0};
            size_t index{i};
            while(index < N && ns[index]) {
                ++len;
                index = index * index;
            }

            if (len > 1) { ans = std::max(ans, len); }
        }

        return ans;
    }
};
