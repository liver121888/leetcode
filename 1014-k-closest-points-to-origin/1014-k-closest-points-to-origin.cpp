class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // we want top k small
        // total n

        // dist, idx
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        priority_queue<pair<int, int>> maxPQ;

        for (int i = 0; i < points.size(); i++) {
            int dist = pow(points[i][0], 2) + pow(points[i][1], 2);
            // pq.push({dist, i});
            if (maxPQ.size() < k) {
                maxPQ.push({dist, i});
            } else if (dist < maxPQ.top().first) {
                maxPQ.pop();
                maxPQ.push({dist, i});
            }
        }

        vector<vector<int>> result;
        // while (k > 0) {
        //     int idx = pq.top().second;
        //     pq.pop();
        //     result.push_back(points[idx]);
        //     k--;
        // }
        while (!maxPQ.empty()) {
            int entryIndex = maxPQ.top().second;
            maxPQ.pop();
            result.push_back(points[entryIndex]);
        }
        return result;
    }
};