class Solution {
public:
    int n;
    int m;
    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        // bfs from current cell and see the nearest cell
        // we can called this funciton by m*n times

        // time complexity: m*n*m*n = O(m*n)^2 in worst case
        // space complexity: O(1)

        // some edges cases
        // [1, 1, 0]
        // [0, 1, 1]
        // [1, 1, 1]
        // bfs 0, 0
        // [1, 1, 0]
        // [0, 1, 1]
        // [1, 2, 2]

        // is there a way we do this space O(1) but O(mn)?

        m = mat.size();
        n = mat[0].size();
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<vector<int>> matrix(m, vector<int>(n, 0));
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        queue<vector<int>> q;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                matrix[row][col] = mat[row][col];
                if (matrix[row][col] == 0) {
                    q.push({row, col, 0});
                    seen[row][col] = true;
                }
            }
        }

        while (!q.empty()) {
            vector<int> curr = q.front();
            q.pop();
            int row = curr[0], col = curr[1], steps = curr[2];
            
            for (vector<int>& direction: directions) {
                int nextRow = row + direction[0], nextCol = col + direction[1];
                if (valid(nextRow, nextCol) && !seen[nextRow][nextCol]) {
                    seen[nextRow][nextCol] = true;
                    q.push({nextRow, nextCol, steps + 1});
                    matrix[nextRow][nextCol] = steps + 1;
                }
            }
        }

        return matrix;

    }
};