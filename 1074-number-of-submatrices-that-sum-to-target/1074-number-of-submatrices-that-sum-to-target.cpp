class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefixSum(m + 1, vector<int>(n + 1, 0));

        // Calculate prefix sum
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            }
        }
        
        int ans = 0;
        // Iterate over all possible pairs of rows
        for (int top = 1; top <= m; top++) {
            for (int bottom = top; bottom <= m; bottom++) {
                unordered_map<int, int> counts;
                counts[0] = 1;

                for (int c = 1; c <= n; c++) {
                    int curSum = prefixSum[bottom][c] - prefixSum[top - 1][c];

                    // Check if the difference needed to reach the target exists in the map
                    ans += counts[curSum - target];

                    // Increment the count of current sum in the map
                    counts[curSum]++;
                }
            }
        }
        return ans;        
    }
};