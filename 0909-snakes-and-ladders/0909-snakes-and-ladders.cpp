
// Return the least number of dice rolls required to reach the square n^2. 
// If it is not possible to reach the square, return -1.
// so we can try multiple method to try to reach
// snake and ladder is the edge 
// we also need the least moves to reach
// we probably do it as graph problem
// these are the edge too, if we have ladder or snake
// we have one more edge
// should we build graph? no
// it's implicit
// [curr + 1, min(curr + 6, n^2)]
// dijkstra

// u only need bfs
// class Solution {
// public:
//     pair<int, int> getPos(int square, int n) {
//         int rowFromBottom = (square - 1) / n;
//         int r = n - 1 - rowFromBottom;
//         int c = (square - 1) % n;

//         // odd row from bottom goes right to left
//         if (rowFromBottom % 2 == 1) {
//             c = n - 1 - c;
//         }

//         return {r, c};
//     }

//     int snakesAndLadders(vector<vector<int>>& board) {
//         int n = board.size();
//         int target = n * n;

//         vector<int> dist(target + 1, -1);
//         queue<int> q;

//         dist[1] = 0;
//         q.push(1);

//         while (!q.empty()) {
//             int curr = q.front();
//             q.pop();

//             if (curr == target) {
//                 return dist[curr];
//             }

//             for (int dice = 1; dice <= 6; dice++) {
//                 int next = curr + dice;
//                 if (next > target) break;

//                 auto [r, c] = getPos(next, n);

//                 int dest = next;
//                 if (board[r][c] != -1) {
//                     dest = board[r][c];
//                 }

//                 if (dist[dest] == -1) {
//                     dist[dest] = dist[curr] + 1;
//                     q.push(dest);
//                 }
//             }
//         }

//         return -1;
//     }
// };

class Solution {
public:

    pair<int, int> getPos(int square, int n) {
        int rowFromBottom = (square - 1) / n;
        int r = n - 1 - rowFromBottom;
        int c = (square - 1) % n;

        // odd row from bottom goes right to left
        if (rowFromBottom % 2 == 1) {
            c = n - 1 - c;
        }

        return {r, c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        // label from 1 to n^2
        int n = board.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        vector<int> minDist(n*n+1, INT_MAX/2);
        pq.push({0,1});
        minDist[1] = 0;

        // start bfs
        while (!pq.empty()) {

            auto [dist, curr] = pq.top();
            pq.pop();

            if (dist != minDist[curr])
                continue;

            cout << dist << " " << curr << endl;


            // check indexing here
            // curr = 1 -> n-1, 0 r = 5, 
            // curr = 6 -> n-1, n-1
            // curr = 7 -> n-2, n-1 r = 4 c = 0
            // curr = 15
            // curr = 14 -> 3
            // n = 6

            auto [r, c] = getPos(curr, n);

            for (int i = 1; i <= 6; i++) {
                // in bound and not visited
                int neighbor = curr + i;
                if (neighbor <= n*n) {
                    auto [nr, nc] = getPos(neighbor, n);
                    // must take the ladder or the snake
                    if (board[nr][nc] != -1)
                        neighbor = board[nr][nc];

                    if (dist + 1 < minDist[neighbor]) {
                        minDist[neighbor] = dist + 1;
                        pq.push({minDist[neighbor], neighbor});
                    }
                }

            }


            // int teleport = board[r][c];
            // if (teleport != -1) {

            // } else {

            // }
        }

        return minDist[n*n] == INT_MAX/2 ? -1 : minDist[n*n];
    }
};