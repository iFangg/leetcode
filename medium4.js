// Solution 1 - dervied from https://gist.github.com/tpae/72e1c54471e88b689f85ad2b3940a8f0
function TrieNode(key) {
    this.key = key;
    this.parent = null;
    this.children = {};
    this.end = false;
}

var Trie = function() {
    this.root = new TrieNode(null);
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    var node = this.root;

    for (let i = 0; i < word.length; i++) {
        if (!node.children[word[i]]) {
            node.children[word[i]] = new TrieNode(word[i]);
            node.children[word[i]].parent = node;
        }

        node = node.children[word[i]];

        if (i == word.length - 1) node.end = true;
    }
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    var node = this.root;
    for (let i = 0; i < word.length; i++) {
        if (node.children[word[i]]) {
            node = node.children[word[i]];
        } else {
            return false;
        }
    }

    return node.end;
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    var node = this.root;
    for (let i = 0; i < prefix.length; i++) {
        if (!node.children[prefix[i]]) return false;
        node = node.children[prefix[i]];
    }

    return true;
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */


// Solution 2
// nested dictionaries
var Trie = function() {
    this.root = {}
};

/** 
 * @param {string} word
 * @return {void}
 */
Trie.prototype.insert = function(word) {
    let node = this.root

    for (let char of word) {
        if (!node[char]) {
            node[char] = {}
        }

        node = node[char]
    }

    node.isWord = true
};

/** 
 * @param {string} word
 * @return {boolean}
 */
Trie.prototype.search = function(word) {
    let node = this.root

    for (let char of word) {
        if (!node[char]) {
            return false
        }

        node = node[char]
    }

    return node.isWord === true
};

/** 
 * @param {string} prefix
 * @return {boolean}
 */
Trie.prototype.startsWith = function(prefix) {
    let node = this.root

    for (let char of prefix) {
        if (!node[char]) {
            return false
        }

        node = node[char]
    }

    return true
};

/** 
 * Your Trie object will be instantiated and called as such:
 * var obj = new Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */
