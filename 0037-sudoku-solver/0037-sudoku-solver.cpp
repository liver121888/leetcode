class Solution {
public:

    static const int n = 9;
    unordered_set<int> rows[n];
    unordered_set<int> cols[n];
    unordered_set<int> boxes[n];

    bool isValid(int r, int c, int num) {
        if (rows[r].find(num) != rows[r].end())
            return false;
        if (cols[c].find(num) != cols[c].end())
            return false;
        int boxId = (r / 3) * 3 + c / 3;
        if (boxes[boxId].find(num) != boxes[boxId].end())
            return false;
        return true;
    }



    bool backtrack(vector<vector<char>>& board, int r, int c) {

        // finish backtrack
        if (r == n - 1 and c == n)
            return true;
        else if (c == n) {
            c = 0;
            r += 1;
        }

        // current cell has been filled
        if (board[r][c] != '.')
            return backtrack(board, r, c + 1);


        int boxId = (r / 3) * 3 + c / 3;
        for (int v = 1; v <= 9; v++) {
            if (!isValid(r, c, v))
                continue;

            // set state
            board[r][c] = '0' + v;
            rows[r].insert(v);
            cols[c].insert(v);
            boxes[boxId].insert(v);

            if (backtrack(board, r, c + 1))
                return true;

            // reset state
            board[r][c] = '.';
            rows[r].erase(v);
            cols[c].erase(v);
            boxes[boxId].erase(v);
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i].insert(num);
                    cols[j].insert(num);
                    boxes[(i/3) * 3 + j/3].insert(num);
                }
            }
        }

        backtrack(board, 0, 0);
    }
};