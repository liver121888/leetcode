class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        // curStep 0 -> n-2
        // cur layer

        // 0 0 -> 0 n-1
        // 0 n-1 -> n-1 n-1
        // n-1 n-1 -> n-1 0
        // n-1 0 -> 0 0

        // 0 1 -> 1 n-1
        // 1 n-1 -> n-1 1
        // n-1 1 -> 1 0
        // 1 0 -> 0 1

        // 1 1

        int n = matrix.size();

        for (int i = 0; i < (n + 1)/2; i++) {
            for ( int j = 0; j < n/2; j++) {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }

        // curLayer = 0, curStep = 0, n = 3
        // n/2 = 1, n-1 = 2
        // z = 1
        // (2, 0) = 7
        // (2, 2) = 9
        // (0, 2) = 3
        // 7 2 1
        // 4 5 6
        // 9 8 3

        // curLayer = 0, curStep = 1, n = 3
        // n/2 = 1, n-1 = 2
        // z = 2
        // (2, 1) = 7
        // (2, 2) = 9
        // (0, 2) = 3
        // 7 2 1
        // 4 5 6
        // 9 8 3





    }
};