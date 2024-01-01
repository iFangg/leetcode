// Solution 1
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if (prices.length < 2) return 0;

    let max = 0;
    let minPrice = prices[0];

    for (let i = 1; i < prices.length; i++) {
        let profit = prices[i] - minPrice;
        max = Math.max(max, profit);
        minPrice = Math.min(minPrice, prices[i]);
    }

    return max;
};
