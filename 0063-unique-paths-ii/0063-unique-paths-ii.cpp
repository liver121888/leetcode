class Solution {
public:
    int m;
    int n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        //base case
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] += dp[i - 1][j] + dp[i][j - 1];  
                }                
            }
        }
        return dp[m][n];
        
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return helper(obstacleGrid, dp, m - 1, n - 1);   
    }
    
    //         int helper(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j) {
    //             if (i < 0 || i >= m || j < 0 || j >=n || obstacleGrid[i][j] == 1)
    //                 return 0;
    //             // base case
    //             if (i == 0 && j == 0)
    //                 return 1;

    //             if (dp[i][j] != -1)
    //                 return dp[i][j];

    //             int res = 0;
    //             res += helper(obstacleGrid, dp, i - 1, j);
    //             res += helper(obstacleGrid, dp, i, j - 1);
    //             return res;        
    //         }
};