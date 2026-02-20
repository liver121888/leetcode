// brute-force
// try every zero, we compare the total distance, and find the minimum
// O(m*n * m * n)

// [1, 1, 0, 1] -> -1;
// calculate nearest 1
// we can start flooding from evey 1
// we end the algorithm when a 0 is visited by flooding from every one
// we take out the sum -> minimum dist from all building
// O(m^2n^2)
// O(m^2n^2) -> visited times + the sum of dist

// we use 0 as the building, dist in the grid
// we use -1 as obstaces
// queue<pair<int,int>> the future flood coords
// grid[i][j] = numVisit, sum of dist
// directions vector
// while (!queue.empty())

class Solution {
public:

    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m;
    int n;

    void bfs(const vector<vector<int>>& grid, vector<vector<vector<int>>>& data, int y, int x) {

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({y, x});
        visited[y][x] = true;

        int level = 0;

        while (!q.empty()) {

            int numNode = q.size();
            while (numNode) {
                auto [r, c] = q.front();
                q.pop();

                // If we reached an empty cell, then add the distance
                // and increment the count of houses reached at this cell.
                if (grid[r][c] == 0) {
                    data[r][c][1] += level;
                    data[r][c][0] += 1;
                }

                for (const auto& dir : dirs)  {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr >= m || nc >= n || nr < 0 || nc < 0)
                        continue;

                    if (!visited[nr][nc] && grid[nr][nc] == 0) {
                        // data[nr][nc][0]++;
                        // data[nr][nc][1] += level;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }

                numNode--;
            }

            level++;
        }

    }

    int shortestDistance(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // number of visits, sum of distance
        vector<vector<vector<int>>> data(m, vector<vector<int>>(n, {0, 0})); 

        int houseNum = 0;

        // traverse to find 1
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    houseNum++;
                    bfs(grid, data, i, j);
                }
            }
        }

        int minDistSum = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int numVisit = data[i][j][0];
                int distSum = data[i][j][1];
                if (numVisit == houseNum) {
                    minDistSum = min(distSum, minDistSum);
                }

            }

        }
        return minDistSum == INT_MAX ? -1 : minDistSum;
    }
};