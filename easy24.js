// Solution 1
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    if (s.length <= 1) return true;
    let replacements = {};
    for (let i = 0; i < s.length; i++) {
        if (s[i] in replacements && t[i] !== replacements[s[i]]) return false;
        if (!(s[i] in replacements) && Object.values(replacements).includes(t[i])) return false;
        else replacements[s[i]] = t[i];
    }

    return true;
};


// Solution 2
const isIsomorphic = (s, t) => {
  const sMap = new Map();
  const tMap = new Map();
  let newS = "";

  for (let i = 0; i < s.length; i++) {
    const sChar = s[i];
    const tChar = t[i];

    if (sMap.has(sChar)) {
      newS += sMap.get(sChar);
    } else {
      if (tMap.has(tChar)) {
        return false;
      }

      sMap.set(sChar, tChar);
      tMap.set(tChar, sChar);
      newS += tChar;
    }
  }

  return newS === t;
};
