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

    struct Cell {
        int y, x;
        int difference;
        Cell(int y, int x, int difference) : y(y), x(x), difference(difference) {}
    };

    // Compare 的語意是：comp(a, b) == true 表示 a 的優先級比 b 低（a 應該排在 b 後面）。而非次序！
    struct Cmp {
        bool operator()(const Cell& a, const Cell& b) const {
            return a.difference > b.difference;
        }

    };

    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    bool isValidCell(int y, int x) {
        return x >= 0 && x <= col - 1 && y >= 0 && y <= row - 1;
    }

    int row, col;

    int minimumEffortPath(vector<vector<int>>& heights) {

        row = heights.size();
        col = heights[0].size();

        vector<vector<int>> differenceMatrix(row, vector<int>(col, INT_MAX));
        priority_queue<Cell, vector<Cell>, Cmp>queue;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        differenceMatrix[0][0] = 0;
        queue.push(Cell(0, 0, differenceMatrix[0][0]));
        while (!queue.empty()) {
            Cell curr = queue.top();
            queue.pop();

            if (curr.difference != differenceMatrix[curr.y][curr.x])
                continue;

            visited[curr.y][curr.x] = true;
            if (curr.y == row -1 && curr.x == col - 1)
                return curr.difference;

            for (const auto& direction : directions) {
                int nr = curr.y + direction[0];
                int nc = curr.x + direction[1];

                if (isValidCell(nr, nc) && !visited[nr][nc]) {
                    int currDiff = abs(heights[nr][nc] - heights[curr.y][curr.x]);
                    int maxDifference = max(currDiff, differenceMatrix[curr.y][curr.x]);
                    if (differenceMatrix[nr][nc] > maxDifference) {
                        differenceMatrix[nr][nc] = maxDifference;
                        queue.push(Cell(nr, nc, maxDifference));
                    }

                }
            }

        }

        return differenceMatrix[row - 1][col - 1];
    }

};
