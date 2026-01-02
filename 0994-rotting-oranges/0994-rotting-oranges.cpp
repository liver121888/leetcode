// graph problem
// bfs
// 3 states, 0, 1, 2
// there might be multiple sources of rotten 
// return minimum number of minutes
// we can bfs from non-rotten oranges at the same time
// the dist of it from the nearest rotten will be the time it goes rotten
// time complexity: O(mn) because we mark visit
// space complexity: O(mn) we need to mark visit 

// 

class Solution {
public:

    queue<vector<int>> bfs;
    vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m;
    int n;

    // state: 0 empty 1 non-rotten 2 rotten

    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int freshOranges = 0;
        int minutesElapsed = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // non-rotten
                if (grid[i][j] == 1) {
                    freshOranges++;
                } else if (grid[i][j] == 2) {
                    bfs.push({i, j});
                }
            }
        }

        // end token for one round
        bfs.push({-1,-1});

        while(!bfs.empty()) {
            auto coords = bfs.front();
            bfs.pop();

            if (coords[0] == -1) {
                minutesElapsed++;
                if (!bfs.empty())
                    bfs.push({-1,-1});
            } else {
                // check neighbors
                for (auto direction : directions) {
                    int nr = coords[0] + direction[0];
                    int nc = coords[1] + direction[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            // this orange would be contaminated
                            grid[nr][nc] = 2;
                            freshOranges--;
                            // this orange would then contaminate other oranges
                            bfs.push({nr, nc});
                        }
                    }
                }
            }
        }

        // cout << minutesElapsed << endl;

        return freshOranges == 0 ? minutesElapsed : -1;
        
    }
};