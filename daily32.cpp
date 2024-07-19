// Solution 1
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        auto row_mins = std::unordered_map<int, int>{};
        auto col_mins = std::unordered_map<int, int>{};

        for (std::size_t i = 0; i < matrix.size(); ++i) {
            for (std::size_t j = 0; j < matrix[i].size(); ++j) {
                if (!row_mins.contains(i))
                    row_mins[i] = matrix[i][j];
                else
                    row_mins[i] = std::min(row_mins[i], matrix[i][j]);
                
                if (!col_mins.contains(j))
                    col_mins[j] = matrix[i][j];
                else
                    col_mins[j] = std::max(col_mins[j], matrix[i][j]);
            }
        }

        auto row_min_values = std::unordered_set<int>{};
        for (auto& [r, v] : row_mins) {
            row_min_values.insert(v);
        }

        auto numbers = std::vector<int>{};
        for (auto& [c, v] : col_mins) {
            if (row_min_values.contains(v))
                numbers.push_back(v);
        }

        return numbers;
    }
};


// Solution 2 - time efficient
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& m) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 0;i < m.size();i++){
            int mn = INT_MAX;
            for(int j = 0;j < m[0].size();j++){
                mn = min(mn, m[i][j]);
            }
            mp[mn]++;
        }
        for(int i = 0;i < m[0].size();i++){
            int mx = 0;
            for(int j = 0;j < m.size();j++){
                mx = max(mx, m[j][i]);
            }
            if(mp.count(mx))ans.push_back(mx);
        }

        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Solution 3 - space efficient
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> result;
        for(int i=0 ; i<mat.size() ; i++)
        {
            for(int j=0 ; j<mat[0].size() ; j++)
            {
                bool flag=true;
                for(int k=0 ; k<mat[0].size() ; k++)
                {
                    if(j==k)
                        continue;
                    if(mat[i][j]>mat[i][k])
                    {
                         flag=false;
                         break;
                    }   
                }
                if(!flag)
                    continue;
                
                for(int k=0 ; k<mat.size() ; k++)
                {
                    if(i==k)
                        continue;
                    
                    else if(mat[i][j]<mat[k][j])
                    {
                         flag=false;
                         break;
                    }   
                }

                if(flag)
                    result.push_back(mat[i][j]);
            }
        }
        return result;
    }
};
