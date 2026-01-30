// for each cell
// we check neighbor -> determine the new state
// we also check bound
// how do we update the board in place?
// we can revisit later

// ok what if we can save the number of neighbor?
// we also need to know our state
// we can encode if 0 -> record neighborNum
// if 1 -> 10 + neighborNum

// [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
// [[1,11,2],[3,5,13],[11,13,12],[2,3,2]]
// we should use +10 for process but dead
// +20 for processed but alive

// we know it's a 0 and has 1 neighbor
// we know it's a 1 and has 1 neighbor ...

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        static const vector<vector<int>> neighbors = {{-1,-1}, {-1,0}, 
                                        {-1, 1}, {0, -1},
                                        {0, 1}, {1, -1},
                                        {1, 0}, {1, 1}};



        // in place, encode
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                bool liveCell = board[i][j];

                int liveNum = 0;
                for (const auto& neighbor : neighbors) {
                    int nr = i + neighbor[0];
                    int nc = j + neighbor[1];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                        // in bound
                        if (board[nr][nc] < 10) {
                            // unprocess, directly add
                            liveNum += board[nr][nc];
                        }
                        else if (board[nr][nc] >= 20) {
                            // process, and is live cell
                            liveNum += 1;
                        }
                        // process, and is not a live cell
                    }
                }

                if (liveCell) {
                    board[i][j] = 20 + liveNum;
                } else {
                    board[i][j] = 10 + liveNum;
                }
                // cout << i << " " << j << " " << liveNum << endl;
            }
        }

        // [[0,0,0,0,0,0],
        // [0,0,1,1,0,0],
        // [0,1,0,0,1,0],
        // [0,0,1,1,0,0],
        // [0,0,0,0,0,0]]



        cout << "[";
        for (int i = 0; i < m; i++) {
            cout << "[";
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << "]" << endl;
        }
        cout << "]" << endl;



        // decode
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] >= 20) {
                    // live cell
                    int nNum = board[i][j] - 20;
                    if (nNum < 2 || nNum > 3)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                } else {
                    // dead cell
                    int nNum = board[i][j] - 10;
                    if (nNum == 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 0;
                }

            }
        }





        // // copy
        // vector<vector<int>> tmp(m, vector<int>(n, 0));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {

        //         bool liveCell = board[i][j];
        //         int liveNum = 0;
        //         for (const auto& neighbor : neighbors) {
        //             int nr = i + neighbor[0];
        //             int nc = j + neighbor[1];
        //             if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
        //                 // in bound
        //                 liveNum += board[nr][nc];
        //             }
        //         }

        //         if (liveCell) {
        //             if (liveNum < 2 || liveNum > 3)
        //                 tmp[i][j] = 0;
        //             else
        //                 tmp[i][j] = 1;
        //         } else {
        //             if (liveNum == 3)
        //                 tmp[i][j] = 1;
        //         }
        //         // cout << i << " " << j << " " << liveNum << endl;
        //     }
        // }
        
        // // assign
        // for (int i = 0; i < m; i++)
        //     for (int j = 0; j < n; j++)
        //         board[i][j] = tmp[i][j];
        
    }
};