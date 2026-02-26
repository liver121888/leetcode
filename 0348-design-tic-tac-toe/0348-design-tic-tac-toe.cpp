
// brute-forece method
// create n*n table
// when put in a move, we check the row, col
// if it's on diagonal, we also need to check the diag
// so the time complexity is O(2n)?


// Follow-up: Could you do better than O(n^2) per move() operation?

// we can do an unordered_map
// we record the row col that a player has played
// if a certain row, a certain col, a certain diag has been place 
// n times, we know the player wins
// we can think of it as if player one plays it we +1
// other wise we -1
// if after any move, we find the number hits n
// we know the player wins

class TicTacToe {
public:

    int n;
    // we choose unorderd_map because the input might be sparse
    unordered_map<int, int> rowCnts;
    unordered_map<int, int> colCnts;
    vector<int> diagCnts;

    TicTacToe(int n) {
        this->n = n;
        diagCnts = vector<int>(2, 0);
    }
    
    int move(int row, int col, int player) {

        // player is 1 or 2
        int diff = player == 1 ? 1 : -1;

        rowCnts[row] += diff;
        if (abs(rowCnts[row]) == n) {
            return rowCnts[row] > 0 ? 1 : 2;
        }

        colCnts[col] += diff;
        if (abs(colCnts[col]) == n) {
            return colCnts[col] > 0 ? 1 : 2;
        }

        // diag: i - j = 0
        // anti-diag: i + j = n - 1

        if (row - col == 0) {
            diagCnts[0] += diff;
            if (abs(diagCnts[0]) == n)
                return diagCnts[0] > 0 ? 1 : 2;
        }
        
        if (row + col == n - 1) {
            diagCnts[1] += diff;
            if (abs(diagCnts[1]) == n)
                return diagCnts[1] > 0 ? 1 : 2;
        }

        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */