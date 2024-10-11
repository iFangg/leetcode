// Solution 1
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        /*
        sort
        pair top and bottom values
        find sum of all products of pairs 
        */

        std::sort(skill.begin(), skill.end());

        long long chem = 0;
        auto left = 0;
        auto right = skill.size() - 1;
        auto prev = 0;

        while (left < right) {
            auto prod = skill[left] * skill[right];
            chem += prod;
            if (prev != 0 and prev != skill[left] + skill[right])
                return -1;
            prev = skill[left] + skill[right];
            ++left;
            --right;
        }

        return chem;
    }
};


// Solution 2
class Solution {
public:
    static long long dividePlayers(vector<int>& skill) {
        const int n = skill.size(), n_2 = n/2;  // n is total players, n_2 is number of teams
        long long sum = 0;
        int freq[1001] = {0};  // Frequency array to count occurrences of each skill level
        int xMax = 1, xMin = 1000;  // Track min and max skill levels

        // First pass: calculate sum, update frequency array, and find min/max skill
        for(int x : skill){
            sum += x;
            freq[x]++;
            xMax = max(x, xMax);
            xMin = min(x, xMin);
        }

        // Check if total skill can be evenly divided among teams
        if (sum % n_2 != 0) return -1;
        int team_skill = sum / n_2;  // Required skill sum for each team
        
        long long chemi = 0;  // Total chemistry
        int l, r;  // Left and right pointers for skill levels

        // Second pass: match players and calculate chemistry
        for(l = xMin, r = xMax; l < r; l++, r--){
            long long fL = freq[l], fR = freq[r];
            // Check if current pair forms valid team and frequencies match
            if (l + r != team_skill || fL != fR) return -1;
            chemi += fL * l * r;  // Add chemistry for all pairs with skills l and r
        }

        // Handle case where l == r (middle skill level)
        chemi += (l == r && l*2 == team_skill) ? freq[l]/2LL * l * l : 0LL;

        return chemi;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
