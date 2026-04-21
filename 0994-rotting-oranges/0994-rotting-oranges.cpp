
// multi-source bfs

class Solution {
public:


    // we count the fresh orages
    // and push rotten orange to our bfs queue
    // every time step (bfs level) we bfs

    int orangesRotting(vector<vector<int>>& grid) {

        if (grid.size() == 0 || grid[0].size() == 0) {
            return -1;
        }

        const int dirs[5] = {-1, 0, 1, 0, -1};

        int m = grid.size();
        int n = grid[0].size(); 

        queue<pair<int,int>> bfs;
        int freshNum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    freshNum += 1;
                } else if (grid[i][j] == 2) {
                    bfs.push({i, j});
                }
            }
        }

        // no cell has a fresh orange
        // the grid is entirely empty
        // or has rotten oranges but no fresh oranges
        if (freshNum == 0)
            return 0;

        int elapseMinute = 0;
        // freshNum > 0 停止條件避免最後多算一層
        // 是一種「停止條件」
        // 只要還有擴散來源 && 還有新鮮橘子沒被感染，就繼續
        while (!bfs.empty() && freshNum > 0) {
            int currLayerSize = bfs.size();
            while (currLayerSize) {

                const auto [y, x] = bfs.front();
                bfs.pop();

                // cout << y << " " << x << " " << elapseMinute << endl;

                for (int i = 0; i < 4; i++) {
                    int ny = y + dirs[i];
                    int nx = x + dirs[i+1];

                    if (ny >= 0 && ny < m && nx >= 0 && nx < n && grid[ny][nx] == 1) {
                        // rot the orange
                        freshNum--;
                        grid[ny][nx] = 2;
                        bfs.push({ny, nx});
                    }

                }
                currLayerSize--;
            }
            elapseMinute++;
        }

        return freshNum == 0 ? elapseMinute : -1;
    }
};

