// Solution 1
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // have visited matrix
        // go right until u can't then down, then left, then up
        auto visited = std::vector<std::vector<int>>{};
        auto path = std::vector<int>{};
        auto curr_dir = std::make_pair(0, 1);
        auto pos = std::make_pair(0, 0);

        auto num_values = matrix.size() * matrix[0].size();
        auto r_limit = std::pair<int, int>{matrix.size(), 0};
        auto c_limit = std::pair<int, int>{matrix[0].size(), 0};
        
        while (path.size() != num_values) {
            auto delta_r = pos.first + curr_dir.first;
            auto delta_c = pos.second + curr_dir.second;
            path.push_back(matrix[pos.first][pos.second]);
            // std::cout << "curr pos is " << pos.first << " - " << pos.second << std::endl;
            // std::cout << "changes in pos are " << delta_r << " - " << delta_c << std::endl;

            if (delta_c >= c_limit.first) {
                // std::cout << "c too b\n";
                r_limit.second++;
                curr_dir.first = 1;
                curr_dir.second = 0;
                pos.first++;
            } else if (delta_c < c_limit.second) {
                // std::cout << "c too s\n";
                r_limit.first--;
                curr_dir.first = -1;
                curr_dir.second = 0;
                pos.first--;
            } else if (delta_r >= r_limit.first) {
                // std::cout << "r too b\n";
                c_limit.first--;
                curr_dir.first = 0;
                curr_dir.second = -1;
                pos.second--;
            } else if (delta_r < r_limit.second) {
                // std::cout << "r too s\n";
                c_limit.second++;
                curr_dir.first = 0;
                curr_dir.second = 1;
                pos.second++;
            } else {
                pos.first = delta_r;
                pos.second = delta_c;
            }
        }

        return path;
    }
};


// Solution 2
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int total = row*col;
        
        //index initialisation
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;
        
        
        while(count < total) {
            
            //print starting row
            for(int index = startingCol; count < total && index<=endingCol; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int index = startingRow; count < total && index<=endingRow; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int index = endingCol; count < total && index>=startingCol; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int index = endingRow; count < total && index>=startingRow; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        } 
        return ans;

    }
};
