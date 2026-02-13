// we first sort the array
// minimum number of intervals you need to remove
// we want to remove the minimum number

// [[1,2],[2,3],[3,4],[1,3]]

// [[1,2],[1,2],[1,2]]

// [[1,2],[2,3]]

// then check how can we remove minimum number
// when consider remove [1, 7] and [1, 8]
// we will want to remove 1, 7

// true means should be place in front
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}


class Solution {
public:


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), compare);

        int ans = 0;
        int currBack = INT_MIN;
        for (int i = 0; i < intervals.size(); i++) {

            // overlap
            if (intervals[i][0] < currBack) {
                ans++;
                // cout << i << " " << ans << " " << currBack << endl;   
            } else {
                currBack = intervals[i][1];
            }
        }
        return ans;
        
    }
};