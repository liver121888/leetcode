class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //         vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        //         int ans = INT_MAX;
        //         for (int j = n - 1; j >= 0; j--) {
        //             ans = min(ans, dfs(matrix, dp, n - 1, j));
        //         }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        int ans = INT_MAX;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0)
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j == n - 1)
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                else
                    dp[i][j] = matrix[i][j] + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i - 1][j + 1]);   
                                
            }
        }

        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n - 1][j]);
        }
        
        
        return ans;
    }
    
//     int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
//         if (i < 0 || i > matrix.size() - 1 || j < 0 || j > matrix.size() - 1)
//             return INT_MAX;        
        
//         if (i == 0) {
//             dp[i][j] = matrix[i][j]; 
//             return dp[i][j];
//         }
        
//         if (dp[i][j] != INT_MAX)
//             return dp[i][j];
        
//         int firstChoice = dfs(matrix, dp, i - 1, j - 1);
//         int secondChoice = dfs(matrix, dp, i - 1, j);
//         int thirdChoice = dfs(matrix, dp, i - 1, j + 1);
        
//         dp[i][j] = matrix[i][j] + min(min(firstChoice, secondChoice), thirdChoice);
//         return dp[i][j];     
//     }  
    
    
};