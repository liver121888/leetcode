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


// optimal
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Total Mtrix to store total distance sum for each empty cell.
        vector<vector<int>> total(rows, vector<int> (cols, 0));

        int emptyLandValue = 0;
        int minDist = INT_MAX;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // Start a bfs from each house.
                if (grid[row][col] == 1) {
                    minDist = INT_MAX;

                    // Use a queue to perform a BFS, starting from the cell located at (row, col).
                    queue<pair<int, int>> q;
                    q.push({ row, col });
                    
                    int steps = 0;

                    while (!q.empty()) {
                        steps++;

                        for (int level = q.size(); level > 0; --level) {
                            auto curr = q.front();
                            q.pop();

                            for (auto& dir : dirs) {
                                int nextRow = curr.first + dir[0];
                                int nextCol = curr.second + dir[1];

                                // For each cell with the value equal to empty land value
                                // add distance and decrement the cell value by 1.
                                if (nextRow >= 0 && nextRow < rows &&
                                    nextCol >= 0 && nextCol < cols &&
                                    grid[nextRow][nextCol] == emptyLandValue) {
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;

                                    q.push({ nextRow, nextCol });
                                    minDist = min(minDist, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }

                    // Decrement empty land value to be searched in next iteration.
                    emptyLandValue--;
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};

// class Solution {
// public:

//     int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//     int m;
//     int n;

//     void bfs(const vector<vector<int>>& grid, vector<vector<vector<int>>>& data, int y, int x) {

//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         queue<pair<int,int>> q;
//         q.push({y, x});
//         visited[y][x] = true;

//         int level = 0;

//         while (!q.empty()) {

//             int numNode = q.size();
//             while (numNode) {
//                 auto [r, c] = q.front();
//                 q.pop();

//                 // If we reached an empty cell, then add the distance
//                 // and increment the count of houses reached at this cell.
//                 if (grid[r][c] == 0) {
//                     data[r][c][1] += level;
//                     data[r][c][0] += 1;
//                 }

//                 for (const auto& dir : dirs)  {
//                     int nr = r + dir[0];
//                     int nc = c + dir[1];

//                     if (nr >= m || nc >= n || nr < 0 || nc < 0)
//                         continue;

//                     if (!visited[nr][nc] && grid[nr][nc] == 0) {
//                         // data[nr][nc][0]++;
//                         // data[nr][nc][1] += level;
//                         visited[nr][nc] = true;
//                         q.push({nr, nc});
//                     }
//                 }

//                 numNode--;
//             }

//             level++;
//         }

//     }

//     int shortestDistance(vector<vector<int>>& grid) {

//         m = grid.size();
//         n = grid[0].size();

//         // number of visits, sum of distance
//         vector<vector<vector<int>>> data(m, vector<vector<int>>(n, {0, 0})); 

//         int houseNum = 0;

//         // traverse to find 1
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     houseNum++;
//                     bfs(grid, data, i, j);
//                 }
//             }
//         }

//         int minDistSum = INT_MAX;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 int numVisit = data[i][j][0];
//                 int distSum = data[i][j][1];
//                 if (numVisit == houseNum) {
//                     minDistSum = min(distSum, minDistSum);
//                 }

//             }

//         }
//         return minDistSum == INT_MAX ? -1 : minDistSum;
//     }
// };
