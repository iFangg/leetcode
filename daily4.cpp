// Solution 1
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // set grumpyless total, and find total outside of grumpyless range
        if (minutes == customers.size()) return std::accumulate(customers.begin(), customers.end(), 0);
        auto max = long{0};
        auto grumpyless = long{0};
        auto total = long{0};
        auto prev = customers[0];
        auto prev_idx = 0;
        for (auto i = 0; i < customers.size(); ++i) {
            if (i < minutes) grumpyless += customers[i];
            else if (!grumpy[i]) total += customers[i];
        }
        max = grumpyless + total;

        for (auto i = minutes; i < customers.size(); ++i) {
            // std::cout << "grumpyless section - " << grumpyless << ", total excluding grumpyless - " << total << ", max - " << max << "\n";
            grumpyless -= prev;
            grumpyless += customers[i];
            if (!grumpy[prev_idx]) total += prev;
            if (!grumpy[i]) total -= customers[i];
            
            max = std::max(max, total + grumpyless);
            prev_idx++;
            prev = customers[prev_idx];
        }

        return max;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Solution 2
class Solution {
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int n = customers.size(), satisfied = 0;
        for(int i = 0; i < n; i++) {
            if(grumpy[i] == 0) {
                satisfied += customers[i];
                customers[i] = 0;
            }
        }

        int i = 0, sum = 0, max = 0;
        while(i < minutes) {
            sum += customers[i];
            i++;
        }
        max = sum;

        while(i < n) {
            sum -= customers[i - minutes];
            sum += customers[i];
            max = std::max(sum, max);
            i++;
        }
        return max + satisfied;
    }
};
