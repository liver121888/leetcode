// why this fails?
// inc idx but does not back track to previous state!

// // board[i][j] lower or upper case english
// // not a big board
// // try to make the search faster

// // we record hashmap
// // "A" (0, 0), (2, 0)
// // try different starting position
// // do dfs see if we can spell the word

// // time: O((mn)^2)
// // space: record visited for the dfs, O(mn)

// // edge cases:
// // the starting word is not in the board at the first place
// // ruled out using serach function
// // multiple starting positions
// // we check every possibilities
// // word.length > bigger than the board itself
// // early return false
// // word = "A"

// class Solution {
// public:

//     const vector<pair<int,int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
//     int n;
//     int m; 


//     // "ABCCED"

//     bool search(const vector<vector<char>>& board, string word, const vector<pair<int,int>>& positions) {

//         for (auto pos : positions) {
//             // dfs the board
//             vector<vector<bool>> visited(m, vector<bool>(n, false));
//             stack<pair<int,int>> dfs;

//             dfs.push(pos);
//             visited[pos.first][pos.second] = true;
//             int idx = 1;

//             cout << "pos: " << pos.first << " " << pos.second << endl;

//             while (!dfs.empty()) {
//                 auto coords = dfs.top();
//                 dfs.pop();


//                 if (board[coords.first][coords.second] == word[idx]) {
//                     idx++;
//                     if (idx == word.size())
//                         return true;
//                 }
                
//                 cout << "coords: " << coords.first << " " << coords.second  << " " << idx << endl;


//                 for (auto dir : dirs) {
//                     int nr = coords.first + dir.first;
//                     int nc = coords.second + dir.second;

//                     // cout << "n coords: " << nr << " " << nc << endl;

//                     if (nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc]) {
//                         // in bound
//                         visited[nr][nc] = true;
//                         dfs.push(make_pair(nr, nc));
//                     }
//                 }
//             }
//             // this pos does not work
//             // reset
//         }
//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {


//         m = board.size();
//         n = board[0].size();

//         // build the hashmap for the starting position
//         unordered_map<char, vector<pair<int,int>>> startPositions;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 startPositions[board[i][j]].push_back(make_pair(i, j));
//             }
//         }

//         // edge cases handling
//         char startChar = word[0];
//         if (startPositions.find(startChar) == startPositions.end()) {
//             return false;
//         } else {
//             if (word.size() == 1)
//                 return true;
//         }
            
//         return search(board, word, startPositions[startChar]);
        
//     }
// };



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, -1, 0, 1};

    bool dfs(vector<vector<char>>& board, int r, int c, const string& word, int k) {
        if (board[r][c] != word[k]) return false;
        if (k == (int)word.size() - 1) return true;

        char saved = board[r][c];
        board[r][c] = '#'; // mark visited in-place

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (board[nr][nc] == '#') continue;
            if (dfs(board, nr, nc, word, k + 1)) {
                board[r][c] = saved;
                return true;
            }
        }

        board[r][c] = saved; // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = (int)board.size();
        n = (int)board[0].size();
        if ((int)word.size() > m * n) return false;
        if (word.empty()) return true;

        // Frequency prune
        array<int, 128> have{}, need{};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                have[(unsigned char)board[i][j]]++;

        for (char ch : word) need[(unsigned char)ch]++;
        for (int c = 0; c < 128; c++)
            if (need[c] > have[c]) return false;

        // Optional heuristic: search from the rarer end
        if (have[(unsigned char)word.front()] > have[(unsigned char)word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
