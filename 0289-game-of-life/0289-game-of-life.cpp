// for each cell
// we check neighbor -> determine the new state
// we also check bound
// how do we update the board in place?
// we can revisit later


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();

        static const vector<vector<int>> neighbors = {{-1,-1}, {-1,0}, 
                                        {-1, 1}, {0, -1},
                                        {0, 1}, {1, -1},
                                        {1, 0}, {1, 1}};

        vector<vector<int>> tmp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                bool liveCell = board[i][j];
                int liveNum = 0;
                for (const auto& neighbor : neighbors) {
                    int nr = i + neighbor[0];
                    int nc = j + neighbor[1];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n) {
                        // in bound
                        liveNum += board[nr][nc];
                    }
                }

                if (liveCell) {
                    if (liveNum < 2 || liveNum > 3)
                        tmp[i][j] = 0;
                    else
                        tmp[i][j] = 1;
                } else {
                    if (liveNum == 3)
                        tmp[i][j] = 1;
                }
                cout << i << " " << j << " " << liveNum << endl;
            }
        }
        
        // assign
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = tmp[i][j];
        
    }
};