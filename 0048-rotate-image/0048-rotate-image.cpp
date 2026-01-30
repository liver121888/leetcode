// matrix is always square
// we take the index i, j
// let new matrix be mat_n, old matrix is m
// m[0][0] -> mat_n[0][n-1]
// m[1][2] -> mat_n[2][2]
// m[i][j] -> mat_n[n-j][]
// we can view it as 5, 11, 16, 15 as a group
// we move it 

// n-1 = 3
// [0][0] <- [3][0] <- [3][3] <- [0][3]
// [0][1] <- [2][0] <- [2][3] <- [1][3]
// [0][2] <- [1][0] <- [1][3] <- [2][3]
// [0][3] <- [0][0] <- [0][3] <- [3][3]

// [1][1] <- [2][1] <- [2][2] <- [1][2]


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
        }
    }

    // i = 0, j = 0
    // mat[0][0], mat[2][0], mat[2][2], mat[0][2]
    // i = 1 j = 0

    // [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    // i = 0, j = 0
    // mat[0]0], mat[3][0], mat[3][3], mat[0][3]
    // i = 1 j = 0


};