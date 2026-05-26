
// Return the maximum score achievable without exceeding a total cost of k, 
// or -1 if no valid path exists.
// at 0, 0 try to go to m-1, n-1
// Note: If you reach the last cell but the total cost exceeds k, 
// the path is invalid.

// Example 1:
// Input: grid = [[0, 1],[2, 0]], k = 1
// Output: 2

// Example 2:
// Input: grid = [[0, 1],[1, 2]], k = 1
// Output: -1

// we assume that the grid is valid
// m >= 1, n >= 1
// there are only 0 1 2 in the grid

// [1] k = 1 -> 1
// can k be 0?
// yes

// [[0, 1],
// [2, 0]], k = 1
// bfs algorithm, within k cost
// shortest path
// not trying to reach with lowest cost, 
// try to reach with highest reward with cost in budget
// dijkstra algorithm, we can know what cells are reachable?
// in every cell we also note the max reward
// so after the dijkstra, we can see if we can reach the goal 
// and the highest reward
// time: O(mn * log(mn))
// space: O(mn) because we mark cost and reward

// cheapest flight within k stops
// Input: grid = [[0, 1],[2, 0]], k = 1
// we can only move down and right

// brutefoce try every possibilities
// c(m*n) choose n to be the move down move
// O(min(m,n)!)

// struct State {
//     int cost;
//     int reward;
//     int x;
//     int y;
// };

// struct Cmp {
//     // we want to put higher reward at front
//     // lower cost at front
//     bool opeartor(const State& a, const State& b) {
//         if (a.reward != b.reward)
//             return a.reward < b.reward;
//         return a.cost > b.cost
//     }
// };

class Solution {
public:

    // We define the state dp[i][j][c] as the maximum score 
    // achievable when reaching position (i,j) with a total 
    // cost of c.
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        // can go up to k cost
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, INT_MIN)));

        // if grid[i][j] = 0 
        // dp[i][j] = max(dp[i-1][j][c], dp[i][j-1][c])
        // if grid[i][j] = 1 
        // dp[i][j][c+1] = max(dp[i-1][j][c], dp[i][j-1][c]) + 1
        // if grid[i][j] = 2 
        // dp[i][j][c+1] = max(dp[i-1][j][c], dp[i][j-1][c]) + 2

        dp[0][0][0] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    // not reachable state
                    if (dp[i][j][c] == INT_MIN)
                        continue;
                    // go to the next cell
                    if (i + 1 < m) {
                        int val = grid[i + 1][j];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i + 1][j][c + cost] = max(dp[i + 1][j][c + cost], dp[i][j][c] + val);
                        }
                    }
                    // go to the next cell
                    if (j + 1 < n) {
                        int val = grid[i][j + 1];
                        int cost = (val == 0 ? 0 : 1);
                        if (c + cost <= k) {
                            dp[i][j + 1][c + cost] = max(dp[i][j + 1][c + cost], dp[i][j][c] + val);
                        }
                    }
                }
            }
        }
        
        int ans = INT_MIN;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }
        return ans < 0 ? -1 : ans;
    }


    // // 0: adds 0 to your score and costs 0.
    // // 1: adds 1 to your score and costs 1.
    // // 2: adds 2 to your score and costs 1. 
    
    // const unordered_map<int, pair<int,int>> val2RC = 
    //     {{0, {0, 0}}, {1, {1, 1}}, {2, {2, 1}}};

    // int maxPathScore(vector<vector<int>>& grid, int k) {

    //     int m = grid.size();
    //     int n = grid[0].size();

    //     vector<int> minCost(m*n, INT_MAX/2);
    //     // our goal is to maxReward
    //     vector<int> maxReward(m*n, 0);

    //     // accumulatedReward, accumulatedCost, x, y
    //     priority_queue<State, vector<State>, Cmp> pq;

    //     // dijkstra
    //     pq.push({val2RC[grid[0][0]].first, val2RC[grid[0][0]].second, 0, 0});
    //     minCost[0] = val2RC[grid[0][0]].second;
    //     maxReward[0] = val2RC[grid[0][0]].first;

    //     while (pq.empty()) {
    //         const auto currState = pq.front();
    //         pq.pop();

    //         if (currState.reward < maxReward[currState.y*n + currState.x])
    //             continue;

    //         int ny = currState.y + 1;
    //         int nx = currState.x + 1;

    //         if (ny < m) {
    //             int newReward = currState.reward + val2RC[grid[ny][currState.x]].first;
    //             int newCoord = ny*n+currState.x;
    //             if (newReward > maxReward[newCoord]) {
    //                 maxReward[newCoord] = newReward
    //                 pq.push({newReward, })
    //             }
    //         }
    //         if (nx < n) {
    //         }
    //     }        
    // }
};