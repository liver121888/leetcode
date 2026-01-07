// we need to return the ordering
// we can return any valid sequence
// so we return by layer (indegree)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        // build adj list
        vector<vector<int>> adjLists(numCourses);
        // calculate in-degrees
        vector<int> indegrees(numCourses);

        for (auto prerequisite : prerequisites) {
            adjLists[prerequisite[1]].push_back(prerequisite[0]);
            indegrees[prerequisite[0]]++;
        }

        queue<int> bfs;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0)
                bfs.push(i);
        }


        vector<int> order;
        while(!bfs.empty()) {

            int c = bfs.front();
            bfs.pop();

            // c is gurantee to be 0 indegree
            order.push_back(c);

            for (auto neighbor : adjLists[c]) {
                indegrees[neighbor]--;
                if (indegrees[neighbor] == 0)
                    bfs.push(neighbor);
            }
        }

        return order.size() == numCourses ? order : vector<int>();
        
    }
};