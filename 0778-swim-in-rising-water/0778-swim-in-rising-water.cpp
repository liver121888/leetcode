/*

You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. 
At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. 
You can swim infinite distances in zero time. 
Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).


n x n integer matrix, start at (0, 0) -> (n-1, n-1)

grid[i][j] = 7
we can pass here after time 7


[0 0 0
 1 2 2
 3 10 0]
 t = 2


// we can bfs
// retrun the route with minimum maximum elevation
// multiple maximum elevation route
// we take the minimum

// bfs every possible route
// record maximum elevation we met with
// at the bottom right, we take the min of every maximum elevation

t -> 2

min of the grid[i][j]
max of the grid[i][j]
simulate the bfs from mid = (min + max)/2
// see if we can reach the end
// we decreasing the serach range until we find a time that is minimum time

where k is the maxvalue in the grid
O(log(k) * n^2)

dp array -> minimum time to reach here
dp[i][j] = max(min(top and the left right down), grid[i][j])


[[0,1,2,3,4],
 [24,23,22,21,5],
 [12,13,14,15,16],
 [11,17,18,19,20],
 [10,9,8,7,6]]


 [[0, 1,2 ,3,4],
 [24,,22,21,5],
 [12,13,14,15,16],
 [11,17,18,19,20],
 [10,9,8,7,6]]


[0 0 0
 1 2 2
 3 5 0]
 t = 2

 matrix -> len n
 time O(n^2)

 [8 0 0
 1 2 2
 3 5 0]

 [8 8 8
  8 8 8
  _ _  _ ]


 [4 4 0
 1 4 2
 3 4 4]


*/



#include <iostream>
#include <vector>
#include <limits>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    const vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n;

    bool bfs(const vector<vector<int>>& grid, int t) {

        if (grid[0][0] > t)
            return false;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        visited[0][0] = true;
        q.push({0,0});

        while (!q.empty()) {

            const auto [y, x] = q.front();
            q.pop();

            if (y == n - 1 && x == n - 1)
                return true;

            for (const auto& dir : dirs) {
                int ny = y + dir[0];
                int nx = x + dir[1];

                if (ny >= 0 && ny < n && nx >= 0 && nx < n && !visited[ny][nx] && grid[ny][nx] <= t) {
                    q.push({ny, nx});
                    visited[ny][nx] = true;
                }

            }

        }
        return false;
    }


    int swimInWater(vector<vector<int>>& grid) {

        n = grid.size();
        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
        }

        // [0 0 0
        //  1 2 2
        //  3 5 0]
        // 0 5 -> 2
        // r = 1
        // l = 2

        // t 1 2 3 4 5
        //   f f t t t
        // l = 1
        // r = 5
        // mid 3

        // l = 1
        // r = 3

        // l = 3
        // r = 3

        // [[0,2],[1,3]]

        // 0 3
        // 1
        // 1 3


        int l = max(grid[0][0], grid[n - 1][n - 1]), r = maxHeight;
        // binary serach the range
        while (l <= r) {
            int mid = (l + r)/2;
            // cout << mid << endl;
            // if we reach the goal
            if (bfs(grid, mid)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }


};

// int main() {

//     Solution sol = Solution();
//     sol.

//   return 0;
// }