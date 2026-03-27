
// weighted directed graph
// if we broadcast the signal
// the minimum time for all the nodes to receive
// dijkstra
// get the minimum time to go to one node
// find the max of that time, then it will be our answer
// if the are some nodes that is unreachable
// return -1

// n nodes label from 1->n
// n == 0
// return -1
// k > n k < 0 not in the graph

// time complexity
// V = n
// E = times.size()
// O(V + E), E on building the list, and V on the dijkstra
// space: O(V + E), adjLis O(E) + delayTime O(V)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        if (n == 0)
            return -1;
        if (k > n || k < 0)
            return -1;

        // 1 <= k <= n <= 100
        // 0 <= wi <= 100

        // so it's safe to use
        const int inf = 100000;

        // 1->n --> 0->n-1
        // label, w
        vector<int> delayTime(n, inf);

        vector<vector<pair<int,int>>> network(n, vector<pair<int,int>>());
        for (const auto& time : times) {
            int u = time[0] - 1;
            int v = time[1] - 1;
            int w = time[2];
            network[u].emplace_back(v, w);
        }

        // smaller delay at front
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({k-1, 0});
        delayTime[k-1] = 0;

        // dijkstra
        while(!minHeap.empty()) {

            const auto [curr, dist] = minHeap.top();
            minHeap.pop();

            if (delayTime[curr] != dist)
                continue;
            
            for (const auto [neighbor, w] : network[curr]) {

                if (dist + w < delayTime[neighbor]) {
                    delayTime[neighbor] = dist + w;
                    minHeap.push({neighbor, dist + w});
                }

            }
        }

        int maxDelay = 0;
        for (const auto& dt : delayTime) {
            if (dt == inf)
                return -1;
            maxDelay = max(maxDelay, dt);
        }

        return maxDelay;
    }
};
