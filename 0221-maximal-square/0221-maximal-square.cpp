// every one itself is a square
// how to exapnd while maintaing square constraint
// create dp(mn) = area number;
// dp[i][j] = dp[i][j-1] == 1 && dp[i-1][j-1] == 1 && dp[i-1][j] == 1

// 1 1 1
// 1 1 1
// 1 1 1

// set self to one but later we check the values
// 1 1 1
// 1 2 2
// 1 2 3

// 1 1 1
// 1 0 1
// 1 1 1

// 1 1 1
// 1 0 1
// 1 

// dp[i][j] the edge can be form if take this as the 
// bottom right corner

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int edge = 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i-1 >= 0 && j-1 >= 0) {
                        dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    }
                    edge = max(edge, dp[i][j]);
                }
            }
        }

        return edge * edge;
    }
};