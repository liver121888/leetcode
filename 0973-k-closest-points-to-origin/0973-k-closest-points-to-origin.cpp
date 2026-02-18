// we can use a heap to solve
// k closest
// we can build min heap
// the pop k times
// also we can build a heap
// when size > k
// we pop
// so the rest will be the k closest
// time: O(nlogn)
// space: O(n)

// same for sorting the abs value
// time: O(nlogn)
// space: O(n)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        // dist, idx
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {

            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            if (maxHeap.size() < k) {
                maxHeap.push({dist, i});
                continue;
            }

            int topDist = maxHeap.top().first;
            if (dist < topDist) {
                maxHeap.push({dist, i});
            }

            if (maxHeap.size() > k) {
                maxHeap.pop();
            }


        }

        vector<vector<int>> ans;
        while (!maxHeap.empty()) {
            auto [dist, idx] = maxHeap.top();
            ans.push_back(points[idx]);
            maxHeap.pop();
        }
        return ans;
    }
};