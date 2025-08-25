class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        // 0, 0 -> 0, 1 -> 1, 0 -> 2, 0 -> 1, 1 -> 0, 2 -> 1, 2 -> 2, 1 -> 2, 2

        vector<int> ans;
        int m = mat.size();
        int n = mat[0].size();

        vector<pair<int, int>> dirs = {{-1, 1}, {1, -1}};
        vector<pair<int, int>> spareDirs = {{0, 1}, {1, 0}};

        // when to end?
        // when both pointer points to the bound
        int i = 0, j = 0, d = 0;
        while (i != m && j != n) {
            ans.push_back(mat[i][j]);
            auto newY = i + dirs[d%2].first;
            auto newX = j + dirs[d%2].second;
            // check out of bound
            if (newY < 0 || newY >= m || newX < 0 || newX >= n) {
                newY = i + spareDirs[d%2].first;
                newX = j + spareDirs[d%2].second;
                // if still out of bound
                if (newY < 0 || newY >= m || newX < 0 || newX >= n) {
                    newY = i + spareDirs[(d%2+1)%2].first;
                    newX = j + spareDirs[(d%2+1)%2].second;
                }
                d++;
            }
            i = newY;
            j = newX;
        }

        // i, j, d = 0
        // ans 1
        // ny = -1, nx = 1 -> out
        // ny = 0, nx = 1

        // i = 0, j = 1, d = 1
        // ans 1 2
        // ny = 1, nx = 0 -> not out
        // continue

        // i = 1, j = 0
        // ans 1 2 4
        // ny = 2, nx = -1 -> out
        // newY = 2 newx = 0


        // i = 0, j = 2
        // ans = [1,2,4,7,5,3]
        // ny = -1, nx = 3
        // d = 2

        // 1 2 
        // 3 4

        // 1 2 3
        // i = 1, j = 1


        return ans;
    }
};