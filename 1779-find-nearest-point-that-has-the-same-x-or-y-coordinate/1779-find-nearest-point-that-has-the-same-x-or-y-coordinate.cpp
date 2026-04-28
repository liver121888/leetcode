class Solution {
public:

    // check valid and check distance, and find the min index if the dist is the same
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        int n = points.size();

        int minDist = INT_MAX/2;
        int ans = -1;

        for (int i = 0; i < n; i++) {

            int px = points[i][0];
            int py = points[i][1];
            
            // valid
            if (px == x || py == y) {
                // check dist
                int currDist = abs(x - px) + abs(y - py);
                // if same dist, we don't update thus keeps
                // smallest index
                if (currDist < minDist) {
                    minDist = currDist;
                    ans = i;
                }
            }

        }

        return ans;
    }
};