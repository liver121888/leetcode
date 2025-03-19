// class Solution {
// public:
//     int dfs(const vector<int>& coins, vector<int>& dp, int amount) {
//         if (amount == 0) return 0;
//         if (amount < 0) return -1;
//         if (dp[amount] != -1) return dp[amount];

//         int minDepth = INT_MAX;
//         for (int coin : coins) {
//             int res = dfs(coins, dp, amount - coin);
//             if (res >= 0 && res < minDepth) {
//                 minDepth = 1 + res;
//             }
//         }

//         dp[amount] = (minDepth == INT_MAX) ? -1 : minDepth;
//         return dp[amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         if (amount == 0) return 0;
//         vector<int> dp(amount + 1, -1);
//         return dfs(coins, dp, amount);
//     }
// };


// class Solution {
// public:
//     int dfs(const vector<int>& coins, vector<int>& dp, int amount) {
//         if (amount == 0) return 0;
//         if (amount < 0) return -1;
//         if (dp[amount] != -1) return dp[amount];

//         int minDepth = INT_MAX;
//         for (int coin : coins) {
//             int res = dfs(coins, dp, amount - coin);
//             if (res >= 0 && res < minDepth) {
//                 minDepth = 1 + res;
//             }
//         }

//         dp[amount] = (minDepth == INT_MAX) ? -1 : minDepth;
//         return dp[amount];
//     }

//     int coinChange(vector<int>& coins, int amount) {
//         if (amount == 0) return 0;
//         vector<int> dp(amount + 1, -1);
//         return dfs(coins, dp, amount);
//     }
// };



class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int max = amount + 1;
            auto dp = vector<int>(amount + 1, max);
            dp[0] = 0;
            for (int i = 1; i <= amount; i++) {
                for (int j = 0; j < coins.size(); j++) {
                    if (coins[j] <= i) {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
            return dp[amount] > amount ? -1 : dp[amount];
    }
};