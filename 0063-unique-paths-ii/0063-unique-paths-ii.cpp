class Solution {
public:
    int m;
    int n;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        // forward dp
        vector<vector<int>> dp(m, vector<int>(n));
        
        //base case
        dp[0][0] = 1;
        int top{}; int left{};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if (i - 1 < 0)
                        top = 0;
                    else
                        top = dp[i - 1][j];
                    if (j - 1 < 0)
                        left = 0;
                    else
                        left = dp[i][j - 1];
                    
                    dp[i][j] += top + left;  
                }                
            }
        }
        return dp[m - 1][n - 1];
        
        // with bottom up dfs + memo (I call this backward dp), TLE
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