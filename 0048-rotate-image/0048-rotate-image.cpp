// an n x n 2D matrix
// always square
// we have two way to rotate
// one way to do this is to do rotation on group of 4
// another way is to transpose then mirror vertically

class Solution {
public:

    // n = 2
    // diag = 1
    // i = 0
    // j = 0

    // i = 1
    // j = 1

    // transpose
    // void transpose(vector<vector<int>> & matrix) {

    //     int n = matrix.size();
    //     // diag traverse
    //     // main diagonal: i - j = same number
    //     // i >= diag
    //     for (int diag = 0; diag < n; diag++) {
    //         for (int i = diag; i < n; i++) {
    //             int j = i - diag;
    //             swap(matrix[i][j], matrix[j][i]);
    //         }
    //     }
    // }

    // void mirrorVertical(vector<vector<int>> & matrix) {
    //     int n = matrix.size();
    //     int l = 0;
    //     int r = n - 1;
    //     while (l < r) {
    //         for (int i = 0; i < n; i++) {
    //             swap(matrix[i][l], matrix[i][r]);
    //         }
    //         l++;
    //         r--;
    //     }
    // }

    // void rotate(vector<vector<int>>& matrix) {
    //     transpose(matrix);
    //     mirrorVertical(matrix);        
    // }


    // four in a group
    // 1 3 9 7
    // 0,0 0,n-1 n-1,n-1 n-1,0

    // 2 6 8 4
    // 0,1 1,n-1 n-1,n-2 n-2,0

    void rotate(vector<vector<int>>& matrix) {

        // n = 4
        // i = 0
        // 3,0/3,3/0,3,0,0

        // i = 1
        // 2,1/2,2

        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }

    }



};