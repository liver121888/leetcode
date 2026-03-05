class Solution {
public:

    // 1 or 2 steps, how many ways to get to n from step 0
    // we want dp[n] = dp[n-1] + dp[n-2] → base case dp[0] = 0, dp[1] = 1, dp[2] = 2

    // 1 <= n <= 45
    int climbStairs(int n) {

        if (n <= 3)
            return n;

        vector<int> memo(n + 1, 0);
        // base cases
        memo[0] = 0; memo[1] = 1; memo[2] = 2;

        for (int i = 3; i <=n; i++) {
            memo[i] = memo[i-1] + memo[i-2];
        }

        return memo[n];
    }


    
    // We are given an int n, in each step, we have a choice to take one step or two step
    // This is a dynamic programming problem
    // We can first try a top down method

    // base case: n = 1, only one way (take one step)
    // n = 2, 2
    // n = 3, 3

    // dp state: stair #
    // stores: how many ways to get 
    
    // 這是另一種 Top-Down 寫法，完全符合你的直覺
    // int climbStairs(int n) {
    //     vector<int> memo(n + 1, 0);
    //     return helper(n, memo); // 從 n 開始 call
    // }

    // int helper(int i, vector<int>& memo) {
    //     if (i == 0 || i == 1) return 1; // Base case: 地板或第1階
    //     if (memo[i] > 0) return memo[i];
        
    //     // 往前看：我是從哪裡來的？
    //     memo[i] = helper(i - 1, memo) + helper(i - 2, memo);
    //     return memo[i];
    // }

    // int dfs(int s, int n, vector<int>& memo) {

    //     if (s > n)
    //         return 0;

    //     if (s == n)
    //         return 1;

    //     if (memo[s] > 0) {
    //         return memo[s];
    //     }

    //     // two options
    //     // 1: take one step to here, so we look for ans from 1 step before
    //     memo[s] = dfs(s+1, n, memo) + dfs(s+2, n, memo);

    //     return memo[s];

    // }

    // recursion with memo
    // int climbStairs(int n) {
    //     vector<int> memo(n + 1, 0);
    //     return dfs(0, n, memo); 
    // }

    // n = 3
    // dfs(2)
    // dfs(1)
    // 1
    // 1

    // dp
    // int climbStairs(int n) {
    //     if (n == 1) {
    //         return 1;
    //     }
    //     int dp[n + 1];
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for (int i = 3; i <= n; i++) {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }
    //     return dp[n];
    // }

};