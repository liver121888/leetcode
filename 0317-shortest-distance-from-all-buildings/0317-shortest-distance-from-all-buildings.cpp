// class Solution {
// public:

//     // calc heuristic so we can rule out most of the possible solutions

//     // int dist(int x0, int y0, int x1, int y1){
//     //     return abs(x0 - x1) + abs(y0 - y1);
//     // }

//     // string hash(int i, int j) {
//     //     return i.to_string() + " " j.to_string();
//     // }

//     // pair<int, int> unHash(string hash) {
//     //     int idx = hash.find(' ') - hash.begin();
//     //     int x = stoi(hash.substring(0, idx));
//     //     int y = stoi(hash.substring(idx + 1, hash.length()));
//     //     return make_pair<int, int>(x, y);
//     // }

//     const vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     int shortestDistance(vector<vector<int>>& grid) {

//         // get all the buildings first
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = INT_MAX;

//         int totalBuildings = 0;
//         for (int i = 0; i < m; i++)
//             for (int j = 0; j < n; j++)
//                 if (grid[i][j] == 1)
//                     totalBuildings++;

//         cout << "totalBuildings: " << totalBuildings << endl;

//         // unordered_set<string> buildings;
//         // O(m*n*m*n) -> O(m^2 * n^2)
//         // space: O(m*n)

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 cout << "i: " << i << " j: " << j << endl;
//                 if (grid[i][j] == 0) {
//                     queue<int> bfs;
//                     unordered_set<int> visited;
//                     int level = 0;
//                     int totalTravelDistance = 0;
//                     int buildingCnts = 0;
//                     bfs.push(i * n + j);
//                     bool earlyEnd = false;

//                     while(!bfs.empty()) {
//                         int currLayerSize = bfs.size();
//                         while (currLayerSize > 0) {
//                             auto curr = bfs.front();
//                             bfs.pop();
//                             int c = curr % n;
//                             int r = curr / n;

//                             visited.insert(curr);

//                             for (auto dir : dirs) {
//                                 int new_r = r + dir[0];
//                                 int new_c = c + dir[1];
//                                 // check boundary
//                                 if (new_r >= m || new_c >= n || new_r < 0 || new_c < 0)
//                                     continue;

//                                 int neighbor = new_r * n + new_c;
//                                 if (!visited.count(neighbor)) {
//                                     int type = grid[new_r][new_c];
//                                     if (type == 0) {
//                                         bfs.push(neighbor);
//                                     } else if (type == 1) {
//                                         totalTravelDistance += level + 1;
//                                         buildingCnts++;
//                                         // for earlyEnd
//                                         if (buildingCnts == totalBuildings) {
//                                             earlyEnd = true;
//                                             break;
//                                         }
//                                     }
//                                     // obstacle otherwise
//                                 }

//                             }
//                             if (earlyEnd)
//                                 break;
//                             currLayerSize--;
//                         }
//                         if (earlyEnd)
//                             break;
//                         level++;
//                     } 
//                     ans = min(totalTravelDistance, ans);
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
private:
    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouses) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        int distanceSum = 0;
        int housesReached = 0;

        // Queue to do a bfs, starting from (r,c) cell
        queue<pair<int, int>> q;
        q.push({ row, col });

        // Keep track of visited cells
        vector<vector<bool>> vis(rows, vector<bool> (cols, false));
        vis[row][col] = true;

        int steps = 0;

        while (!q.empty() && housesReached != totalHouses) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();

                row = curr.first;
                col = curr.second;

                // If this cell is a house, then add the distance from the source to this cell
                // and we go past from this cell.
                if (grid[row][col] == 1) {
                    distanceSum += steps;
                    housesReached++;
                    continue;
                }

                // This cell was an empty cell, hence traverse the next cells which is not a blockage.
                for (auto& dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                            vis[nextRow][nextCol] = true;
                            q.push({nextRow, nextCol});
                        }
                    }
                }
            }
            
            // After traversing one level cells, increment the steps by 1 to reach to next level.
            steps++;
        }

        // If we did not reach all houses, then any cell visited also cannot reach all houses.
        // Set all cells visted to 2 so we do not check them again and return INT_MAX.
        if (housesReached != totalHouses) {
            for (row = 0; row < rows; row++) {
                for (col = 0; col < cols; col++) {
                    if (grid[row][col] == 0 && vis[row][col]) {
                        grid[row][col] = 2;
                    }
                }
            }
            return INT_MAX;
        }
        // If we have reached all houses then return the total distance calculated.
        return distanceSum;
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();
        int totalHouses = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) { 
                    totalHouses++;
                }
            }
        }

        // Find the min distance sum for each empty cell.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    minDistance = min(minDistance, bfs(grid, row, col, totalHouses));
                }
            }
        }

        // If it is impossible to reach all houses from any empty cell, then return -1.
        if (minDistance == INT_MAX) {
            return -1;
        }
        return minDistance;
    }
};