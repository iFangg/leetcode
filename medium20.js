// Solution 1
/**
 * @param {number[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var gameOfLife = function(board) {
    const height = board.length;
    const width = board[0].length;
    const deltaCoords = new Map();
    
    let curr = [0,0];
    while (curr[0] < height && curr[1] < width) {
        let neighbours = 0;
        for (let i = -1; i <= 1; i++) {
            if (curr[0] + i < 0 || curr[0] + i >= height) continue;
            for (let j = -1; j <= 1; j++) {
                if (i === 0 && j === 0) continue;
                if (curr[1] + j < 0 || curr[1] + j >= width) continue;
                if (board[curr[0] + i][curr[1] + j] === 1) neighbours++;
            }
        }
        if (neighbours < 2 || neighbours > 3) {
            if (!deltaCoords.has(0)) deltaCoords.set(0, [[curr[0], curr[1]]]);
            else deltaCoords.get(0).push([curr[0], curr[1]]);
        } else {
            if (board[curr[0]][curr[1]] === 0 && neighbours != 3) {
               if (!deltaCoords.has(0)) deltaCoords.set(0, [[curr[0], curr[1]]]);
                else deltaCoords.get(0).push([curr[0], curr[1]]); 
            } else {
                if (!deltaCoords.has(1)) deltaCoords.set(1, [[curr[0], curr[1]]]);
                else deltaCoords.get(1).push([curr[0], curr[1]]);
            }
        }
        if (curr[1] < width - 1) curr[1]++;
        else {
            curr[0]++;
            curr[1] = 0;
        }
    }

    if (!deltaCoords.has(0)) deltaCoords.set(0, []);
    if (!deltaCoords.has(1)) deltaCoords.set(1, []);
    
    for (let coords of deltaCoords.get(0)) {
        board[coords[0]][coords[1]] = 0;
    }

    for (let coords of deltaCoords.get(1)) {
        board[coords[0]][coords[1]] = 1;
    }
};


// Solution 2
    /* Algo (Final Reviwed*)
      -  alive to dead ===> -1, dead to alive ==> 2
      - if cell is -1 or 1 then we can detect it as alive, find all the alive neighbours
      
      
       Simple program, just go over it.
       - since we are using 0, 1 for dead or alive.
       live ----> dead ====> -1
          if cell is alive (1)  then if number of neighbours is <2 or >3 then cell becomes dead
     
       dead ----> alive ===>  2. (if neighbours is ===3)
          if cell is dead (0) then if neighoubrs are exaclty 3 then cell becomes alive.

    -- while finding the neighbours, after boundary condtions we need to check if board[i][j] === 1 or -1, -1 is artifical one that we made it dead, originally it was alive, so this is needed for other cells to calculate its values

    --- old
            let us assume 
        -1 denotes a cell been alive to dead.
        2 represent cell been dead to alive.
        
        update this values in one pass
        and update the original values in the second pass.
        
        
        Challenge 1: Defining 8 directions in terms of 0,1,-1 to find all the neibhours is NEW thing
        Chaallenge 2: marking each cell with -1 and 2 is NEW and awesome.

        Follow Up 2: what if the board is infinite ?
                     - can't store the infinite matrix in memory 
                     - we'll be wasting space if the we have small number of 1s in the matrix 
                sparse matrix, it woulln't make sense to store entire matrix for this, this is widely the problem with any 0 or 1 matrix, YOU CAN EXPECT THIS FOLLOW UP QUESTION IN THOSE CASES
        
        Sol1 : if we can have some space to store matrix (huge with less number of 1s) then we can just store the adress of the live cells and update them as per the rules

        Sol2: if we dont have space at all to store matrix, then we can store the rows in the file in sequentila manner, if we were to update the 8 possible neighbours then we would only need to fetch its TOP ROW AND BOTTOM ROW, with that we can update check if the cell is alive or not.

        so at most only 3 reads from the file would be suffice.



    */
var gameOfLife = function(board) {
    let m = board.length;
    let n = board[0].length;
    
    function findAliveNeighbours(row, col) {
        let liveCount = 0;
        // clockwise direction, starting form topleft to left 
        let dir = [[-1,-1],[-1,0],[-1,1],[0,1],[1,1],[1,0],[1,-1],[0,-1]];
        
        for(let [r, c] of dir) {
            // r,c has to change everytime not the row and col
            r = row + r;
            c = col + c;
            if(r>=0 && r<m && c>=0 && c<n && (board[r][c] === 1 || board[r][c] === -1)) liveCount++;
        }
        
        return liveCount;
    }
    
    for(let i=0; i<board.length; i++) {
        for(let j=0; j<board[0].length; j++) {
            let cell = board[i][j];
            let noOfNeiAlive = findAliveNeighbours(i,j);
            if(cell === 0) { // if cell is dead
                if(noOfNeiAlive === 3) board[i][j] = 2; // dead to alive marker
            } else if (cell === -1 || cell === 1) { // cell is alive initially, could be -1 or 1
                if(noOfNeiAlive < 2 || noOfNeiAlive >3) board[i][j] = -1; // alive to dead marker
            }
        }
    }

    for(let i=0; i<board.length; i++) {
        for(let j=0; j<board[0].length; j++) {
            let cell = board[i][j];
            if(cell === 2) board[i][j] = 1;
            if(cell === -1) board[i][j] = 0;
        }
    }
};
