// Solution 1
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n)
            return {};
        auto arr = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        auto r = 0;
        auto c = 0;

        for (auto& elem : original) {
            arr[r][c] = elem;
            
            if (c + 1 >= n) {
                c = 0;
                r++;
            } else {
                c++;
            }
        }

        return arr;
    }
};


// Solution 2
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
         ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        if(m*n!=original.size()){
            return {};
        }
        vector<vector<int>>ans(m,vector<int>(n,0));
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[k++];
               
            }
        }
        return ans;
    }
};
