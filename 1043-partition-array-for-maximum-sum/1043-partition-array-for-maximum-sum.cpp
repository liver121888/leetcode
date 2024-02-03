class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return dfs(dp, arr, 0, k);
        
    }
    
    int dfs(vector<int>& dp, vector<int>& arr, int i, int k) {
        // redundant, the for loop wont run
        if (i >= arr.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        
        int curMax = 0;
        int res = 0;
        for (int j = i; j < min((int)arr.size(), i + k); j++) {
            curMax = max(curMax, arr[j]);
            int windowSize = j - i + 1;
            res = max(res, dfs(dp, arr, j + 1, k) + curMax * windowSize);  
        }
        
        dp[i] = res;
        return res;
    }
};