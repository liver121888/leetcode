// Example 1:
// Input: points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
// Output: 3
// Explanation: The shaded region represents your field of view. All points can be made visible in your field of view, including [3,3] even though [2,2] is in front and in the same line of sight.

// Example 2:
// Input: points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
// Output: 4
// Explanation: All points can be made visible in your field of view, including the one at your location.


// Input: points = [[1,0],[2,1]], angle = 13, location = [1,1]
// Output: 1
// Explanation: You can only see one of the two points, as shown above.


// we calculate the arctan2 of each point to us
// sort the angles
// we can use a sliding window, the l and r should not > fov

// O(nlogn)
// O(n)

// (0, 0)
// (-1, -1)

// -1, -1 b - a

// 0, 0 0, 0
// if we see xDiff = 0 and yDiff = 0
// we inc our ans

// points =
// [[0,0],[0,2]]
// angle =
// 90
// location =
// [1,1]

// 這就是典型的「角度是環」問題：你沒處理跨越 -180/180（或 0/360）邊界的窗口。

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {

        // cout << atan2(-1,-1)* 180 / M_PI << " " << atan2(-1,1)* 180 / M_PI << endl;

        //  -135 -45

        int ans = 0;
        vector<double> angles;
        for (const auto& point : points) {
            int xDiff = point[0] - location[0];
            int yDiff = point[1] - location[1];
            if (xDiff == 0 && yDiff == 0) {
                ans++;
                continue;
            }
            double thetaRad = atan2(yDiff, xDiff);
            double deg = thetaRad * 180 / M_PI;
            if (deg < 0) 
                deg += 360.0; // normalize to [0, 360)
            angles.push_back(deg);
        }

        // sort the angles
        sort(angles.begin(), angles.end());

        int n = angles.size();

        // angles = [0 270]
        // cout << angles.size() << endl;
        // angle = 13

        // extend angles to handle wrap-around
        // 這裡是處理0度
        // 例如 359和1度，如果直接相減會以為看不到
        // 但其實可以同時看到
        vector<double> ext = angles;
        ext.reserve(2 * n);
        for (int i = 0; i < n; i++) 
            ext.push_back(angles[i] + 360.0);

        int best = 0;
        int l = 0;
        const double EPS = 1e-9; // avoid floating edge issues

        // sliding window to find the longest subarray
        for (int r = 0; r < (int)ext.size(); r++) {
            while (ext[r] - ext[l] > (double)angle + EPS)
                l++;
            // can't take more than n original points
            // 同樣是 r-l +1, min(r - l + 1, n)限制了不可能超過n
            // 因為最多就是整個array了所以這裡的min是合法的
            best = max(best, min(r - l + 1, n));
        }

        return ans + best;
    }
};
