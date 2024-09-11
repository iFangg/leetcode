#include <vector>
#include <unordered_map>


// Solution 1
class Solution {
public:
    int robotSim(std::vector<int>& commands, std::vector<std::vector<int>>& obstacles) {
        /*
        keep track of current position
        keep track of obstacles per row and col (from current coord)
            have n^2 matrices for amount of obstacles from this point
            NO
            have cumulative sum nxn matrix for obstacles in each row and col starting from 0,0 and going to nth row/col
        
        keep track of seen obstacles
        move as per command
        if obstacle exists in this current row (if going forawrds/backwards) or col (if going left/right)
        */

        pos_ = std::make_pair(0, 0);
        obst_ = std::unordered_map<int, std::vector<int>>{};

        for (auto& o : obstacles) {
            if (!obst_.contains(o[0]))
                obst_[o[0]] = std::vector<int>{};
            
            if (!obst_.contains(o[1]))
                obst_[o[1]] = std::vector<int>{};
            
            obst_[o[0]].push_back(o[1]);
            obst_[o[1]].push_back(o[0]);
        }

        auto dir = std::make_pair(1, 0);
        auto delta_x = std::unordered_map<int, int>{
            {1, 0},
            {0, -1},
            {-1, 0},
            {0, 1}
        };
        auto delta_y = std::unordered_map<int, int>{
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0}
        };

        for (auto& c : commands) {
            if (c == -2) {
                dir.first = delta_x[dir.first];
                dir.second = delta_y[dir.second];
            } else if (c == -1) {
                dir.first = delta_x[dir.first];
                dir.second = -delta_y[dir.second];
            } else {
                // yes obstacle
                if (obst_[pos_.first].size() > 0 and dir.first) {
                    return;
                } else if (obst_[pos_.second].size() > 0 and dir.second) {
                    return;
                } else {
                // no obstacle
                    if (!dir.first)
                        pos_.second += c;
                    else
                        pos_.first += c;
                }
            }
        }

        return static_cast<int>(std::pow(pos_.first, 2) + std::pow(pos_.second, 2));
    }

private:
    std::pair<int, int> pos_;
    std::unordered_map<int, std::vector<int>> obst_;
};


// Solution 2
class Solution {
public:
    static int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> XobSet, YobSet;
        XobSet.reserve(10000), YobSet.reserve(10000);
        for(auto& ob: obstacles){
            int x=ob[0], y=ob[1];
            XobSet[x].insert(y);
            YobSet[y].insert(x);
        }

        const int dir[4][2]={{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int x=0, y=0, dx=0, dy=1, face=0, maxD2=0;
        for(int c: commands){
            switch(c){
                case -2: face=(face+1)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                case -1: face=(face+3)%4; dx=dir[face][0]; dy=dir[face][1]; break;
                default:
                //    cout<<"\nc="<<c<<" face="<<face<<":";
                    switch(face){
                        case 0: {//up
                            auto it=upper_bound(XobSet[x].begin(), XobSet[x].end(), y);
                            if (it!=XobSet[x].end() && *it<=y+c) y=*it-1;
                            else y+=c;
                            break;
                        }
                        case 1: {//left
                            auto it=upper_bound(YobSet[y].rbegin(), YobSet[y].rend(), x, greater<>());
                            if (it!=YobSet[y].rend() && *it>=x-c) x=*it+1;
                            else x-=c;
                            break;
                        }
                        case 2: {//down
                            auto it=upper_bound(XobSet[x].rbegin(), XobSet[x].rend(), y, greater<>());
                            if (it!=XobSet[x].rend() && *it>=y-c) y=*it+1;
                            else y-=c;
                            break;
                        }
                        case 3: {//right
                            auto it=upper_bound(YobSet[y].begin(), YobSet[y].end(), x);
                            if (it!=YobSet[y].end() && *it<=x+c) x=*it-1;
                            else x+=c;
                            break;
                        }
                    }
                //    cout<<"("<<x<<","<<y<<"),";
                    maxD2=max(maxD2, x*x+y*y);
                }
        }
        return maxD2;
    }
};
