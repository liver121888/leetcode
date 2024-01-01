class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // for (auto x : intervals)
        //     cout << x[0] << ' | ' << x[1] << endl;
        int ans = 0;
        int prevEnd = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                ans++;
                // don't have to remove
                // intervals.erase(intervals.begin() + i);
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {                
                prevEnd = intervals[i][1];
            }            
        }

        return ans;
    }
};