class Solution {
public:

    bool checkInterval(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int intervalNum = 0;
        int latestEnd = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            // cout << "s: " << start << ", end: " << end << endl;

            if (start >= latestEnd) {
                intervalNum += 1;
            }
            latestEnd = max(latestEnd, end);
        }
        // cout << "in: " << intervalNum << endl;
        return (intervalNum >=3);

    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        // we can check x direction first the check y direction
        // same as merge intervals

        int numRectangle = rectangles.size();

        auto xIntervals = vector<vector<int>>(numRectangle, vector<int>(2, 0));
        auto yIntervals = vector<vector<int>>(numRectangle, vector<int>(2));
        for (int i = 0; i < rectangles.size(); i++) {
            // x
            xIntervals[i][0] = rectangles[i][0];
            xIntervals[i][1] = rectangles[i][2];

            // y
            yIntervals[i][0] = rectangles[i][1];
            yIntervals[i][1] = rectangles[i][3];
        }

        cout << "x: " << checkInterval(xIntervals) << endl;
        cout << "y: " << checkInterval(yIntervals) << endl;

        return (checkInterval(xIntervals) || checkInterval(yIntervals));
    }
};