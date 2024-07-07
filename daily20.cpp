// Solution 1
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // keep track of how many full bottles there still are
        // starting with x bottles
        // empty all remaining bottles
        auto full = numBottles;
        auto empty = 0;
        auto bottles = 0;
        while (full + empty >= numExchange) {
            bottles += full;
            empty += full;
            full = empty / numExchange;
            empty = empty % numExchange;
            // std::cout << "next round (full - empty): " << full << " - " << empty << std::endl;
        }

        return bottles + full;
    }
};


// Solution 2
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles;
        int x=numBottles;
        while(true){
            int y=x/numExchange;
            int z=x%numExchange;
            sum+=y;
            x=y+z;
            if(x<numExchange){
                break;
            }
        }
        return sum;
    }
};
