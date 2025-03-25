class Solution {
public:

    long long dijkstra(const vector<vector<pair<int, int>>>& adjLists, unordered_set<int> targets, int s) {

        int n = adjLists.size();
        auto result = vector<long long>(n, LLONG_MAX);
        result[s] = 0;

        unordered_set<int> closed;
        // dist, id
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});

        while (!pq.empty()) {
            auto currPair = pq.top();
            pq.pop();
            long long dist = currPair.first;
            auto curr = currPair.second;

            closed.insert(curr);
            if (targets.count(curr)) {
                return result[curr];
            }

            // id, g
            for (auto& [neighbor, g] : adjLists[curr]) {

                if (!closed.count(neighbor)) {
                    if (dist + g < result[neighbor]) {
                        // we found a shorter route!
                        // update result
                        result[neighbor] = dist + g;
                    }

                    // push the current shortest path length and the id
                    pq.push({result[neighbor], neighbor});
                }

            }
        }
        return LLONG_MAX;
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
        return (minDist == LLONG_MAX) ? -1 : int(minDist);
    }
};