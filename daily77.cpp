// Solution 1
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        /*
        loop through k until k is negative
            return index at which k became negative

        if k is divisible by n, return 0
        if k is not divisible by n,
            take remainder and loop thru chalk to find index where k is neg
        */

        long total = std::accumulate(chalk.begin(), chalk.end(), 0.0);
        long remainder = k % total;
        if (remainder == 0)
            return 0;

        int index = 0;
        while (remainder >= 0 and index < chalk.size()) {
            remainder -= chalk[index];
            ++index;
        }

        return index - 1;
    }
};


// Solution 2
class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    int chalkReplacer(vector<int>& chalk, int k) {
        long int r = 0;
        r = accumulate(chalk.begin(), chalk.end(), r);
        k = k % r;
        for(int i = 0; i < chalk.size(); i++)
        {
            k = k - chalk[i];
            if(k < 0){
                return i;
                break;
            }
        }return 0; 
    }
};


// Solution 3
inline unsigned long long vecfromstr(std::string& s, std::vector<unsigned long long>& chalk) {
    unsigned long long number = 0;
    unsigned long long prev_number = 0;
    chalk.clear();
    for (char* c = &s[1]; *c != '\0'; c++) {
        if (*c >= 48 && *c <= 57) {
            number = number * 10 + (*c & 15);
            continue;
        }
        unsigned long long newn = number + prev_number;
        chalk.push_back(newn);
        prev_number = newn;
        number = 0;
    }
    return prev_number;
}

int init = [] {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("user.out", "w", stdout);
    vector<unsigned long long> chalk;
    int k;
    for (std::string s; getline(cin, s);) {
        unsigned long long max = vecfromstr(s, chalk);
        getline(cin, s);
        k = std::stoi(s);
        unsigned long long left = k % max;
        vector<unsigned long long>::iterator u;
        u = upper_bound(chalk.begin(), chalk.end(), left);
        std::cout << (u-chalk.begin()) << '\n';
    }
    return 0;
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) { return 0; }
};
