// Solution 1
/**
 * @param {number[][]} board
 * @return {number}
 */
var snakesAndLadders = function(board) {
    const height = board.length;
    const numBoard = buildMap(height);
    // console.log(numBoard);
    let count = 0;
    let curr = numBoard[height - 1][0]; // 1
    const queue = [];
    const predecessors = {};
    queue.push(curr);
    while (queue.length !== 0) {
        const next = queue.shift();
        // console.log(next);
        if (next === height ** 2) return count;
        for (let i = next + 1; i < Math.min(next + 6, height ** 2); i++) {
            // console.log(visited);
            const neighbCoords = getCoords(numBoard, i, height);
            let neighbour = numBoard[neighbCoords[0]][neighbCoords[1]];
            const neighbourVal = board[neighbCoords[0]][neighbCoords[1]];
            if (!(neighbour in predecessors)) {
                addValue(predecessors, next, neighbour);
                // predecessors[next] = neighbour;
                queue.push(neighbour);
                if (neighbourVal !== -1) {
                    addValue(predecessors, neighbour, neighbourVal);
                    // predecessors[neighbour] = neighbourVal;
                    queue.push(neighbourVal);
                }
            }
        }
    }
    
    console.log(predecessors)
    let prev = height ** 2;
    while (prev != 1) {
        const coords = getCoords(numBoard, prev, height);
        const pred = numBoard[coords[0]][coords[1]];
        if (!(prev in predecessors)) break;
        prev = predecessors[pred];
        count++;
    }

    return count > 0 ? count : -1;
};

function getCoords(board, squareNum, height) {
    for (let i = 0; i < height; i++) {
        for (let j = 0; j < height; j++) {
            if (board[i][j] === squareNum) return [i, j];
        }
    }

    return null;
}

function buildMap(height) {
    const board = new Array(height);
    let pos = 1;
    let i = height - 1;
    for (let i = height - 1; i >= 0; i--) {
        board[i] = new Array(height);
        for (let j = 0; j < height; j++) {
            let h = j;
            if (i % 2 === 0) h = height - j - 1;
            board[i][h] = pos;
            pos++;
        }
    }

    return board;
}

// stopped after implementation of this, FAILURE today
function addValue(map, key, value) {
    if (!(key in map)) {
        map[key] = [];
    }
    map[key].push(value);
}


// Solution 2
var snakesAndLadders = function(board) {
    let n = board.length;
    let set = new Set();
    let getPos = (pos) => {
        let row = Math.floor((pos - 1) / n)
        let col = (pos-1) % n
        col = row % 2 == 1 ? n - 1 - col : col;
        row = n - 1 - row;
        return [row, col]
    }
    let q = [[1, 0]]
    while(q.length > 0){
        [pos, moves] = q.shift();
        for(let i = 1; i < 7; i++){
            let newPos = i + pos;
            let [r, c] = getPos(newPos);
            if(board[r][c] != -1 ) newPos = board[r][c]
            if(newPos == n * n) return moves+1;
            if(!set.has(newPos)){
                set.add(newPos)
                q.push([newPos, moves+1])
            }
        }
    }
    return -1;
};
