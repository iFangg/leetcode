// Solution 1 - TOO SLOW
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const anagramsArr = []
    const visited = []
    function isAnagram(str1, str2) {
        let map = new Array(256).fill(0);
        for (let i = 0; i < str1.length; i++) {
            map[str1.charCodeAt(i)]++;
        }

        for (let i = 0; i < str2.length; i++) {
            map[str2.charCodeAt(i)]--;
        }
        return map.every(value => value === 0);
    }

    for (let i = 0; i  < strs.length; i++) {
        if (visited.includes(strs[i])) continue;
        const str = strs[i]
        const anagrams = [str];
        for (let j = i + 1; j < strs.length; j++) {
            let str2 = strs[j];
            if (isAnagram(str, str2)) {
                anagrams.push(str2);
                visited.push(str2);
            }
        }

        anagramsArr.push(anagrams);
    }

    return anagramsArr;
};

// Solution 2
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const anagramsMap = new Map();

    for (let str of strs) {
        const sortedStr = str.split('').sort().join('');
        if (!anagramsMap.has(sortedStr)) {
            anagramsMap.set(sortedStr, []);
        }
        anagramsMap.get(sortedStr).push(str);
    }

    return Array.from(anagramsMap.values());
};


// Solution 3
var groupAnagrams = function(strs) {
    const primes = [2,3,5,7,11,13,17,19,23,29,31,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103];
    const map = new Map()
    for(let i=0; i<strs.length; i++){
        let h = 1; for (let j=0; j<strs[i].length; j++) h *= primes[ strs[i][j].charCodeAt(0)-97 ]
        const arr = map.get(h)
        if(arr) arr.push(strs[i]); else map.set(h, [strs[i]])
    }
    return [...map.values()]
};
