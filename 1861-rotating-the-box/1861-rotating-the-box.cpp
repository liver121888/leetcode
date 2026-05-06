
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
// O(m*n*m), back fill might take m
// O(1)

// #, _, *,_
// vector<stirng>
// "1", ""

class Solution {
public:

    // Input: boxGrid = [["#",".","#"]
    // m = 1
    // n = 3
    // stoneCnt = 2


    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {

        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> ans =vector<vector<char>>(n, vector<char>(m, '.'));

        // start traverse the boxGrid
        // i,j -> j, n-i / 1,2 -> 2,0
        for (int i = 0; i < m; i++) {
            int stoneCnt = 0;
            for (int j = 0; j < n; j++) {
                if (boxGrid[i][j] == '#') {
                    stoneCnt += 1;
                } else if (boxGrid[i][j] == '*'){
                    ans[j][m-1-i] = '*';
                    // back fill stone cnt will cost a lot of time
                    int k = j;
                    while (stoneCnt) {
                        ans[k-stoneCnt][m-1-i] = '#';
                        stoneCnt--;
                    }
                }
            }
            int k = n;
            cout << stoneCnt << " " << k << endl;
            // clear unfinish stoneCnt
            while (stoneCnt) {
                ans[k-stoneCnt][m-1-i] = '#';
                stoneCnt--;
            }
        }
        
        return ans;
    }
};