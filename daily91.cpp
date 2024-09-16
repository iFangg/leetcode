// Solution 1
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        /*
        Convert all times to hours and minutes
        sort based on hours and minutes
        */

        auto times = std::vector<std::pair<int, int>>{};

        for (auto i = 0; i < timePoints.size(); ++i) {
            auto h = std::stoi(timePoints[i].substr(0, 2));
            auto min = std::stoi(timePoints[i].substr(3, 2));
            auto time = std::make_pair(h, min);
            times.push_back(time);
            
            if (h == 0) {
                times.push_back(std::make_pair(24, min));
            } else if (h < 12) {
                times.push_back(std::make_pair(24 + h, min));
            }
        }

        std::sort(times.begin(), times.end(), [](std::pair<int, int> l, std::pair<int, int> r) {
            if (l.first == r.first)
                return l.second < r.second;

            return l.first < r.first;
        });
        // for (auto& [h, m] : times) {
        //     std::cout << h << ":" << m << std::endl;
        // }

        auto min = INT_MAX;
        auto index = 1;
        while (index < times.size()) {
            auto h2 = times[index].first;
            auto min2 = times[index].second;
            auto h1 = times[index - 1].first;
            auto min1 = times[index - 1].second;

            if (h1 > h2) {
                std::swap(h1, h2);
                std::swap(min1, min2);
            } else if (h1 == h2) {
                if (min1 > min2) {
                    std::swap(h1, h2);
                    std::swap(min1, min2);
                }
            }
            // std::cout << "time 1: " << h1 << ":" << min1 << ", time 2: " << h2 << ":" << min2 << std::endl;

            auto delta_h = h2 - h1;
            auto delta_min = min2 - min1;

            if (delta_min < 0) {
                delta_min = 60 + delta_min;
                --delta_h;
            }

            // std::cout << "delta h: " << delta_h << ", delta_min: " << delta_min << std::endl;

            min = std::min(min, delta_h * 60 + delta_min);

            ++index;
        }

        return min;
    }
};


// Solution 2
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int N=24*60 , H = 12*60;
        int minX = N, maxX = 0;
        bitset<N> seen=0;
        for(string& s:timePoints) {
            int x = ((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
            if(seen[x]) return 0;
            seen[x]=1;
            minX=min(x, minX);
            maxX=max(x, maxX);
        }

        int diff = N, prev = minX;
        for(int x=minX+1; x<=maxX; x++){
            if (!seen[x]) continue;
            diff=min(diff, x-prev);
            prev=x;
        }
        diff=min(N-(maxX-minX), diff);
        return diff;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
