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

// Solution 2 - refactored sol'n 1
var summaryRanges = function(nums) {
    const rangeArray = [];

    for (let i = 0; i < nums.length; i++) {
        let start = nums[i];
        while (i + 1 < nums.length && nums[i + 1] - nums[i] === 1) {
            i++;
        }
        let end = nums[i];
        let range = start === end ? `${start}` : `${start}->${end}`;
        rangeArray.push(range);
    }

    return rangeArray;
};

// Solution 3 - better memory usage sol'n (allegedly)
var summaryRanges = function(nums) {
    if(nums.length === 0) return []
    const results = []    
    let i = 1
    let start = nums[0]
    for(; i < nums.length; i++ ) {
        if(nums[i] !== (nums[i-1]+1)) {
            pushData(results, start, nums[i-1])            
            start = nums[i]
        }
    }

    pushData(results, start, nums[i-1])            
    return results
};

const pushData = (results, start, end) => {        
    if(start === end) results.push(`${start}`)
    else results.push(`${start}->${end}`)                    
}
