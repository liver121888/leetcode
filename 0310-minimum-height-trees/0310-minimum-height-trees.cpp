class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0}; // Edge case: single node

        vector<vector<int>> adjLists(n);
        vector<int> degrees(n, 0);

        // Build Graph and calculate initial degrees
        for (auto& edge : edges) {
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }

        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                leaves.push_back(i);
            }
        }

        // Trim leaves until we reach the centroid(s)
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;

            for (int leaf : leaves) {
                for (int neighbor : adjLists[leaf]) {
                    // We simply decrement the neighbor's degree. 
                    // We don't need 'visited' because removed nodes 
                    // won't ever satisfy the (degree == 1) condition again.
                    degrees[neighbor]--;
                    
                    if (degrees[neighbor] == 1) {
                        newLeaves.push_back(neighbor);
                    }
                }
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};