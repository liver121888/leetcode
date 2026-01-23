class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    bool dfs(vector<vector<char>> &grid, const string &word, int idx, int x, int y){
        if(idx >= word.size()) 
            return true;

        for(int i=0; i<4; i++){
            int nx = x + dir[i], ny = y + dir[i+1];
            if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size() || grid[nx][ny] == ' ' || grid[nx][ny] != word[idx]) continue;
            char tmp = grid[nx][ny];
            grid[nx][ny] = ' ';
            if(dfs(grid, word, idx+1, nx, ny))
                return true;
            grid[nx][ny] = tmp;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word){
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    char tmp = board[i][j];
                    board[i][j] = ' ';
                    if(dfs(board, word, 1, i, j)) return true;
                    board[i][j] = tmp;
                }
            }
        }
        return false;
    }

};
