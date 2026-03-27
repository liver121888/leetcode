// class Solution {
// public:
//     vector<int> spiralOrder(vector<vector<int>>& matrix) {

//         int m = matrix.size();
//         int n = matrix[0].size();

//         int direction = 1;
//         int i = 0, j = -1;

//         vector<int> ans;

//         // two patterns
//         // move to the right
//         // then move down
//         // then move to left
//         // then move up
//         // we keep shrinking the traverse range

//         while (m*n > 0) {
//             for (int k = 0; k < n; k++) {
//                 j += direction;

//                 cout << i << " " << j << endl;
//                 ans.push_back(matrix[i][j]);
//             }
//             // we traverse a row, so when we go down we cannot travere m
//             m -= 1;
//             for (int k = 0; k < m; k++) {
//                 i += direction;
//                 cout << i << " " << j << endl;
//                 ans.push_back(matrix[i][j]);
//             }
//             n -= 1;
//             direction *=-1;
//         }
//         return ans;


//     }
// };


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;


        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        // mark visit in place
        const int v = 101;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        pair<int,int> pose = {0, 0};

        int i = 0;
        ans.push_back(matrix[pose.first][pose.second]);
        matrix[pose.first][pose.second] = v;

        while (true) {
            int nextRow = pose.first + dir[i].first;
            int nextCol = pose.second + dir[i].second;

            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && 
                matrix[nextRow][nextCol] != v) {

                pose.first = nextRow;
                pose.second = nextCol;
                ans.push_back(matrix[pose.first][pose.second]);
                matrix[pose.first][pose.second] = v;
            } else {
                i = (i + 1) % 4;
            }

            // Break when all elements are visited
            // need to have this otherwise it will keep looping
            if (ans.size() == m * n)
                break; 
        }

        return ans;
        
    }        
};