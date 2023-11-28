// Solution 1
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var averageOfLevels = function(root) {
    const totals = {};
    const numNodes = {};
    const avgs = [];
    const height = getHeight(root, 1);
    findAvg(root, totals, 1, height, numNodes);
    for (let i = 1; i <= height; i++) {
        avgs.push(totals[i] / numNodes[i]);
    }
    
    return avgs;
};

function findAvg(node, totals, n, height, numNodes) {
    if (node === null) return;
    if (!(n in totals)) {
        totals[n] = node.val;
        numNodes[n] = 1;
    }
    else {
        totals[n] += node.val;
        numNodes[n]++;
    }

    findAvg(node.left, totals, n + 1, height, numNodes);
    findAvg(node.right, totals, n + 1, height, numNodes);
}

function getHeight(node) {
    if (node === null) return 0;
    
    const leftHeight = getHeight(node.left);
    const rightHeight = getHeight(node.right);

    // Return the maximum height among left and right subtrees, plus 1 for the current node
    return Math.max(leftHeight, rightHeight) + 1;
}

// Solution 2
var averageOfLevels = function(root) {
    // * s: >=1 node
    if(root?.val === undefined) return [];

    const q = [root];
    const res = [];

    const bfs = () => {
        while(q.length > 0) {

            let sum = 0;
            const size = q.length;
            for(let i=0; i<size; ++i) {
                const cn = q.shift();

                // * s: best place
                sum = sum + cn?.val;

                // * s: q
                if(cn?.left?.val !== undefined) {
                    q.push(cn.left);
                }

                if(cn?.right?.val !== undefined) {
                    q.push(cn.right);
                }
            } // end bfs level

            // * s: count
            res.push(sum / size);
        } // end loop
    }

    bfs();

    return res;
};

