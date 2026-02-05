// click is always in bound
// click is always on the M or E
// we need to set digit

// ideally, we want to separate the logic of revealing
// and the marking digits
// if the click is on the mine, we marked the board and end game

// time complexity: O(mn), we go to each square at most once
// space complexity: O(mn) for call stack

class Solution {
public:

    int m, n;

    const vector<pair<int,int>> neighbors = {{-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, 
                                            {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void update(vector<vector<char>>& board, int y, int x) {

        // cout << "y: " << y << " x: " << x;

        // we only update inbound cell
        if (y < 0 || y >= m || x < 0 || x >= n)
            return;

        // we only update unreveal cell, and we don't update 'M'
        if (board[y][x] != 'E')
            return;


        // count the mine around
        int mineCnt = 0;
        for (const auto& neighbor : neighbors) {
            int ny = y + neighbor.first;
            int nx = x + neighbor.second;
            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if (board[ny][nx] == 'M')
                mineCnt++;
        }


        // mark the cell
        if (mineCnt != 0) {
            board[y][x] = '0' + mineCnt;
            // if we met with number, don't dfs into it
        } else {
            board[y][x] = 'B';
            // update adjacent square
            for (const auto& neighbor : neighbors)
                update(board, y + neighbor.first, x + neighbor.second);
        }
    }


    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

        m = board.size();
        n = board[0].size();

        // early end
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }

        // then it has to be 'E'
        // recursive open and mark the board
        update(board, click[0], click[1]);
        return board;        
    }

    // [["E","E","E","E","E","E","E","E"],
    // ["E","E","E","E","E","E","E","M"],
    // ["E","E","M","E","E","E","E","E"],
    // ["M","E","E","E","E","E","E","E"],
    // ["E","E","E","E","E","E","E","E"],
    // ["E","E","E","E","E","E","E","E"],
    // ["E","E","E","E","E","E","E","E"],
    // ["E","E","M","M","E","E","E","E"]]

    // [["B","B","B","B","B","B","1","E"]
    // ["B","1","1","1","B","B","1","M"],
    // ["1","2","M","1","B","B","1","1"],
    // ["M","E","1","1","B","B","B","B"],
    // ["1","1","B","B","B","B","B","B"],
    // ["B","B","B","B","B","B","B","B"],
    // ["B","1","2","2","1","B","B","B"],
    // ["B","1","M","M","1","B","B","B"]]


};