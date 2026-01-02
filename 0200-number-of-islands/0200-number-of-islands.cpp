// a grid world with either 0 or 1
// we need to find the number of islands
// a island is adjacent 1 surrounded by 0
// the boundary can be consider water

// we can use DFS method to solve this
// have a stack as the dfs stack, have a vistied 
// array to prevent repeat actions

// call dfs on every cell, if not vist then traverse all the 
// adj 1s

// time complexity: O(m*n), since we traverse each cell only once
// space complexity: O(1)


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        // traverse directions
        vector<pair<int,int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int m = grid.size();
        int n = grid[0].size();
        // visited grid
        // auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        // instead of using a visited grid, we can sunk the island (set it to 0)


        // dfs stack
        stack<pair<int,int>> dfs;
        int ans = 0;

        // call dfs on every cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // check if its a land cell
                if (grid[i][j] == '1') {

                    ans++;
                    dfs.push(make_pair(i, j));
                    // visit
                    // visited[i][j] = true;
                    grid[i][j] = 0;
                    while (!dfs.empty()) {
                        auto coords = dfs.top();
                        dfs.pop();
                        int r = coords.first;
                        int c = coords.second;
    
                        // cout << r << " " << c << endl;

                        // an not visited island, traverse
                        for (auto direction : directions) {
                            int nr = r + direction.first;
                            int nc = c + direction.second;
                            if (nr < m && nc < n && nr >= 0 && nc >= 0 && grid[nr][nc] == '1') {
                                // inbound
                                dfs.push(make_pair(nr,nc));
                                // visited[nr][nc] = true;
                                grid[nr][nc] = 0;
                            }
                        }
          
                            
                    }
                }

            }
        }

        return ans;
        
    }
};