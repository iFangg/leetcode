// Solution 1
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        if (m == 2) return position.back() - position.front();
        auto left = int{1};
        auto right = position.back() - position.front();
        auto baskets = std::unordered_set<int>(position.begin(), position.end());
        auto result = int{0};
        while (left <= right) {
            auto mid = long{left + (right - left) / 2};
            auto basket_num = int{1};
            auto last_pos = position.front();
            for (auto i = int{1}; i < position.size(); ++i) {
                if (position[i] - last_pos >= mid) {
                    basket_num++;
                    last_pos = position[i];
                }

                if (basket_num >= m) break;
            }

            if (basket_num >= m) {
                left = mid + 1;
                result = mid;
            } else if (basket_num < m) {
                right = mid - 1;
            }
        }

        return result;
    }
};


// Solution 2
class Solution {
public:
    bool isAcceptable(vector<int>& position, int m, int mid) {
        int ballCount = 1;
        int ballPosition = position[0];
        for (int i = 1; i < position.size(); i++) {
            if (position[i] - ballPosition >= mid) {
                ballCount++;
               
                ballPosition = position[i];
            }
        }
         if (ballCount >= m) return true;
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start = 1;
        int end = position.back() - position.front();
        int result = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isAcceptable(position, m, mid)) {
                start = mid + 1;
                result = mid;
            } else {
                end = mid - 1;
            }
        }

        return result;
    }
};

// Used to speed up run time
auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();



