// when someone wins, on one side of the board we need to check
// horizontal, vertical and the diagonal
// we can init a 2d array
// -1 player 1
// 0 empty
// 1 player 2
// after each move we took we need to check the condition
// space: O(n^2)
// time: O(n)  

// we can design horizontal, vertical and diagonal
// and only mark there and check the squares related to that


class TicTacToe {
public:

    vector<vector<int>> board;
    int n;

    TicTacToe(int n) {
        this->n = n;
        board.assign(n, vector<int>(n, 0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;
        if (checkCol(col, player) || checkRow(row, player))
            return player;
        if (row == col) {
            if (checkDiagonal(player))
                return player;
        }

        if (row == n - 1 - col) {
            if (checkAntiDiagonal(player))
                return player;
        }

        return 0;
    }

    bool checkDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][row] != player)
                return false;
        }
        return true;
    }


    bool checkAntiDiagonal(int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][n-1-row] != player)
                return false;
        }
        return true;
    }

    bool checkCol(int col, int player) {
        for (int row = 0; row < n; row++) {
            if (board[row][col] != player) return false;
        }
        return true;
    }

    bool checkRow(int row, int player) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] != player) return false;
        }
        return true;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */