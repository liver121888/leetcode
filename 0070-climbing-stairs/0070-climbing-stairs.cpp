class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, dp);
    }
    
    
    int dfs(int n, vector<int>& dp) {
        if (n == 0) {
            dp[0] = 1;
            return 1;
        }
        
        if (dp[n] != -1)
            return dp[n];
        
        int res = 0;
        if (n - 1 >= 0)
            res += dfs(n - 1, dp);
        if (n - 2 >= 0)
            res += dfs(n - 2, dp);
        
        dp[n] = res;
        
        return res;
        
    }
};