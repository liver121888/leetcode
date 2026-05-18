
// brute force
// check each car pair wise
// O(n^2)

// 1
// 1
// 12
// 7
// 3

// we sort the position
// and see the arrival time
// O(NlogN)
// O(N)
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size();
        vector<pair<int, double>> pts(n);
        for (int i = 0; i < n; ++i) {
            // calculate the time for each car to reach the target
            double t = 1.0 * (target - position[i]) / speed[i];
            pts[i] = {position[i], t};
        }

        // sort by position
        sort(pts.begin(), pts.end());


        // 0,12 3,3 5,7 8,1 10,1

        int fleets = 0;
        double currFleetTime = 0;

        for (int i = n - 1; i >= 0; i--) {
            double time = pts[i].second;

            if (time > currFleetTime) {
                // if pts[i] arrives sooner, it can't be caught
                // so cnt it as a group
                fleets++;
                currFleetTime = time;
            }
        }

        return fleets;
    }
};