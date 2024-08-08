// Solution 1
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // importance = city, [total incomign and outgoing edges, importance]
        // amount of total in/out edges is importance?
        auto importance = std::unordered_map<int, int>{};
        auto in_out_edges = std::vector<std::pair<int,int>>(n, std::pair<int, int>{0 ,0});
        for (int i = 0; i < n; ++i) {
            in_out_edges[i].first = i;
            importance[i] = 0;
        }

        for (auto i = roads.begin(); i != roads.end(); ++i) {
            auto road = (*i)[0];
            auto dest = (*i)[1];
            in_out_edges[road].second++;
            in_out_edges[dest].second++;
        }
        std::sort(in_out_edges.begin(), in_out_edges.end(), [](std::pair<int, int>& a, std::pair<int, int>& b) {
            if (b.second == a.second) return b.first <= a.first;
            return b.second < a.second;
        });

        auto curr_imp = n;
        auto prev = int{0};
        for (auto a = in_out_edges.begin(); a != in_out_edges.end(); ++a) {
            importance[(*a).first] = curr_imp;
            curr_imp--;
            // std::cout << (*a).first << " ";
        }
        // std::cout << "\n";

        auto total = long{0};
        for (auto i = 0; i < roads.size(); ++ i) {
            total += importance[roads[i][0]] + importance[roads[i][1]];
        }

        return total;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Solution 2
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
        // cout.tie(nullptr);

        vector<long long> deg(n, 0);
        for (auto &a : roads) {
            deg[a[0]]++;
            deg[a[1]]++;
        }
        sort(deg.begin(), deg.end());
        long long ans = 0;
        for (long long i=0;i<n;i++) {
            ans += ( (i+1)*deg[i] );
        }
        return ans;
    }
};

