
// the grid only has lowercase eng char
// we can only move around the same character
// we can only move in for diections
// we can bfs on every cell
// we also need to have a global visited, so we know 
// where we already tried
// time O(mn), since we visit each cell exactly once
// space: O(mn), we marked visited

class Solution {
public:

    const int dirs[5] = {-1, 0, 1, 0, -1};
    int m;
    int n;

    // find cycle, use recursive is easier
    // if use iterative, save parent info
    bool dfs(const vector<vector<char>>& grid,
             vector<vector<bool>>& visited,
             int y, int x, int py, int px,
             char group) {
        
        visited[y][x] = true;

        for (int k = 0; k < 4; k++) {
            int ny = y + dirs[k];
            int nx = x + dirs[k + 1];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if (grid[ny][nx] != group)
                continue;

            // 不要走回 parent
            if (ny == py && nx == px)
                continue;

            if (visited[ny][nx])
                return true;

            if (dfs(grid, visited, ny, nx, y, x, group))
                return true;
        }

        return false;
    }


    bool containsCycle(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        return false;
    }
};