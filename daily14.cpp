// Solution 1
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        // need 1, 2 and 3 to be odd
        // if 1 is even, shift up by 1
        // if 2 is even, shift up by 2
        // if 3 is even, shift up by 3
        if (arr.size() <= 2) return false;
        auto head = int{0};
        while (head + 2 < arr.size()) {
            if (arr[head] % 2 == 0) {
                ++head;
            } else if (arr[head + 1] % 2 == 0) {
                head += 2;
            } else if (arr[head + 2] % 2 == 0) {
                head += 3;
            }

            else
                return true;
        }

        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


// Solution 2
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()==1||arr.size()==2)
        return false;
        for(int i=0;i<arr.size()-2;i++)
        {
            if(arr[i]%2!=0)
            {
                if(arr[i+1]%2 !=0 && arr[i+2]%2 !=0)
                {
                   return true;
                }
            }

        }
      return false;  
    }
};
