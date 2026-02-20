// we don't know which line we are gonna choose
// the inputs are int
// we can get a line from any two points
// brute-force: O(n^2 * n), get evey line, check evey point
// y = ax+b
// input every point
// 1 = a+b X
// 2 = 3a+b O
// 3 = 5a+b X
// 1 = 4a+b O
// 3 = 2a+b O
// 4 = a+b O

// the change in a is the same
// 


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1) {
            return 1;
        }
        int result = 2;
        for (int i = 0; i < n; i++) {

            // angle, freq
            unordered_map<double, int> cnt;
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    double angle = atan2(points[j][1] - points[i][1], 
                        points[j][0] - points[i][0]);
                    cnt[angle]++;
                }
            }

            for (auto [h, count] : cnt) {
                // add self
                result = max(result, count+1);
            }
        }

        return result;
    }
};