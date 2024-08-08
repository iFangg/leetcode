// Solution 1
class Solution {
public:
    int m_bouquets(vector<int>& bloomDay, int& mid, int& m, int& k) {
        auto bouquet = int{0};
        auto count = int{0};
        for (auto i = size_t{0}; i < bloomDay.size(); ++i) {
            if (bloomDay[i] <= mid) count++;
            else count = 0;
            if (count == k) {
                bouquet++;
                count = 0;
            }
            if (bouquet == m) return true;
        }
        
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (static_cast<long>(m) * static_cast<long>(k) > bloomDay.size()) return -1;

        auto left = *std::min_element(bloomDay.begin(), bloomDay.end());
        if (m == 1 and k == 1) return left;
        auto right = *std::max_element(bloomDay.begin(), bloomDay.end());
        while (left <= right) {
            auto mid = left + (right - left) / 2;
            // std::cout << "left: " << left << ", right: " << right << ", mid: " << mid << "\n";
            auto possible = m_bouquets(bloomDay, mid, m, k);

            if (possible) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }

        if (m_bouquets(bloomDay, left, m, k)) return left;

        return -1;
    }
};


// Solution 1.b
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (static_cast<long>(m) * static_cast<long>(k) > bloomDay.size()) return -1;

        auto left = *std::min_element(bloomDay.begin(), bloomDay.end());
        if (m == 1 and k == 1) return left;
        auto right = *std::max_element(bloomDay.begin(), bloomDay.end());
        auto result = int{-1};
        while (left <= right) {
            long mid = left + (right - left) / 2;
            auto bouquet = int{0};
            auto count = int{0};
            for (auto i = size_t{0}; i < bloomDay.size(); ++i) {
                if (bloomDay[i] <= mid) count++;
                else count = 0;
                if (count >= k) {
                    bouquet++;
                    count = 0;
                }
            }

            if (bouquet >= m) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};


// Solution 2
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long max = *max_element(bloomDay.begin(), bloomDay.end());
        long long low = 0;
        int answer = -1;
        while (low <= max) {
            long long day = low + (max - low) / 2;
            int noOfBouquete = 0;
            int count = 0;
            for (int i = 0; i < bloomDay.size(); i++) {
                if (bloomDay[i] <= day) {
                    count++;
                } else {
                    count = 0;
                }
                if (count >= k) {
                    noOfBouquete++;
                    count = 0;
                }
            }
            if (noOfBouquete >= m) {
                answer = day;
                max = day - 1;
            } else if (noOfBouquete < m)
                low = day + 1;
        }
        return answer;
    }
};

