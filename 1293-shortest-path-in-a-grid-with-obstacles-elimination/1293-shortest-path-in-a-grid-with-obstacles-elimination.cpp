
// we need to bfs (x, y ,r)
// if we bfs on a same cell with higher
// remain k, then we should go for it
// from 0, 0 to m-1 n-1

// [[0,1],
// [1,1],
// [0,0]]

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        // 建立方向陣列：依序可組合出 (-1,0)上, (0,1)右, (1,0)下, (0,-1)左
        const vector<int> dirs = {-1, 0, 1, 0, -1};  

        // 【修正重點】
        // visited 陣列用來記錄抵達 (y, x) 時「所剩餘的最大 K 值」。
        // 初始化為 -1 代表該格子「尚未走訪過」（因為剩下的 k 最小為 0）。
        vector<vector<int>> visited(m, vector<int>(n, -1));

        // 建立 BFS 佇列，存放格式為：<y座標, x座標, 當前剩餘的消除次數 remainK>
        queue<tuple<int, int, int>> bfs;  
        bfs.push({0, 0, k});
        visited[0][0] = k; // 起點的剩餘 K 值為初始值 k

        int level = 0; // 記錄當前步數
        
        while (!bfs.empty()) {
            int currLevelSize = bfs.size();

            // 處理當前步數 (level) 下的所有可能節點
            while (currLevelSize--) {
                const auto [y, x, remainK] = bfs.front();
                bfs.pop();

                // 如果成功抵達右下角終點，直接回傳當前累積的步數
                if (y == m - 1 && x == n - 1) {
                    return level;
                }

                // 往四個可能方向進行探索
                for (int i = 0; i < 4; i++) {
                    int ny = y + dirs[i];
                    int nx = x + dirs[i + 1];

                    // 防呆機制：確保下一步沒有超出網格邊界
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
                        continue;
                    }

                    // 情況 1：遇到障礙物 (1)，且我們還有消除額度 (remainK > 0)
                    // 如果消除障礙物後，剩餘的 K 值大於歷史紀錄，代表這條路徑更有利，值得走！
                    if (grid[ny][nx] == 1 && remainK > 0 && visited[ny][nx] < remainK - 1) {
                        bfs.push({ny, nx, remainK - 1});
                        visited[ny][nx] = remainK - 1; // 更新歷史紀錄
                    } 
                    // 情況 2：遇到平地 (0)
                    // 如果走到平地後，剩餘的 K 值大於歷史紀錄，同樣代表這條路更優
                    else if (grid[ny][nx] == 0 && visited[ny][nx] < remainK) {
                        bfs.push({ny, nx, remainK});
                        visited[ny][nx] = remainK; // 更新歷史紀錄
                    }
                }
            }

            // 當前層級的所有節點都探索完畢，步數 +1
            level++;
        }

        // 如果佇列都清空了還是沒抵達終點，代表無法通關
        return -1;  
    }
};