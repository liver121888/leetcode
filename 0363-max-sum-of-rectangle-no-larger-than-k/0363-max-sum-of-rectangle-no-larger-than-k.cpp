
// 优化解法：使用 前缀和 技术和 列压缩（压缩成一维问题）来优化，最终的时间复杂度降为 O(n^3)。

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int m = matrix.size(), n = matrix[0].size();
        int result = INT_MIN;

        // iter every possible
        // start with r1 and ends with r2
        // O(m^2)

        for (int r1 = 0; r1 < m; r1++) {

            vector<int> col_sum(n, 0);
            
            for (int r2 = r1; r2 < m; r2++) {
                // O(n) to sum up
                for (int col = 0; col < n; col++) {
                    col_sum[col] += matrix[r2][col];
                }

                // ordered set to sort the sums
                // O(nlogn) to look through possible sums
                set<int> prefix_sums;
                // always a 0 sum
                prefix_sums.insert(0);
                int curr_sum = 0;
                
                for (int sum : col_sum) {
                    curr_sum += sum;
                    // 1d subarray equal k
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