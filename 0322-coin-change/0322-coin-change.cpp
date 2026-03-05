#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
    // base caes
    // dp[i] = the min numbers to come up with this amount
    // dp[0] = 0; zero ways to come up with
    // dp[i] = min(dp[i-coin1] + 1, dp[i-coin2] + 1....) 
    int coinChange(vector<int>& coins, int amount) {
        // Memoization table initialized to impossible values
        // Space Complexity: O(amount)
        vector<int> memo(amount + 1, amount + 1);
        // base case
        memo[0] = 0;
        for (int i = 1; i < amount+1; i++) {

            for (int j = 0; j < coins.size(); j++) {
                if (i-coins[j] >= 0) {
                    memo[i] = min(memo[i], memo[i-coins[j]] + 1);
                }
            }
        }
        return memo[amount] == amount + 1 ? -1 : memo[amount];
    }
};


// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         // Memoization table initialized to -1 (representing "unvisited")
//         // Space Complexity: O(amount)
//         vector<int> memo(amount + 1, -1);
//         return dfs(coins, memo, amount);
//     }

// private:
//     // Helper function for Top-Down DP
//     // Time Complexity: O(amount * n), where n is coins count
//     int dfs(const vector<int>& coins, vector<int>& memo, int rem) {
//         // 1. Base Cases
//         if (rem < 0) return -1; // Invalid path
//         if (rem == 0) return 0; // Target reached
        
//         // 2. Check Memo
//         if (memo[rem] != -1) return memo[rem];

//         // 3. Recursive Step
//         int minCoins = INT_MAX;

//         for (int coin : coins) {
//             int res = dfs(coins, memo, rem - coin);
            
//             // If subproblem has a valid solution
//             if (res >= 0) {
//                 minCoins = min(minCoins, 1 + res);
//             }
//         }

//         // 4. Store and Return
//         // If minCoins is still INT_MAX, it means no solution was found -> store -1
//         memo[rem] = (minCoins == INT_MAX) ? -1 : minCoins;
//         return memo[rem];
//     }
// };
