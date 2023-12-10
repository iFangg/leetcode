// Solution 1
/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    const steps = [1,2];
    function stairsCombos(combos, currSum, sumArray) {
        for (let i = 0; i < steps.length; i++) {
            currSum += steps[i];
            if (combos.includes(sumArray)) break;
            sumArray.push(steps[i]);
            console.log(sumArray)
            if (currSum === n) {
                combos.push(sumArray);
                currSum = 0;
                sumArray = [];
            }
            else if (currSum > n) break;
            else stairsCombos(combos, currSum, sumArray);
        }
        // console.log(combos);
        return combos;
    };

    const combos = stairsCombos([], 0, []);
    return combos.length;
};

// Solution 2
var climbStairs = function(n) {
    const memo = new Map(); // Memoization table

    function countWaysToReach(currStep) {
        if (currStep === n) return 1; // Reached the top, one valid way
        if (currStep > n) return 0; // Went beyond the top, not a valid way

        if (memo.has(currStep)) return memo.get(currStep);

        let totalWays = 0;

        for (let i = 1; i <= 2; i++) {
            totalWays += countWaysToReach(currStep + i);
        }

        memo.set(currStep, totalWays);
        return totalWays;
    }

    return countWaysToReach(0);
};

// Solution 3
var climbStairs = function(n) {
    if (n <= 2) {
        return n
    }
    
    const arr = [1, 2];
    for (let i = 2; i < n; i++) {
        const sum = arr[i - 1] + arr[i - 2];
        arr.push(sum);
    }

    return arr[arr.length - 1]; 
};

// Solution 4 - doesn't use memoization
var climbStairs = function(n) {
    
    if (n < 2) return 1;
    
    let firstStep = 1;    
    let secondStep = 1;    
    let thirdStep = 0;
    
    for (let i = 2; i <= n; i++) {
        thirdStep = firstStep + secondStep;
        firstStep = secondStep;
        secondStep = thirdStep;
    }

    return thirdStep;
};
