// Solution 1 - too slow
class Solution {
public:
    bool possible_collisions(const std::vector<std::vector<int>>& robots) {
        int left = 0, right = robots.size() - 1;
        while (left < right) {
            if (robots[left][1] <= 0)
                left++;
            if (robots[right][1] <= 0)
                right--;
            int left_dir = robots[left][2];
            int right_dir = robots[right][2];
            if (left_dir == -1)
                left++;
            if (right_dir == 1)
                right--;
            
            if (left_dir < right_dir)
                return true;
        }
        return false;
    }

    void move_robots(std::vector<std::vector<int>>& robots, std::vector<int>& healths) {
        // move robot and update all robots in same position
        for (auto i = 0; i < robots.size(); ++i) {
            if (robots[i][1] <= 0)
                continue;
            auto& curr_pos = robots[i][0];
            auto new_pos = curr_pos + robots[i][2];
            if (new_pos < 1)
                new_pos = 1;
            robots[i][0] = new_pos;
            for (auto j = 0; j < robots.size(); ++j) {
                if (j == i)
                    continue;
                if (robots[j][1] <= 0)
                    continue;
                if (robots[j][0] != new_pos)
                    continue;
                if (robots[j][2] == robots[i][2])
                    continue;
                
                auto& curr_hp = robots[i][2];
                auto& other_hp = robots[j][2];
                if (curr_hp > other_hp) {
                    healths[i]--;
                    robots[i][1]--;
                    healths[j] = 0;
                } else if (curr_hp < other_hp) {
                    healths[j]--;
                    robots[j][1]--;
                    healths[i] = 0;
                } else {
                    healths[i] == 0;
                    healths[j] == 0;
                    break;
                }
            }
        }
    }

    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        auto direction_set = std::unordered_set<char>{directions.begin(), directions.end()};
        if (direction_set.size() == 1)
            return healths;

        std::vector<std::vector<int>> robots;
        for (size_t i = 0; i < positions.size(); ++i) {
            int dir = (directions[i] == 'L') ? -1 : 1;
            robots.emplace_back(std::vector<int>{positions[i], healths[i], dir});
        }

        while (possible_collisions(robots)) {
            move_robots(robots, healths);
        }

        healths.erase(std::remove_if(healths.begin(), healths.end(), [](int h) { return h <= 0; }), healths.end());
        return healths;
    }
};


// Solution 2
class Solution {
public:
    std::vector<int> survivedRobotsHealths(std::vector<int>& positions, std::vector<int>& healths, std::string directions) {
        int n = positions.size();
        std::vector<int> indices(n);
        for (int i = 0; i < n; ++i) indices[i] = i;
        // sort robots based on positions (e.g example 1: robot 5 will be first because it's at pos 1)
        std::sort(indices.begin(), indices.end(), [&](int a, int b) { return positions[a] < positions[b]; });

        std::stack<int> st;
        for (int i : indices) {
            // if robot is moving to the right, add it to the stack
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // if the robot is moving to the left, compare to all robots that will collide with it
                while (!st.empty() && healths[st.top()] > 0) {
                    // modify healths vector in place
                    if (healths[st.top()] > healths[i]) {
                        healths[st.top()]--;
                        healths[i] = 0;
                        break;
                    } else if (healths[st.top()] < healths[i]) {
                        healths[i]--;
                        healths[st.top()] = 0;
                        st.pop();
                    } else {
                        healths[i] = 0;
                        healths[st.top()] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }

        std::vector<int> survivors;
        for (int h : healths) {
            if (h > 0) survivors.push_back(h);
        }
        return survivors;
    }
};


