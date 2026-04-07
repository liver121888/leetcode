
// 從某個點開始
// 每次拿最小 cost 的點
// 如果這點已經在 MST，跳過
// 如果不在，把它加入 MST，然後把鄰邊丟進 pq


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        minDist[0] = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            inMST[u] = true;
            ans += minDist[u];

            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int d = abs(points[u][0] - points[v][0]) +
                            abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], d);
                }
            }
        }

        return ans;
    }
};



