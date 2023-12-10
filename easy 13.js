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
