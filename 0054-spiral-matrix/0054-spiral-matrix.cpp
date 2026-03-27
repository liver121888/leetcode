class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int direction = 1;
        int i = 0, j = -1;

        vector<int> ans;

        // two patterns
        // move to the right
        // then move down
        // then move to left
        // then move up
        // we keep shrinking the traverse range

        while (m*n > 0) {
            for (int k = 0; k < n; k++) {
                j += direction;

                cout << i << " " << j << endl;
                ans.push_back(matrix[i][j]);
            }
            // we traverse a row, so when we go down we cannot travere m
            m -= 1;
            for (int k = 0; k < m; k++) {
                i += direction;
                cout << i << " " << j << endl;
                ans.push_back(matrix[i][j]);
            }
            n -= 1;
            direction *=-1;
        }
        return ans;


    }
};