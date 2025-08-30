class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int N = 9;

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        // this idea is clever to use the r c to indexing, and come up with another idx to find the block 
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                char val = board[r][c];
                // Check if the position is filled with number
                if (val == '.') {
                    continue;
                }
                // Check the row
                if (rows[r].find(val) != rows[r].end()) {
                    return false;
                }
                rows[r].insert(val);
                // Check the column
                if (cols[c].find(val) != cols[c].end()) {
                    return false;
                }
                cols[c].insert(val);
                // Check the box
                int idx = (r / 3) * 3 + c / 3;
                if (boxes[idx].find(val) != boxes[idx].end()) {
                    return false;
                }
                boxes[idx].insert(val);

            }
        }
        return true;
    }
};