// build adj list
// choose different node as root and use bfs to calculate the depth
// O(n * n)

// how can we make a tree minimum height
// select the most out degree one and make it either 
// left right root?
// how can we prove this is right?

// so in degree and out degree is same here
// we should take the most edged node
// try as root, and try as child

// we can prove that a most edged node cannot be on the second layer?

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if (n < 2) {
            vector<int> centroids;
            for (int i = 0; i < n; i++)
                centroids.push_back(i);
            return centroids;
        }

        vector<vector<int>> adjLists(n, vector<int>());
        vector<int> degrees(n, 0);
        for (auto& edge : edges) {
            adjLists[edge[0]].push_back(edge[1]);
            adjLists[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }


        // Initialize the first layer of leaves
        vector<int> leaves;
        for (int i = 0; i < n; i++)
            if (degrees[i] == 1)
                leaves.push_back(i);


        int remainingNodes = n;
        vector<bool> visited(n);
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();

            vector<int> newLeaves;

            for (auto& leaf : leaves) {
                visited[leaf] = true;

                for (auto& neighbor : adjLists[leaf]) {

                    if (!visited[neighbor]) {
                        degrees[neighbor]--;
                        // if we have a new leaf
                        if (degrees[neighbor] == 1)
                            newLeaves.push_back(neighbor);

                    }

                }

            }
            leaves = newLeaves;
        }

        return leaves;
    }
};