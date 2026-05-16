
// can do simple bfs on the grid
// O(n^2)
// space O(n^2) for the queue

// grid is always square



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        int dirs[8][2] = {
            {-1, 0}, {0, -1}, {1, 0}, {0, 1},
            {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int pathLen = 1;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [y, x] = q.front();
                q.pop();

                if (y == n - 1 && x == n - 1)
                    return pathLen;

                for (auto& dir : dirs) {
                    int ny = y + dir[0];
                    int nx = x + dir[1];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;

                    if (grid[ny][nx] == 0) {
                        grid[ny][nx] = 1;
                        q.push({ny, nx});
                    }
                }
            }

            pathLen++;
        }

        return -1;
    }
};

// class Solution {

// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         int n = grid.size();
//         // int n = grid[0].size();

//         if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
//             return -1;

//         // const vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

//         const int dy[8] = {0, -1, 0, 1, -1, 1, 1, -1};
//         const int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1};

//         // int dirs[8][2] = {
//         //     {-1, 0}, {0, -1}, {1, 0}, {0, 1},
//         //     {-1, -1}, {1, 1}, {-1, 1}, {1, -1}
//         // };

//         int pathLen = 1;

//         queue<pair<int,int>> bfs;

//         bfs.push({0, 0});
//         grid[0][0] = 1;

//         while (!bfs.empty()) {
            
//             int currLayerSize = bfs.size();
//             while (currLayerSize) {
//                 auto [y, x] = bfs.front();
//                 bfs.pop();

//                 if (y == n - 1 && x == n - 1)
//                     return pathLen;
                
//                 for (int i = 0; i < 8; i++) {
//                     int ny = y + dy[i];
//                     int nx = x + dx[i];

//                     if (ny >= n || ny < 0 || nx >= n || nx < 0)
//                         continue;
                    
//                     if (grid[ny][nx] != 1) {
//                         bfs.push({ny, nx});
//                         grid[ny][nx] = 1;
//                     }

//                 }

//                 currLayerSize--;
//             }

//             pathLen++;

//         }

//         return -1;
        
//     }
// };