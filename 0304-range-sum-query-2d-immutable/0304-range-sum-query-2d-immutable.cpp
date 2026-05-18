class NumMatrix {
public:

    vector<vector<int>> dp;

    // Sum(ABCD)=Sum(OD)−Sum(OB)−Sum(OC)+Sum(OA)
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (m == 0 || n == 0)
            return;

        // init plus one to store 0
        dp = vector<vector<int>>(m+1, vector<int>(n+1));

        // instead of keeping a currSum and keep putting it
        // use the dp relation to calculate
        for (int i = 0; i < m; i++) {
            // dp[i].resize(n + 1);
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] + matrix[i][j] - dp[i][j];
            }
        }
    }


    // You must design an algorithm where sumRegion works on O(1) time complexity.
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] 
            - dp[row2 + 1][col1] + dp[row1][col1];  
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */