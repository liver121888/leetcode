class Solution {
public:
    
    int numRollsToTarget(int n, int k, int target) {
        vector<int> dp = vector<int>(target + 1);
        // vector<int> nextDp = vector<int>(target + 1);

        int MOD = 1e9 + 7;
        
        // base case
        dp[0] = 1;

        for (int dice = 0; dice < n; dice++) {
            vector<int> nextDp = vector<int>(target + 1);
            // fill(nextDp.begin(), nextDp.end(), 0);

            for (int val = 1; val < k + 1; val++) {
                for (int total = val; total < target + 1; total++) {
                    nextDp[total] = (nextDp[total] + dp[total - val]) % MOD;
                }
            }
            dp = nextDp;
        }
        
        return dp[target];
    }
};