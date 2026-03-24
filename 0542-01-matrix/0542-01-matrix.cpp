class Solution {
public:

    // bfs from each cell
    // if it's zero then we keep it
    // if it's one we bfs find the nearest zero
    // bfs cost O(mn) and we called it O(mn) times
    // how to optimize
    
    // we need to find the nearest zero
    // we can multi-source bfs from every zero all together
    // if we find a cell that is 1 -> set it to the current layer
    // time: O(mn) space: O(mn) for bfs

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        const int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int,int>> bfs;
        
        // 用 -1 當未訪問標記, 因為我們要寫1，可能會搞混
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0)
                    bfs.push({i, j});
                else
                    mat[i][j] = -1;
            }
        }

        // 0 -> visited
        // number changed -> visited
        // push non-visited

        int layer = 0;
        while (!bfs.empty()) {
            int currLayerSize = bfs.size();
            while (currLayerSize) {

                const auto [r, c] = bfs.front();
                bfs.pop();

                for (const auto dir : dirs) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    // if not visited
                    if (mat[nr][nc] == -1) {
                        bfs.push({nr, nc});
                        // visit and change value
                        mat[nr][nc] = layer + 1;
                    }

                }
                currLayerSize--;
            }
            layer++;
        }

        return mat;
        
    }
};

