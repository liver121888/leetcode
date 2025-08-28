class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        // index each diagonal and sort
        // how to index diagonal

        // n-1 0
        // n-2 0, 0 n-2
        // 0 0, 1 1, n-1 n-1
        // 0 n-1, 1 n-1
        // 0 n-1

        int n = grid.size();

        for (int i = 0; i < n; i++) {
            vector<int> temp;

            for (int j = 0; i + j < n; j++) {
                temp.push_back(grid[i+j][j]);
            }
            // non-increasing
            sort(temp.begin(), temp.end(), greater<int>());
            for (int j = 0; i + j < n; j++) {
                grid[i + j][j] = temp[j];
            }
        }

        for (int j = 1; j < n; j++) {
            vector<int> tmp;
            for (int i = 0; j + i < n; i++) {
                tmp.push_back(grid[i][j + i]);
            }
            sort(tmp.begin(), tmp.end());
            for (int i = 0; j + i < n; i++) {
                grid[i][j + i] = tmp[i];
            }
        }
        return grid;

    }
};