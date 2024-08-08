// Solution 1
class Solution {
public:
    string numberToWords(int num) {
        // start from 1st digit and work your way up to 10th, 100th, 1000th .. etc
        // use stack to track current digit
        // for every 10th (ie 11, 11010, 11000200 - 2nd, 5th, 8th, 11th)
            // pop off the previous (if needed) to add 10s value (e.g 11 - pop off one and add 11, 21, just add 20 instead of popping off)
        if (num == 0)
            return "Zero";

        // Could optimise for the tens? (+ "teen" onto strings instead of having mapped value)
        auto nums = std::unordered_map<int, std::string>{
            {0, "Zero"},
            {1, "One"},
            {10, "Ten"},
            {11, "Eleven"},
            {12, "Twelve"},
            {13, "Thirteen"},
            {14, "Fourteen"},
            {15, "Fifteen"},
            {16, "Sixteen"},
            {17, "Seventeen"},
            {18, "Eighteen"},
            {19, "Nineteen"},
            {2, "Two"},
            {20, "Twenty"},
            {3, "Three"},
            {30, "Thirty"},
            {4, "Four"},
            {40, "Forty"},
            {5, "Five"},
            {50, "Fifty"},
            {6, "Six"},
            {60, "Sixty"},
            {7, "Seven"},
            {70, "Seventy"},
            {8, "Eight"},
            {80, "Eighty"},
            {9, "Nine"},
            {90, "Ninety"}
        };
            
        auto tens = std::unordered_map<long, std::string>{
            {100, "Hundred"},
            {1000, "Thousand"},
            {1000000, "Million"},
            {1000000000, "Billion"},
        };

        auto number_stack = std::stack<std::string>{};
        auto num_str = std::to_string(num);
        auto len = static_cast<int>(num_str.size() - 1);
        auto tenths = long{1};
        // for every 1000th position, u must reposition the exponent (10th power)
        // scan every 3 numbers, increment thousands
        while (len >= 0) {
            auto curr_tenths = 1;
            auto curr_stack = std::stack<std::string>{};
            for (auto i = len; i > len - 3 and i >= 0; --i) {
                auto digit = num_str[i] - '0';
                auto num = nums[digit];

                if (curr_tenths == 10) {
                    if (!curr_stack.empty() and digit != 0)
                        curr_stack.pop();
                    if (digit == 1) {
                        num = nums[digit * 10 + num_str[i + 1] - '0'] + " ";
                    } else {
                        num = nums[digit * 10] + " " + nums[num_str[i + 1] - '0'];
                        if (num_str[i + 1] - '0' == 0)
                            num = nums[digit * 10] + " ";
                    }

                } else if (curr_tenths == 100) {
                    if (digit != 0)
                        num += " " + tens[curr_tenths];
                }

                if (digit != 0) {
                    curr_stack.push(num);
                }

                curr_tenths *= 10;
            }

            auto curr_num = std::string{};
            while (!curr_stack.empty()) {
                auto n = curr_stack.top();
                curr_stack.pop();

                if (!curr_num.empty())
                    curr_num += " ";
                curr_num += n;
            }

            int last = curr_num.size() - 1;
            while (last >= 0 && curr_num[last] == ' ')
                --last;
            curr_num = curr_num.substr(0, last + 1);

            if (tenths >= 1000 and !curr_num.empty()) {
                curr_num += " " + tens[tenths];
            }

            if (!curr_num.empty())
                number_stack.push(curr_num);

            tenths *= 1000;
            len -= 3;
        }

        auto result = std::string{""};
        while (!number_stack.empty()) {
            auto n = number_stack.top();
            number_stack.pop();

            if (!result.empty())
                result += " ";
            result += n;
        }

        int last = result.size() - 1;
        while (last >= 0 && result[last] == ' ')
            --last;
        return result.substr(0, last + 1);
    }
};


// Solution 2
class Solution {
public:
    vector<string> belowTen = {"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> belowTwenty = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> belowHundred = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string numberToWords(int num) {
        if(num == 0)
           return "Zero";
        return find(num);
    }

    string find(int num)
    {
        string result = "";
        if(num < 10)
            result = belowTen[num];
        else
            if(num < 20)
                result = belowTwenty[num - 10];
        else
            if(num < 100)
                result = belowHundred[num / 10] + " " + find(num % 10);
        else
            if(num < 1000)
                result = find(num / 100) + " Hundred " + find(num % 100);
        else
            if(num < 1000000)
                result = find(num / 1000) + " Thousand " + find(num % 1000);
        else
            if(num < 1 000000000)
                result = find(num / 1000000) + " Million " + find(num % 1000000);
        else
            result = find(num / 1000000000) + " Billion " + find(num % 1000000000);
        int size = result.length();
        if(size > 0 && result[size - 1] == ' ')
            result = result.substr(0, size - 1);
        return result;
    }
};


