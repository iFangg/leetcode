// Solution 1
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    const length = digits.length;
    if (length === 0) return [];

// Define the mapping of digits to letters
    const digitMap = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    };
    if (length === 1) return digitMap[digits].split('');

    // Helper function to generate combinations
    const generateCombinations = (index, currentCombination) => {
        if (index === digits.length) {
            result.push(currentCombination);
            return;
        }

        const currentDigit = digits[index];
        const letters = digitMap[currentDigit];

        for (const letter of letters) {
            generateCombinations(index + 1, currentCombination + letter);
        }
    };

    const result = [];
    generateCombinations(0, '');

    return result;
};
