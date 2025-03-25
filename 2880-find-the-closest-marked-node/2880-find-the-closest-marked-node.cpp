class Solution {
public:

    int dijkstra(const vector<vector<pair<int, int>>>& adjLists, unordered_set<int> targets, int s) {

        int n = adjLists.size();
        auto result = vector<int>(n, INT_MAX);
        result[s] = 0;

        // can removed a closed set because result act like one!
        // unordered_set<int> closed;
        // dist, id
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto currPair = pq.top();
            pq.pop();
            int dist = currPair.first;
            auto curr = currPair.second;

            if (targets.count(curr)) {
                return result[curr];
            }

            // id, g
            for (const auto& [neighbor, g] : adjLists[curr]) {
                int newDist = dist + g;

                if (newDist < result[neighbor]) {
                    // we found a shorter route!
                    // update result
                    result[neighbor] = newDist;
                    // push the current shortest path length and the id
                    pq.push({result[neighbor], neighbor});
                }

            }
        }
        return INT_MAX;
    }

    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {

        // repeated edges!
        // directed weighted!

        unordered_set<int> targets(marked.begin(), marked.end());

        auto adjLists = vector<vector<pair<int, int>>>(n, vector<pair<int,int>>());
        for (auto edge : edges) {
            adjLists[edge[0]].push_back({edge[1], edge[2]});
        }
        
        // when I finish dijkstra, I should find the minimum dist from s to all marked
        // then return the minimum dist
        auto minDist = dijkstra(adjLists, targets, s);
        return (minDist == INT_MAX) ? -1 : int(minDist);
    }
};