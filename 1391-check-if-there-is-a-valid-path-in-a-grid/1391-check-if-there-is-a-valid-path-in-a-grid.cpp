
// // dfs on the street
// // there is only one direction
// // check if we can meet the end

// class Solution {
// public:

//     // a map of road type to it's direction
//     const unordered_map<int, vector<vector<int>>> road2dirs = {
//         {1, {{0, -1}, {0, 1}}},
//         {2, {{-1, 0}, {1, 0}}},
//         {3, {{0, -1}, {1, 0}}},
//         {4, {{1, 0}, {0, 1}}},
//         {5, {{0, -1}, {-1, 0}}},
//         {6, {{0, 1}, {-1, 0}}},
//     };

//     // two condition
//     // reachable
//     // then we dfs the other direction
//     // curr cell 可以往 next cell 走
//     // &&
//     // next cell 有一條路可以回到 curr cell

//     bool helper(const vector<vector<int>>& grid, int y, int x, int prevY, int prevX) {

//         int m = grid.size();
//         int n = grid[0].size();

//         // base case
//         if (y < 0 || y >= m || x < 0 || x >= n)
//             return false;
//         if (y == m - 1 && x == n - 1)
//             return true;

//         int roadType = grid[y][x];
//         bool result = false;
//         const auto& dirs = road2dirs.at(roadType);
//         vector<vector<int>> newCells;
//         for (const auto& dir : dirs) {
//             int ny = y + dir[0];
//             int nx = x + dir[1];
//             newCells.push_back({ny, nx});
//         }

//         // check if we can go back to the prev cell first
//         if (find(newCells.begin(), newCells.end(), {prevY, prevX}) == newCells.end())
//             return false;

//         // go to next cells
//         for (int i = 0; i < 2; i++) {

            
//         }



//             result = result || helper(grid, ny, nx, y, x);
        
//         return result;
//     }

//     bool hasValidPath(vector<vector<int>>& grid) {
//         if (grid.size() == 0 || grid[0].size() == 0)
//             return false;
//         return helper(grid, 0, 0, -1, -1); 
//     }
// };

class Solution {
public:
    vector<vector<pair<int, int>>> dirs = {
        {},                         // dummy, street type starts from 1
        {{0, -1}, {0, 1}},          // 1: left, right
        {{-1, 0}, {1, 0}},          // 2: up, down
        {{0, -1}, {1, 0}},          // 3: left, down
        {{1, 0}, {0, 1}},           // 4: down, right
        {{0, -1}, {-1, 0}},         // 5: left, up
        {{0, 1}, {-1, 0}}           // 6: right, up
    };

    bool hasDirection(int type, int dy, int dx) {
        for (auto [a, b] : dirs[type]) {
            if (a == dy && b == dx)
                return true;
        }
        return false;
    }

    bool dfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited,
             int y,
             int x) {
        
        int m = grid.size();
        int n = grid[0].size();

        if (y == m - 1 && x == n - 1)
            return true;

        visited[y][x] = true;

        int type = grid[y][x];

        for (auto [dy, dx] : dirs[type]) {
            int ny = y + dy;
            int nx = x + dx;

            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;

            if (visited[ny][nx])
                continue;

            int nextType = grid[ny][nx];

            // next cell must be able to connect back to current cell
            if (!hasDirection(nextType, -dy, -dx))
                continue;

            if (dfs(grid, visited, ny, nx))
                return true;
        }

        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        return dfs(grid, visited, 0, 0);
    }
};
