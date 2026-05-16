
// We need to find the meeting point first
// we can bfs from every friend
// sum their dist to each empty cell
// if a cell has visit == numFriends
// then we get the min dist
// we can traverse the house too
// for each 1, we create a mask
// add that mask to the totalDist
// instead of doing the bfs or create the mask
// use median to solve
// 最佳解：
// 把所有 1 的 row 收集起來：
// rows = [所有朋友的 row]
// 把所有 1 的 col 收集起來：
// cols = [所有朋友的 col]
// 最佳 meeting point 是：
// rowMedian = rows[rows.size() / 2]
// colMedian = cols[cols.size() / 2]
// 然後答案就是所有人到這個點的 Manhattan distance。
// 為什麼可以這樣？
// 假設只有一維：
// positions = [1, 2, 10]
// 選 2：
// |1 - 2| + |2 - 2| + |10 - 2| = 1 + 0 + 8 = 9
// 選 5：
// |1 - 5| + |2 - 5| + |10 - 5| = 4 + 3 + 5 = 12
// 中位數會讓左右兩邊的距離平衡，所以總距離最小。
// 二維 Manhattan distance 可以拆成：
// sum(abs(row_i - meetRow)) + sum(abs(col_i - meetCol))
// 所以 row 找 row median，col 找 col median。


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rows;
        vector<int> cols;

        // rows naturally sorted
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                }
            }
        }

        // cols naturally sorted
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (grid[i][j] == 1) {
                    cols.push_back(j);
                }
            }
        }

        return getDist(rows) + getDist(cols);
    }

    int getDist(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int dist = 0;

        while (l < r) {
            dist += nums[r] - nums[l];
            l++;
            r--;
        }

        return dist;
    }
};


// class Solution {
// public:

    // const int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    // int m;
    // int n;

    // void bfs(const vector<vector<int>>& grid, 
    //         vector<vector<int>>& numVisited, 
    //         vector<vector<int>>& totalDist, int y, int x) {

    //     queue<pair<int, int>> q;
    //     vector<vector<bool>> visited(m, vector<bool>(n, false));

    //     q.push({y, x});
    //     visited[y][x] = true;
    //     numVisited[y][x] += 1;

    //     int layer = 1;
    //     while (!q.empty()) {

    //         int currLayerSize = q.size();
    //         while (currLayerSize) {

    //             auto [y, x] = q.front();
    //             q.pop();

    //             for (const auto& dir : dirs) {
    //                 int ny = y + dir[0];
    //                 int nx = x + dir[1];

    //                 if (ny >= m || ny < 0 || nx >= n || nx < 0)
    //                     continue;
                    
    //                 if (!visited[ny][nx]) {
    //                     numVisited[ny][nx]++;
    //                     totalDist[ny][nx] += layer;
    //                     q.push({ny, nx});
    //                     visited[ny][nx] = true;
    //                 }

    //             }
    //             currLayerSize--;
    //         }
    //         layer++;

    //     }

    // }

    // int minTotalDistance(vector<vector<int>>& grid) {

    //     m = grid.size();
    //     n = grid[0].size();

    //     vector<vector<int>> numVisited(m, vector<int>(n, 0));
    //     vector<vector<int>> totalDist(m, vector<int>(n, 0));

    //     int friendCnt = 0;
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == 1) {
    //                 friendCnt++;
    //                 bfs(grid, numVisited, totalDist, i, j);
    //             }
    //         }
    //     }

    //     int ans = INT_MAX/2;
    //     // cout << "[";
    //     for (int i = 0; i < m; i++) {
    //         // cout << "[";
    //         for (int j = 0; j < n; j++) {

    //             // cout << totalDist[i][j] << " ";

    //             // if (numVisited[i][j] == friendCnt) {
    //             ans = min(ans, totalDist[i][j]);
    //             // }
    //         }
    //         // cout << "]";
    //     }
    //     // cout << "]" << endl;

    //     return ans;
        
    // }

    // we can traverse the house too
    // for each 1, we create a mask
    // add that mask to the totalDist
    
//     int m;
//     int n;
//     const int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

//     void addDist(vector<vector<int>>& totalDist, int y, int x) {

//         queue<pair<int,int>> q;
//         vector<vector<bool>> visited(m, vector<bool>(n, false)); 
//         q.push({y, x});
//         visited[y][x] = true;

//         int layer = 1;
//         while (!q.empty()) {

//             int currLayerSize = q.size();
//             while (currLayerSize) {

//                 auto [y, x] = q.front();
//                 q.pop();

//                 for (const auto& dir : dirs) {
//                     int ny = y + dir[0];
//                     int nx = x + dir[1];

//                     if (ny >= m || ny < 0 || nx >= n || nx < 0)
//                         continue;
                    
//                     if (!visited[ny][nx]) {
//                         totalDist[ny][nx] += layer;
//                         q.push({ny, nx});
//                         visited[ny][nx] = true;
//                     }

//                 }
//                 currLayerSize--;
//             }
//             layer++;
//         }


//     }

//     int minTotalDistance(vector<vector<int>>& grid) {

//         m = grid.size();
//         n = grid[0].size();

//         vector<vector<int>> totalDist(m, vector<int>(n, 0));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 1) {
//                     addDist(totalDist, i, j);
//                 }
//             }
//         }

//         int ans = INT_MAX/2;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 ans = min(totalDist[i][j], ans);
//             }
//         }
//         return ans;
//     }


// };