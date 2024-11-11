// Solution 1 - FAIL
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        /*
        start from right
        if number to the left is greater, reduce until smaller
            if reductions cause a negative number, return false

        return true
        */

        for (int i = nums.size() - 1; i > 0; --i) {
            std::cout << "curr: " << nums[i] << ", left: " << nums[i - 1] << std::endl;
            auto n = nums[i - 1];
            int prev = 0;
            int res = nums[i - 1];
            
            while (res >= nums[i]) {
                std::cout << n << std::endl;
                if (n == prev)
                    return false;

                prev = n;
                n = nearestLowerPrime(n);
                res = nums[i - 1] - n;
            }
            std::cout << n << std::endl;
            std::cout << "exited\n";

            nums[i - 1] = res;
        }

        return true;
    }

private:
    // Helper function to check if a number is prime
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;

        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }

    // Function to find the nearest prime less than n
    int nearestLowerPrime(int n) {
        // Start from n - 1 and check downwards
        for (int i = n - 1; i > 1; --i) {
            if (isPrime(i)) return i;
        }
        return -1; // In case there's no prime (edge case for very small values of n)
    }
};


// Solution 2
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int maxElement = getMaxElement(nums);
        
        // Create Sieve of Eratosthenes array to identify prime numbers
        vector<bool> sieve(maxElement + 1, true);
        sieve[1] = false;
        for (int i = 2; i <= sqrt(maxElement + 1); i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= maxElement; j += i) {
                    sieve[j] = false;
                }
            }
        }
        
        // Check if array can be made strictly increasing by subtracting prime numbers
        int currValue = 1;
        int i = 0;
        while (i < nums.size()) {
            int difference = nums[i] - currValue;
            
            // Return false if current number is already smaller than required value
            if (difference < 0) {
                return false;
            }
            
            // Move to next number if difference is prime or zero
            if (sieve[difference] == true || difference == 0) {
                i++;
                currValue++;
            } else {
                currValue++;
            }
        }
        return true;
    }
    
private:
    // Helper method to find maximum element in array
    int getMaxElement(vector<int>& nums) {
        int max = -1;
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
};

