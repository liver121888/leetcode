class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        vector<vector<int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        int i = 0;
        vector<int> pose = {0 , 0};
        ans.push_back(matrix[0][0]);
        visited[pose[0]][pose[1]] = true;

        //         while(1) {
        //             pose[0] += dir[i][0];
        //             pose[1] += dir[i][1];

        //             if (!visited[pose[0]][pose[1]]) {
        //                 ans.push_back(matrix[pose[0]][pose[1]]);
        //                 visited[pose[0]][pose[1]] = true;
        //             } else
        //                 break;        


        //             if (pose[0] + dir[i][0] < 0 || pose[0] + dir[i][0] >= m || 
        //                 pose[1] + dir[i][1] < 0 || pose[1] + dir[i][1] >= n || 
        //                 visited[pose[0] + dir[i][0]][pose[1] + dir[i][1]]) {
        //                 i++;
        //             }

        //             if (i == 4)
        //                 i = 0;   
        //         }
        
        while (true) {
            int nextRow = pose[0] + dir[i][0];
            int nextCol = pose[1] + dir[i][1];

            if (nextRow >= 0 && nextRow < m && nextCol >= 0 && nextCol < n && !visited[nextRow][nextCol]) {
                pose[0] = nextRow;
                pose[1] = nextCol;
                ans.push_back(matrix[pose[0]][pose[1]]);
                visited[pose[0]][pose[1]] = true;
            } else {
                i = (i + 1) % 4;
            }

            if (ans.size() == m * n) break; // Break when all elements are visited
        }

        return ans;
        
    }        
};