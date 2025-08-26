class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {

        // start bfs from the gate and update the values in the room
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0)
                    q.push(make_pair(i, j));
            }
        }

        while (!q.empty()) {
            auto coords = q.front();
            q.pop();
            int r = coords.first;
            int c = coords.second;
            // cout << "r: "<< r << ", c: " << c << endl;
            for (auto dir : dirs) {
                int newR = r + dir[0];
                int newC = c + dir[1];
                // cout << "newR: "<< newR << ", newC: " << newC << endl;

                if (newR < 0 || newC < 0 || newR >= m || newC >= n)
                    continue;
                // Only step into unvisited rooms (INF)
                if (rooms[newR][newC] == INT_MAX) {
                    rooms[newR][newC] = rooms[r][c] + 1;
                    q.emplace(newR, newC);
                }
            }

        }
        
    }
};