class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        // find the boundary
        // O(1) space to store the min and max
        // O(n^2) time to check every if we start from 0, 0

        // maximize the difference

        // 1, 2 
        // 1, 0
        // 0, 1
        // find in x min and max and find y min and max
        // x: 0, 1
        // y: 0, 2
        // area = (1 - 0 + 1) * (2 - 0 + 1) = 6

        int m = grid.size();
        int n = grid[0].size();
        int min_y = m;
        int min_x = n;
        int max_y = 0;
        int max_x = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    min_y = min(min_y, i);
                    min_x = min(min_x, j);
                    max_y = max(max_y, i);
                    max_x = max(max_x, j);
                }

            }
        }
        return (max_y - min_y + 1) * (max_x - min_x + 1);
        
    }
};