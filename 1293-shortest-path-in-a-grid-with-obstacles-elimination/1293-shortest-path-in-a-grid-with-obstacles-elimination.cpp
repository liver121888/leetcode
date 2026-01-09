#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 【優化/剪枝】：如果 k 足夠大，大到可以直接走曼哈頓距離（無視所有障礙）
        // 那最短路徑就是曼哈頓距離。這在 k 很大的情況下能極大提升性能。
        if (k >= m + n - 2) {
            return m + n - 2;
        }

        // 隊列狀態: {row, col, current_k_left}
        // 注意：我不把 steps 放進 tuple，而是用 BFS 的層級來計算，這樣更簡潔
        queue<vector<int>> q;
        q.push({0, 0, k});

        // Visited 數組：visited[row][col] = 記錄到達該點時剩餘的「最大」k
        // 初始化為 -1，表示未訪問過
        vector<vector<int>> visited(m, vector<int>(n, -1));
        visited[0][0] = k;

        int steps = 0;
        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto curr = q.front();
                q.pop();
                int r = curr[0];
                int c = curr[1];
                int cur_k = curr[2];

                // 到達終點
                if (r == m - 1 && c == n - 1) return steps;

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    // 邊界檢查
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        int next_k = cur_k - grid[nr][nc]; // 如果是障礙物(1)，k-1；否則 k 不變

                        // 【核心邏輯】：只有當 next_k 合法，且比之前到達這裡的狀態「更好」時，才加入隊列
                        // "更好" 的定義是：剩餘的消除次數更多
                        if (next_k >= 0 && next_k > visited[nr][nc]) {
                            visited[nr][nc] = next_k;
                            q.push({nr, nc, next_k});
                        }
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};