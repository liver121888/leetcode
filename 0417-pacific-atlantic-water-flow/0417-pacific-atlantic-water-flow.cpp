class Solution {
public:

    int m;
    int n;

    const vector<pair<int,int>> dirs =  {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void bfs(const vector<vector<int>>& heights, queue<pair<int,int>>& q,       
        vector<vector<bool>>& visited) {

        while (!q.empty()) {

            const auto [r, c] = q.front();
            // cout << r << " " << c << endl;
            q.pop();

            for (const auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= m || nr < 0 || nc >= n || nc < 0)
                    continue;

                if (heights[nr][nc] >= heights[r][c] && 
                    !visited[nr][nc]) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        // m x n integer matrix heights where heights[r][c] 
        // represents the height above sea level of the cell at coordinate (r, c).
        // flow to neighboring cells directly north, south, east, and west

        // if the neighboring cell's height is less than or equal 
        // to the current cell's height.
        
        // Return a 2D list of grid coordinates result where result[i] = [ri, ci] 
        // denotes that rain water can flow from cell (ri, ci) to both the 
        // Pacific and Atlantic oceans.

        // we bfs from the pacific and atlantic
        // we only bfs a cell that is larger or equal to us

        m = heights.size();
        n = heights[0].size();
        
        queue<pair<int,int>> pQ;
        queue<pair<int,int>> aQ;

        vector<vector<bool>> pVisited(m, vector<bool>(n, false));
        vector<vector<bool>> aVisited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            pQ.push({i, 0});
            pVisited[i][0] = true;
            aQ.push({i, n-1});
            aVisited[i][n-1] = true;
        }

        for (int j = 0; j < n; j++) {
            pQ.push({0, j});
            pVisited[0][j] = true;
            aQ.push({m-1, j});
            aVisited[m-1][j] = true;
        }   

        bfs(heights, pQ, pVisited);
        bfs(heights, aQ, aVisited);

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (aVisited[i][j] && pVisited[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};