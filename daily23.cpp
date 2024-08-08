// Solution 1
class Solution {
public:
    int minOperations(vector<string>& logs) {
        auto folders = std::stack<std::string>{};
        for (auto move : logs) {
            if (move == "../") {
                if (!folders.empty())
                    folders.pop();
                continue;
            }

            if (move == "./")
                continue;
            
            folders.push(move);
        }

        return folders.size();
    }
};


// Solution 2
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (logs[i] == "../") {
               if(n > 0) n--;
               continue;
            }

            if (logs[i] == "./")
                continue;

            n++;
        }

        if(n < 0) 
            return 0;
        return n;
    }
};
