
// coin change i
// minimum numbers

// Return the number of combinations that make up that amount. 
// dp[i] = the ways to make up that amount
// dp[i] = sum (for j in range coins dp[i - coins[j]])

// base case: 1 way to make amount 0

// The answer is guaranteed to fit into a signed 32-bit integer.
// so we don't need a long long

//  amount = 5, coins = [1,2,5]
// dp 1 0 0 0 0 0
// dp 1 1 0 0 0 0
// dp 1 1 2 0 0 0
// dp 1 1 2 2 0 0
// dp 1 1 2 2 3 4
// 

using ull = unsigned long long;

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n = coins.size();
        vector<ull> dp(amount+1, 0);
        // base case, one way to get amount 0
        dp[0] = 1;

        // 外層先枚舉 coin，內層再枚舉 amount。
        // 這樣就會保證：
        // 1 + 2 + 2
        // 2 + 1 + 2
        // 2 + 2 + 1
        // 這些不同順序，只會被算成 同一種組合。

        // for (int i = 1; i <= amount; i++) {
        //     // try every coin, the way we try is important
        //     // we don't want eg 3
        //     // 2 + 1
        //     // 1 + 2 to be count twice
        //     // we can use unorder map to save the numbers we used
        //     // 
        //     for (int j = 0; j < n; j++) {
        //         if (i - coins[j] >= 0)
        //             dp[i] += dp[i - coins[j]];
        //     }
        // }

        // 外圈 iter coins就確保了不會重複
        // 意義是現在能用這些coins你能用幾種方式湊出amount
        for (int j = 0; j < n; j++) {
            // amount至少從coins[j]開始
            for (int i = coins[j]; i <= amount; i++) {
                dp[i] += dp[i - coins[j]];
            }
        }

        return (int) dp[amount];
    }

};