// we can use bfs to find the connected component
// this will take O(n^2) time and O(1) space if we 
// marked visited in place

// we want a one-pass solution and only O(1) memory but 
// cannot modify the board
// one of the property we can use is that the ship 
// is either horizontal or vertical
// we can try first traverse the board, if we find an X, 
// check 4 dirs
// this is still using bfs, I think we can do is group the 
// X by row and col


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int ans = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'X') {

                    // if (r == 0)
                    //     ans++;
                    // else if (c == 0)
                    //     ans++;
                    // else if (board[r][c-1] == '.' && board[r-1][c] == '.')
                    //     ans++;
                    // 並不試選說沒有，而是選說有的情況然後union取反例
                    bool hasUp = (r > 0 && board[r-1][c] == 'X');
                    bool hasLeft = (c > 0 && board[r][c-1] == 'X');
                    if (!hasUp && !hasLeft) 
                        ans++; // head of a ship
                }   
            }
        }
        return ans;
    }

    // dry run
    // [["X",".",".","X"],
    //  [".",".",".","X"],
    //  [".",".",".","X"]]



};