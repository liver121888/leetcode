// absolute difference
// rectangle grid m n
// bfs O(mn)
// space marked visited in place O(1), we also need to save every
// possibility when we reach bottom right
// so we find min effort
// no greedy, we might need to circle around to get the minimum effort

// we can save the minimum effort to each cell
// [[1,2,2],
// [3,8,2],
// [5,3,5]]
// find minimum efforts from 4 directions, find the abs diff of the current cell to the other
// [[0,1,0],
// [2,6,0],
// [2,2,2]]

// we save minimum of the maximum difference

// class Solution {
// public:
//     int minimumEffortPath(vector<vector<int>>& heights) {

//         int m = heights.size();
//         int n = heights[0].size();
//         // id the cells

//         // Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.
//         // top, left, down, right, we save the abs difference
//         int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//         vector<vector<int>> adjList(m*n, vector<int>(4, -1));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 for (int k = 0; k < diretions.size(); k++) {
//                     const auto& direciton = diretions[k];
//                     int nr = direciton[0] + i;
//                     int nc = direction[1] + j;
//                     if (nr < 0 || nr >= m || nc < 0 || nc >= n)
//                         adjList[i*m + j][k] = -1;
//                     else {
//                         adjList[i*m + j][k] = abs(heights[nr][nc] - heights[i][j]);
//                     }
//                 }
//             }
//         }
//     }
// };


class Solution {
public:

    struct Compare {

        // so for sort, from small to large
        // for pq, from large to small
        // but here we are define if a is smaller than b
        // if a is smaller return true, he will be put in the back
        // so we should put >, a has smaller value but return false
        // so will be put in the front
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        }
    };

    int minimumEffortPath(vector<vector<int>>& heights) {

        // 高度差絕對值的最大值。
        // when we reach a cell, we need to record the least effort to a cell
        // and we update its neighbor
        // dijkstra algo can be used

        // edge case
        if (heights.size() == 0 || heights[0].size() == 0)
            return -1;  

        int m = heights.size();
        int n = heights[0].size();

        const vector<int> dirs = {-1, 0, 1, 0, -1};

        // each node is the effort and x y
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        // use minEffort to mark visit, init to unreachable
        vector<vector<int>> minEffort(m, vector<int>(n, INT_MAX/2));

        minEffort[0][0] = 0;
        // effort, y, x
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            
            const auto v = pq.top();
            int effort = v[0];
            int y = v[1];
            int x = v[2];
            // cout << effort << " " << y << " " << x << endl;
            pq.pop();

            if (effort != minEffort[y][x])
                continue;

            if (y == m - 1 && x == n - 1)
                break;

            for (int i = 0; i < 4; i++) {

                int ny = y + dirs[i];
                int nx = x + dirs[i+1];

                if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                    continue;

                // see if we can improve
                int newEffort = max(effort, abs(heights[y][x] - heights[ny][nx]));
                // has to be <, if it's <= may cause inf loop
                if (newEffort < minEffort[ny][nx]) {
                    minEffort[ny][nx] = newEffort;
                    pq.push({newEffort, ny, nx});
                }
            }
        }

        return minEffort[m-1][n-1];
    }
};





// class Solution {
// public:

//     struct Cell {
//         int y, x;
//         int difference;
//         Cell(int y, int x, int difference) : y(y), x(x), difference(difference) {}
//     };

//     // Compare 的語意是：comp(a, b) == true 表示 a 的優先級比 b 低（a 應該排在 b 後面）。而非次序！
//     struct Cmp {
//         bool operator()(const Cell& a, const Cell& b) const {
//             return a.difference > b.difference;
//         }

//     };

//     int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

//     bool isValidCell(int y, int x) {
//         return x >= 0 && x <= col - 1 && y >= 0 && y <= row - 1;
//     }

//     int row, col;

//     int minimumEffortPath(vector<vector<int>>& heights) {

//         row = heights.size();
//         col = heights[0].size();

//         vector<vector<int>> differenceMatrix(row, vector<int>(col, INT_MAX));
//         priority_queue<Cell, vector<Cell>, Cmp>queue;

//         vector<vector<bool>> visited(row, vector<bool>(col, false));

//         differenceMatrix[0][0] = 0;
//         queue.push(Cell(0, 0, differenceMatrix[0][0]));
//         while (!queue.empty()) {
//             Cell curr = queue.top();
//             queue.pop();

//             if (curr.difference != differenceMatrix[curr.y][curr.x])
//                 continue;

//             visited[curr.y][curr.x] = true;
//             if (curr.y == row -1 && curr.x == col - 1)
//                 return curr.difference;

//             for (const auto& direction : directions) {
//                 int nr = curr.y + direction[0];
//                 int nc = curr.x + direction[1];

//                 if (isValidCell(nr, nc) && !visited[nr][nc]) {
//                     int currDiff = abs(heights[nr][nc] - heights[curr.y][curr.x]);
//                     int maxDifference = max(currDiff, differenceMatrix[curr.y][curr.x]);
//                     if (differenceMatrix[nr][nc] > maxDifference) {
//                         differenceMatrix[nr][nc] = maxDifference;
//                         queue.push(Cell(nr, nc, maxDifference));
//                     }

//                 }
//             }

//         }

//         return differenceMatrix[row - 1][col - 1];
//     }

// };
