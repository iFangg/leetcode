// Solution 1
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    const rangeArray = [];
    if (nums.length === 1) {
        rangeArray.push(`${nums[0]}`);
        return rangeArray;
    }

    let start;
    let prev;
    for (let num of nums) {
        if (start == null) {
            start = num;
            prev = start;
            continue;
        }

        if (num - prev > 1) {
            let range = `${start}->${prev}`;
            if (start === prev) range = `${start}`;
            rangeArray.push(range);
            start = num;
        }

        prev = num;
        if (nums.indexOf(prev) === nums.length - 1) {
            let range = `${start}->${prev}`;
            if (start === prev) range = `${start}`;
            rangeArray.push(range);
        }
    }

    return rangeArray;
};

// Solution 2
