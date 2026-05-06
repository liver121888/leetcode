
// the box grid only shows obstacle, stone, free space
// is the size of the grid can fit in int?
// yes
// stationary obstacles is for sure
// row -> column
// we can process row by row
// edge cases
// empty box, assume we won't have empty box

// for j from 0 to n
// counts the num of stones
// if we met a stationary obs, we conlcue counting
// then we filled the stones backward
// O(m*n*n), back fill might take n
// O(1)

// #, _, *,_
// vector<stirng>
// "1", ""
// 此作法太複雜了，下面使用two pointers的作法才是最乾淨的
// class Solution {
// public:

//     // Input: boxGrid = [["#",".","#"]
//     // m = 1
//     // n = 3
//     // stoneCnt = 2


//     vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

//         int m = boxGrid.size();
//         int n = boxGrid[0].size();
//         vector<vector<char>> ans =vector<vector<char>>(n, vector<char>(m, '.'));

//         // start traverse the boxGrid
//         // i,j -> j, n-i / 1,2 -> 2,0
//         for (int i = 0; i < m; i++) {
//             int stoneCnt = 0;
//             for (int j = 0; j < n; j++) {
//                 if (boxGrid[i][j] == '#') {
//                     stoneCnt += 1;
//                 } else if (boxGrid[i][j] == '*'){
//                     ans[j][m-1-i] = '*';
//                     // back fill stone cnt will cost a lot of time
//                     int k = j;
//                     while (stoneCnt) {
//                         ans[k-stoneCnt][m-1-i] = '#';
//                         stoneCnt--;
//                     }
//                 }
//             }
//             int k = n;
//             // cout << stoneCnt << " " << k << endl;
//             // clear unfinish stoneCnt
//             while (stoneCnt) {
//                 ans[k-stoneCnt][m-1-i] = '#';
//                 stoneCnt--;
//             }
//         }
        
//         return ans;
//     }
// };


// rotate first then two pointers so we don't need back fill
// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         int m = box.size();
//         int n = box[0].size();
//         vector<vector<char>> result(n, vector<char>(m));

//         // Create the transpose of the input grid in `result`
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 result[i][j] = box[j][i];
//             }
//         }

//         // Reverse each row in the transpose grid to complete the 90° rotation
//         for (int i = 0; i < n; i++) {
//             reverse(result[i].begin(), result[i].end());
//         }

//         // Apply gravity to let stones fall to the lowest possible empty cell in
//         // each column
//         for (int j = 0; j < m; j++) {
//             int lowestRowWithEmptyCell = n - 1;
//             // Process each cell in column `j` from bottom to top
//             for (int i = n - 1; i >= 0; i--) {
//                 // Found a stone - let it fall to the lowest empty cell
//                 if (result[i][j] == '#') {
//                     result[i][j] = '.';
//                     result[lowestRowWithEmptyCell][j] = '#';
//                     lowestRowWithEmptyCell--;
//                 }
//                 // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
//                 // directly above it
//                 if (result[i][j] == '*') {
//                     lowestRowWithEmptyCell = i - 1;
//                 }
//             }
//         }
//         return result;
//     }
// };

// directly assign
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> result(n, vector<char>(m, '.'));

        // Apply gravity to let stones fall to the lowest possible empty cell in
        // each column
        for (int i = 0; i < m; i++) {
            int lowestRowWithEmptyCell = n - 1;
            // Process each cell in row `i` in reversed order
            for (int j = n - 1; j >= 0; j--) {
                // Found a stone - let it fall to the lowest empty cell
                if (box[i][j] == '#') {
                    // Place it in the correct position in the rotated grid
                    result[lowestRowWithEmptyCell][m - i - 1] = '#';
                    // (Optional - already initialized to '.') result[j][m - i -
                    // 1] = '.';
                    lowestRowWithEmptyCell--;
                }
                // Found an obstacle - reset `lowestRowWithEmptyCell` to the row
                // directly above it
                if (box[i][j] == '*') {
                    // Place the obstacle in the correct position in the rotated
                    // grid
                    result[j][m - i - 1] = '*';
                    lowestRowWithEmptyCell = j - 1;
                }
            }
        }
        return result;
    }
};
