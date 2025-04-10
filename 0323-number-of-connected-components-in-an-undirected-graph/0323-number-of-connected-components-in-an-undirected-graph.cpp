class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adjLists(n, vector<int>());

        for (auto edge : edges) {
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n);
        stack<int> dfs;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            
            dfs.push(i);

            while (!dfs.empty()) {
                int currNode = dfs.top();
                dfs.pop();
                visited[currNode] = true;

                for (auto neighbor : adjLists[currNode]) {
                    if (!visited[neighbor])
                        dfs.push(neighbor);
                }
            }

            ans++;
            // dfs must already be empty
        }
        return ans;
    }
    // i = 0
    // dfs(0)
    // 0 1 2
    // i = 1
    // i = 2
    // i = 3
    // i = 4

};