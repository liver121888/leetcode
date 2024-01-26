class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return dfs(dp, coins, 0, 0);
    }
    
    int dfs(vector<vector<int>>& dp, vector<int>& coins, int i, int j) {       
        // how many ways to sum up to zero? Always 1
        if (j == dp[0].size() - 1)
            return 1;
        
        if (j > dp[0].size() - 1)
            return 0;
        
        if (i == coins.size())
            // out of bound
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        
        dp[i][j] = dfs(dp, coins, i, j + coins[i]) + dfs(dp, coins, i + 1, j);        
        return dp[i][j];        
    }    
};