
// 优化解法：使用 前缀和 技术和 列压缩（压缩成一维问题）来优化，最终的时间复杂度降为 O(n^3)。

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MIN;

        for (int r1 = 0; r1 < m; r1++) {
            vector<int> col_sum(n, 0);
            
            for (int r2 = r1; r2 < m; r2++) {
                for (int col = 0; col < n; col++) {
                    col_sum[col] += matrix[r2][col];
                }

                set<int> prefix_sums;
                prefix_sums.insert(0);
                int curr_sum = 0;
                
                for (int sum : col_sum) {
                    curr_sum += sum;
                    auto it = prefix_sums.lower_bound(curr_sum - k);
                    if (it != prefix_sums.end()) {
                        result = max(result, curr_sum - *it);
                    }
                    prefix_sums.insert(curr_sum);
                }
            }
        }

        return result;
    }
};