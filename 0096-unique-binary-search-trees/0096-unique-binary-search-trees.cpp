class Solution {
public:

    int dfs(vector<int>& dp, int n) {

        // base case: one way to construct a bst with 1
        if (n <= 1)
            return 1;

        if (dp[n] != 0) {
            return dp[n];
        }

        int res = 0;
        // in every call, what are our options?
        // choose what to be the root
        // when n == 3, we should return 5 as in the example
        for (int i = 1; i <= n; i++) {
            // when i as root
            int left = dfs(dp, i - 1);
            int right = dfs(dp, n - i);
            res += left * right;
        }

        dp[n] = res;

        return res;
    }

    int numTrees(int n) {

        // constraint -> in order must be [1 2 3]
        vector<int> dp(n + 1);
        return dfs(dp, n);
    }
};