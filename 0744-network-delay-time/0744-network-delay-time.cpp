class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // graph
        // directed graph, w/ weights
        // is there cycle? there will be cycle
        // use a visited hashset to record that
        // all edges are unique

        // build a adjacency list (graph)
        // the label starts from 1 to n (inclusive)
        vector<vector<pair<int, int>>> networkGraph = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
        for (auto edge : times) {
                auto s = edge[0];
                auto target = edge[1];
                auto time = edge[2];
                networkGraph[s].push_back(make_pair(target, time));
        }

        // start from k
        // w <= 100
        // it's broadcasting, so we just have to find the largest delayTime in the array
        vector<int> delayTime = vector<int>(n + 1, INT_MAX);

        // filled dummy node with 0
        delayTime[0] = 0;

        // traverse
        queue<int> bfsQ;
        bfsQ.push(k);
        delayTime[k] = 0;

        // bfs, dijkstra
        while (!bfsQ.empty()) {

            // poll out the top priority node
            auto id = bfsQ.front();
            auto neighbors = networkGraph[id];
            bfsQ.pop();

            for (auto neighbor_w : neighbors) {
                auto neighbor = neighbor_w.first;
                auto w = neighbor_w.second;
                // check if we found a shorter path
                if (delayTime[id] + w < delayTime[neighbor]) {
                    // update delayTime
                    delayTime[neighbor] = delayTime[id] + w;
                    bfsQ.push(neighbor);
                }
                // should we still push back if we didn't found shorter path?
                // 0 1 the shortest w is 5
                // we found a path that produce w 6
                // and current is 7
                // we don't need to because adding this will defnitely not help us find the shortest path
            }
        }

        for (auto t : delayTime) {
            // unreachable
            if (t == INT_MAX)
                return -1;
        }

        return *max_element(delayTime.begin(), delayTime.end());

    }
};