// Solution 1 - FAIL
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        /*
        indices array, sort based off arrival time
        iterate thru sorted array until we reach target, return current chair
            increment chair
        have var for chairs occupied
            save exit times in a max heap, pop earliest departure once a start time <= earliest exit.
                each pop = decrement chair then add current person and increment chair (chair num stays the same)
                each save = incrememnt chair
        */

        auto indices = std::vector<int>(times.size());

        for (auto i = 0; i < times.size(); ++i) {
            indices[i] = i;
        }

        std::sort(indices.begin(), indices.end(), [&times](int a, int b) {
            return times[a][0] < times[b][0];
        });

        auto curr_chair = 0;
        auto exit_times = std::priority_queue<int, std::vector<int>, std::greater<int>>{};
        for (auto i : indices) {
            // std::cout << "current arrival: " << times[i][0] << std::endl;
            if (i == targetFriend)
                return curr_chair;

            exit_times.push(times[i][1]);
            // std::cout << "earliest departure: " << exit_times.top() << std::endl;

            while (!exit_times.empty() and exit_times.top() <= times[i][0]) {
                exit_times.pop();
                if (curr_chair >= 0)
                    curr_chair--;
            }
          
            curr_chair++;
        }

        return curr_chair;
    }
};


// Solution 2
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupied;
        priority_queue<int, vector<int>, greater<>> available;
        
        for (int i = 0; i < n; i++) {
            available.push(i);
        }
        
        for (int idx : indices) {
            long long arrival = times[idx][0];
            long long departure = times[idx][1];
            
            while (!occupied.empty() && occupied.top().first <= arrival) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            
            int chair = available.top();
            available.pop();
            
            if (idx == targetFriend) {
                return chair;
            }
            
            occupied.push({departure, chair});
        }
        
        return -1; // This line should never be reached if the input is valid
    }
};

