// Solution 1
function maxProfit(prices: number[]): number {
    if (prices.length < 2) {
        return 0;
    }

    let max = 0;
    let minPrice = prices[0];

    for (let i = 1; i < prices.length; i++) {
        let profit = prices[i] - minPrice;
        max = Math.max(max, profit);
        minPrice = Math.min(minPrice, prices[i]);
    }

    return max;
}


// Solution 2
function maxProfit(prices: number[]): number {
    let buy = prices[0];
    let maxProfit = 0;
    let i = 1;

    while (i < prices.length) {
        if (prices[i] < buy) {
            buy = prices[i];
        } else {
            maxProfit = Math.max(prices[i] - buy, maxProfit);
        }

        i++;
    }

    return maxProfit;
};
