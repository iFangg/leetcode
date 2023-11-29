// Solution 1
/**
 * // Definition for a Node.
 * function Node(val, neighbors) {
 *    this.val = val === undefined ? 0 : val;
 *    this.neighbors = neighbors === undefined ? [] : neighbors;
 * };
 */

/**
 * @param {Node} node
 * @return {Node}
 */
var cloneGraph = function(node) {
    if (node === null) return node;
    const visited = new Map();
    return traverseGraph(node, visited);
};

function traverseGraph(node, visited) {
    if (visited.has(node)) {
        return visited.get(node);
    }

    const nodeClone = new Node(node.val, []);
    visited.set(node, nodeClone);

    for (const neigh of node.neighbors) {
        const neighClone = traverseGraph(neigh, visited);
        nodeClone.neighbors.push(neighClone);
    }

    return nodeClone;
}

// Solution 2
var cloneGraph = function(node) {

     if(!node) return node;

     let visited = {};
     function dfs(node) {
        if(node.val in visited)
            return visited[node.val];

        let newNode = new Node(node.val);
        visited[node.val] = newNode;

        for (let i = 0; i < node.neighbors.length; i++) {
            newNode.neighbors.push(dfs(node.neighbors[i]));
        }
        return newNode;
     }

     
     return dfs(node);
};
