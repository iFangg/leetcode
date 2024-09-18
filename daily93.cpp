// Solution 1.1 - FAIL
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /*
        sort the vector by leftmost number, if leftmost numbers are equal, view next number to the right
        */

        auto num_strs = std::vector<std::string>(nums.size());

        for (auto i = 0; i < nums.size(); ++i) {
            num_strs[i] = std::to_string(nums[i]);
        }

        std::sort(num_strs.begin(), num_strs.end(), [](std::string a, std::string b) {
            auto l = std::stoll(a + b);
            auto r = std::stoll(b + a);

            return l > r;
        });

        if (num_strs[0] == "0") return "0";

        auto num = std::string{};
        for (auto& n : num_strs) {
            num += n;
        }

        return num;
    }
};


// Solution 1.2
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /*
        sort the vector by leftmost number, if leftmost numbers are equal, view next number to the right
        */

        auto num_strs = std::vector<std::string>(nums.size());

        for (auto i = 0; i < nums.size(); ++i) {
            num_strs[i] = std::to_string(nums[i]);
        }

        std::sort(num_strs.begin(), num_strs.end(), [](std::string a, std::string b) {
            return a + b > b + a;
        });

        if (num_strs[0] == "0") return "0";

        auto num = std::string{};
        for (auto& n : num_strs) {
            num += n;
        }

        return num;
    }
};

