// Solution 1
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int total = 0;
        for (auto& p : details) {
            auto pos = std::size_t{};
            total += std::stoi(p.substr(11,2), &pos) > 60 ? 1 : 0;
        }

        return total;
    }
};


// Solution 2
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(int i=0;i<details.size();i++)
        {
            int age=( (details[i][11]-'0')*10 )+(details[i][12]-'0');
            ans+=(age>60);
        }
        return ans;
    }
};
