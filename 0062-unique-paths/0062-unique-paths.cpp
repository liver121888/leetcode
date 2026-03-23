// in each square, robot has two choices
// either go down or go right

class Solution {
public:


    // int uniquePaths(int m, int n) {

    //     vector<vector<int>> dp(m, vector<int>(n, 0));

    //     for (int i = 0; i < m; i++)
    //         dp[i][0] = 1;
    //     for (int i = 0; i < n; i++)
    //         dp[0][i] = 1;


    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             dp[i][j] = dp[i-1][j] + dp[i][j-1];
    //         }
    //     }

    //     return dp[m-1][n-1];
    // }


    // math
    // there are h+v moves to do from start to finish, 
    // h=m−1 horizontal moves,and v=n−1 vertical ones.
    // One could choose when to move to the right,
    // i.e. to define h horizontal moves, and that will fix vertical ones.
    // Or, one could choose when to move down,
    // i.e. to define v vertical moves, and that will fix horizontal ones.
    // In other words, we're asked to compute in how many ways one could
    // choose p elements from p+k elements.

    int uniquePaths(int m, int n) {
        int total = m + n - 2;
        int choose = min(m - 1, n - 1);

        long long ans = 1;
        for (int i = 1; i <= choose; i++) {
            ans = ans * (total - choose + i) / i;
        }

        return (int)ans;
    }

};