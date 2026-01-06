// we can model this question as graph
// every prerequsite is an directional edge
// 



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adjLists(numCourses);
        vector<int> indegree(numCourses);

        for (auto pre : prerequisites) {
            adjLists[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        // find 0 in-degree course, it means that we can directly take it
        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int nodesVisited = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            nodesVisited++;
            for (auto& neighbor : adjLists[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return nodesVisited == numCourses;
        
    }
};