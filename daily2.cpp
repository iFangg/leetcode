// Solution 1 - 17/6/24
class Solution {
public:
    bool judgeSquareSum(int c) {
        if (c <= 2) return true;
        if (c == 3) return false;
        auto square = std::unordered_set<long>{};
        for (auto i = long{0}; i <= c; ++i) {
            auto sq_num = pow(i, 2);
            if (sq_num > c) break;
            if (sq_num <= c) square.insert(sq_num);
        }

        for (auto n = square.begin(); n != square.end(); ++n) {
            // std::cout << *n << "\n";
            auto diff = c - *n;
            if (diff * 2 == c) return true;
            if (square.contains(diff)) return true;
        }

        return false;
    }
};


// Solution 2
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long a=0, b=pow(c, 0.5);

        while(a<=b){
            if(a*a+b*b==(long long)c)return true;
            else if(a*a+b*b>(long long)c)b--;
            else a++;
        }
        
        return false;
    }
};
