// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// multiple source bfs?
// we find all the zeros
// and bfs on it

// queue<int> -> O(mn) space

// if we find a zero
// it's not propagation
// i.e. a newly set zero cannot set others to zero
// take i j and 

// -2^31 <= matrix[i][j] <= 2^31 - 1

class Solution {
public:

    // void helper(vector<vector<int>>& matrix, int r, int c) {


    // }

    // use the first col and row to record if certain row and col needs to be zero
    // so we need to deal with first row and col specially
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // 1. check first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // 2. check first col
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }


        // 3. check the elements
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // 4. fill in
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // 5. check if firstRow or firstCol are zero

        if (firstRowZero) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }


        if (firstColZero) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }



        // we basically shrink the boundary as we traverse
        // int leftBound = 0;
        // int rightBound = n - 1;
        // int topBound = 0;
        // int downBound = m - 1;

        // int r = topBound;
        // int c = leftBound;

        // while () {
        //     if (matrix[r][c] == 0) {
        //         // mark the whole r and c as 0
        //         // we cannot simply does this because on example one we will see
        //         // we also need to mark 0, 3 as it and mark col 3
        //         // we need a recursion for it
        //         helper()
        //     }
        // }



        
    }
};