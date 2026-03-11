
// we can dfs at every cell
// following this rule

// we can only move toward higher
// for each cell, we pick out the one that's larger
// and build it as the adj list
// and we dfs this graph
// time O(mn * mn)

// the longest path from each cell is fixed
// we can create dp, save the ans
// dp[i][j] = 1 + max(four directions) if that direction < dp[i][j]
// ans = max(dp[i][j])
// DFS + memo
// memo with 1

class Solution {
public:

    const int dirs[5] = {-1, 0, 1, 0, -1};

    int m;
    int n;

    int dfs(const vector<vector<int>>& matrix, vector<vector<int>>& memo,
            int i, int j) {

        if (memo[i][j] != 0)
            return memo[i][j];

        // 至少包含自己
        int best = 1;

        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d];
            int nj = j + dirs[d + 1];

            if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                continue;

            if (matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, memo, ni, nj));
            }
        }

        return memo[i][j] = best;


    }


    // I think it is worthy to mention that for most of this kind 
    // of questions that we could not add memorization upon a DFS. 
    // This question is a special case. Normally when you could move to 4 directions, 
    //  there would be cycle so you could not memorize the result. 
    //  However since this question is strictly increasing, thus it is a DAG.
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        m = matrix.size();
        n = matrix[0].size();

        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, memo, i, j));
            }
        }

        return ans;
        
    }
};