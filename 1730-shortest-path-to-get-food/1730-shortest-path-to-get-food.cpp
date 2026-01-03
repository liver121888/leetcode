// we can bfs start from the person
// track the layer number
// if we found food, return the layer number
// we need to find the person first
// time complexity: O(MN)
// space complexity: O(1)


class Solution {
public:
    int getFood(vector<vector<char>>& grid) {

        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        int m = grid.size();
        int n = grid[0].size();

        int i = 0, j = 0;
        bool foundSelf = false;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '*') {
                    foundSelf = true;
                    i = r;
                    j = c;
                    break;
                }
            }
            if (foundSelf)
                break;
        }

        queue<vector<int>> bfs;
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));

        // cout << i << " " << j << m << " " << n << endl;

        bfs.push({i, j});
        visited[i][j] = true;
        int pathLength = 0;
        bool foodFound = false;

        while(!bfs.empty()) {

            int levelSize = bfs.size(); // Lock the size for the current level

            // Process all nodes in the current level
            for (int i = 0; i < levelSize; i++) {
                auto coords = bfs.front();
                bfs.pop();
                int r = coords[0];
                int c = coords[1];

                if (grid[r][c] == '#') {
                    return pathLength; // Found food
                }

                for (auto& dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n 
                        && !visited[nr][nc] && grid[nr][nc] != 'X') {
                        visited[nr][nc] = true;
                        bfs.push({nr, nc});
                    }
                }
            }
            // Increment pathLength after finishing a full layer
            pathLength++;

        }

        return foodFound ? pathLength : -1;
    }
};