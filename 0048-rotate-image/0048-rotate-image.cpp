// to rotate image
// we can rotate in 4 of a groups
// 0,0, 0,2, 2,2, 2,0
// 0,1, 1,2, 2,1, 1,0
// time: O(m*n), because we traverse from 0 to n-1
// space: O(1), in-place

// we can also do a transpose first
// then mirror horizontally
// time: O(m*n) for transpose, O(m*n) for mirror
// space: O(1)

// is the matrix valid?
// yes, you can always assume that it's valid (2-dim)
// is the size of the matrix within int?
// yes

class Solution {
public:
    // 4 of a group method
    // void rotate(vector<vector<int>>& matrix) {
        
    // }

    // matrix operation method
    void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        // transpose
        for (int diag = 0; diag < m; diag++) {
            for (int i = diag; i < m; i++) {
                swap(matrix[diag][i], matrix[i][diag]);
            }
        }

        // mirror horizontally
        for (int j = 0; j < n/2; j++) {
            for (int i = 0; i < m; i++) {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }

    }

};