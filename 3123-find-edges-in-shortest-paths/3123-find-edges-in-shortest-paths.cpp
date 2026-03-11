
// weighted graph
// dijkstra
// 兩次 Dijkstra，把每個點到起點 / 終點的最短距離都算出來，然後用 edge 做拼接檢查。

// 這題關鍵不是「怎麼從 Dijkstra 找 path」。
// 而是要想到這個判準：
// 點在 shortest path 上
// dist0[x] + dist1[x] == dist0[n-1]
// 邊在 shortest path 上
// dist0[u] + w + dist1[v] == dist0[n-1]
// or
// dist0[v] + w + dist1[u] == dist0[n-1]

// 兩次 Dijkstra：O((n + m) log n)
// 掃 edges：O(m)

// 總共：O((n + m) log n)

class Solution {
public:

    int n_;

    void dijkstra(const vector<vector<pair<int,int>>>& graph, 
        vector<long long>& distArray, int start) {

        priority_queue<pair<long long, int>, 
            vector<pair<long long, int>>, 
            greater<pair<long long, int>>> bfs;

        // visit start
        distArray[start] = 0;
        bfs.push({0, start});

        while (!bfs.empty()) {
            const auto [dist, id] = bfs.top();
            bfs.pop();

            if (distArray[id] != dist)
                continue;

            for (const auto [neighbor, w] : graph[id]) {
                long long newDist = dist + w;
                if (newDist < distArray[neighbor]) {
                    // update 
                    distArray[neighbor] = newDist;
                    bfs.push({newDist, neighbor});
                }
            }
        }

    }


    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {

        n_ = n;
        int m = edges.size();
        // build adj lists
        // label: 0 - n-1
        vector<vector<pair<int,int>>> adjLists(n);
        for (int i = 0; i < m; i++) {
            int a = edges[i][0]; int b = edges[i][1]; int w = edges[i][2];
            adjLists[a].push_back({b,w});
            adjLists[b].push_back({a,w});
        }

        vector<long long> distStart(n, INT_MAX);
        vector<long long> distEnd(n, INT_MAX);

        // two dijkstra
        dijkstra(adjLists, distStart, 0);
        dijkstra(adjLists, distEnd, n-1);

        // check the edge
        vector<bool> ans(m, false);
        for (int i = 0; i < m; i++) {
            int a = edges[i][0]; int b = edges[i][1]; int w = edges[i][2];
            if (distStart[a] + w + distEnd[b] == distStart[n_ - 1] || 
                distStart[b] + w + distEnd[a] == distStart[n_ - 1]) {

                ans[i] = true;

            }
        }

        return ans;
        
    }
};