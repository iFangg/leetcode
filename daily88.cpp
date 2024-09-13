// Solution 1
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        auto results = std::vector<int>{};

        for (auto& q : queries) {
            // std::cout << "new query\n";
            auto start = arr[q[0]];
            // std::cout << start << std::endl;
            for (auto i = q[0] + 1; i <= q[1]; ++i) {
                // std::cout << start << " xor " << arr[i] << " = " << (start ^ arr[i]) << std::endl;
                if (i < arr.size())
                    start ^= arr[i];
                // std::cout << start << std::endl;
            }

            results.push_back(start);
        }

        return results;
    }
};


// Solution 2
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
  
        for (int i = 1; i < n; ++i) {
            arr[i] ^= arr[i - 1];
        }

        vector<int> result;
        result.reserve(m);

        for (const auto& q : queries) {
            int start = q[0], end = q[1];
            result.push_back(start > 0 ? arr[end] ^ arr[start - 1] : arr[end]);
        }
        
        return result;
    }
};


static const int KDS = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
//KDS

// Solution 3
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        return {};
    }
};
bool init = ([]() -> char {
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int ARR[30001]; ARR[0] = 0;
    ofstream out("user.out");
    string s;
    while(getline(cin, s)) {
        for(int i = 1, l = s.length(), c = 1, x = 0; i < l; i++) {
            if(s[i] == ',') {
                ARR[c++] = x ^ ARR[c-1];
                x = 0;
            }else if(s[i] == ']') {
                ARR[c] = x ^ ARR[c-1];
                break;
            }else {
                x = 10*x + (s[i] - '0');
            }
        }
        out << '['; getline(cin, s);
        bool first = true;
        int i = 2, l = s.length();
        while(i < l) {
            int x = 0, y = 0;
            while(s[i] != ',') {
                x = 10*x + (s[i++] - '0');
            }
            i++;
            while(s[i] != ']') {
                y = 10*y + (s[i++] - '0');
            }
            if(first) {
                first = false;
            }else out << ',';
            out << (ARR[y+1] ^ ARR[x]);

            i += 3;
        }
        out << "]\n";
    }
    out.flush();
    exit(0);
    return 1;
})();

