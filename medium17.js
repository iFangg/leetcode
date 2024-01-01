// Solution 1 - Too slow
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (prices.length <= 1) return 0;

    let max = 0;
    function next(start) {
        if (prices.length - 1 - start <= 1) return 0;

        let max = 0;
        let sell = prices[start];
        // console.log(`min ${sell}`)
        for (let i = start + 1; i < prices.length; i++) {
            let profit = prices[i] - sell;
            max = Math.max(max, profit + next(i + 1));
            sell = Math.min(sell, prices[i])
            // console.log(max);
        }

        return max;
    }

    max = next(0);

    return max;
};

// Solution 2
var maxProfit = function(prices) {
    if (prices.length <= 1) return 0;

    let max = 0;

    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            // If the current price is greater than the previous one, we can make a profit
            max += prices[i] - prices[i - 1];
        }
    }

    return max;
};
