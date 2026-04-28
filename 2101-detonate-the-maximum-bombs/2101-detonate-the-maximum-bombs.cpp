
// brute force, try every bomb, so we then check for the points inside the radius
// then we can bfs or dfs on the bombs
// O(n*n)

// like a directed edge (0 can bomb 2 but 2 cannot bomb 0)
// 0 -> 1,2
// 1 -> []
// 2 -> 3
// 4 -> []

class Solution {
public:

    int dfs(const vector<vector<int>>& bombs, vector<bool>& visited, int start) {

        visited[start] = true;
        int cnt = 1;

        // check all bombs
        for (int i = 0; i < bombs.size(); i++) {
            int xStart = bombs[start][0], yStart = bombs[start][1], rStart = bombs[start][2];
            int xi = bombs[i][0], yi = bombs[i][1];

            if (!visited[i] && 
                (long long)rStart * rStart >= (long long)(xi - xStart) * (xi - xStart) +
                (long long)(yi - yStart) * (yi - yStart)) {
                cnt += dfs(bombs, visited, i);
            }
        }        
        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        for (int i = 0; i < bombs.size(); i++) {
            vector<bool> visited(n, false);
            ans = max(ans, dfs(bombs, visited, i));
        }
        
        return ans;
        
    }
};