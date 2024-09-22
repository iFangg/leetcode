// Solution 1 - FAIL
class Solution {
public:
    int findKthNumber(int n, int k) {
        auto count = 1;
        long long currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            if (count == k)
                return static_cast<int>(currentNumber);
            
            ++count;

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return n;
    }
};


// Solution 2
class Solution {
private:
    int getReqNum(long a,long b,long &n){
        int gap=0; 
        while(a <= n){
            gap += min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
public:
    int findKthNumber(long n, int k) {
        long num = 1;
        for(int i=1; i<k;){
            int req = getReqNum(num,num+1,n);
            if(i+req <= k){
                i+=req;
                num++;
            }else{
                i++;
                num *= 10;
            }
        }
        return num;
    }
};
