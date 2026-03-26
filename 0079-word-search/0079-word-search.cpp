class Solution {
public:
    int dirs[5] = {-1, 0, 1, 0, -1};

    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        // 先檢查目前格子是否符合 word[k]
        if (board[i][j] != word[k]) return false;

        // 如果已經匹配到最後一個字元，成功
        if (k == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = '#';  // 標記已訪問

        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];

            if (ni < 0 || ni >= board.size() || nj < 0 || nj >= board[0].size())
                continue;

            if (board[ni][nj] == '#')
                continue;

            if (dfs(board, word, ni, nj, k + 1))
                return true;
        }

        board[i][j] = temp;  // 回溯
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};