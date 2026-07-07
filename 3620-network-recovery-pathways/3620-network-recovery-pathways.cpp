// no cycle
// start from 0 to n-1
// find the path that the cost does not exceed K
// its score as the minimum edge‑cost along that path.
// the largest
// we cannot open the offline nodes

// dijkstra
// k restrict validness
// cost is the min edge cost

// binary search

// bellman-ford
// sort the edges and relax
// relax at most k times

class Solution {
public:




    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        
        int n = online.size();

        int l = INT_MAX, r = 0;

        vector<vector<pair<int,int>>> adjList(n);

        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int c = edge[2];
            if (online[u] && online[v]) {
                adjList[u].push_back({v, c});
                l = min(l, c);
                r = max(r, c);
            }
        }
        // type: an function that return bool, so we use auto here
        auto check = [&](int mid) -> bool {
            vector<long long> dis(n, LLONG_MAX);
            priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                           greater<>> q;

            dis[0] = 0;
            q.push({0, 0});
            while (!q.empty()) {
                auto [d, u] = q.top();
                q.pop();

                if (d > k) {
                    return false;
                }
                if (u == n - 1) {
                    return true;
                }
                if (d > dis[u]) {
                    continue;
                }

                for (auto& [v, w] : adjList[u]) {
                    // unsafe
                    if (w < mid) {
                        continue;
                    }
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        q.push({dis[v], v});
                    }
                }
            }
            return false;
        };


        if (!check(l)) {
            return -1;
        }
        
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(mid)) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;
    }
};