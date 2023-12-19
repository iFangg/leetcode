// Solution 1
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const map = {
        'I': 1,
        'IV': 4,
        'V': 5,
        'IX': 9,
        'X': 10,
        'XL': 40,
        'L': 50,
        'XC': 90,
        'C': 100,
        'CD': 400,
        'D': 500,
        'CM': 900,
        'M': 1000,
    }

    let count = 0;
    for (let i = 0; i < s.length; i++) {
        let num = map[s[i]];
        if (i + 1 < s.length && map.hasOwnProperty(s[i] + s[i + 1])) {
            num = map[s[i] + s[i + 1]];
            i++;
        }

        count += num;
    }

    return count;
};


// Solution 2
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    let res = 0
    s = s.split('')

    for(let i = 0; i < s.length; i++){
        switch(s[i]){
            case 'I':
                ['V','X'].includes(s[i+1]) ? res += -1 : res += 1
            break
            case 'X':
                ['L','C'].includes(s[i+1]) ? res += -10 : res += 10
            break
            case 'C':
                ['D','M'].includes(s[i+1]) ? res += -100 : res += 100
            break
            case 'V':
                res+=5
            break
            case 'L':
                res += 50
            break
            case 'D':
                res += 500
            break
            case 'M':
                res += 1000
            break
        }
    }
    return res
};


// Solution 3
var romanToInt = function (s) {
  const romanValue = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };
  let result = 0;
  for (let i = 0; i < s.length; i++) {
    const curValue = romanValue[s[i]];
    const nextValue = romanValue[s[i + 1]];
    if (curValue < nextValue) {
      result += nextValue - curValue;
      i++;
    } else result += curValue;
  }
  return result;
};
