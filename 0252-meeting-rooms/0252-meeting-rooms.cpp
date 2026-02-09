class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {

        // check overlap in java
        // public static boolean overlap(int[] interval1, int[] interval2) {
        //     return (Math.min(interval1[1], interval2[1]) >
        //             Math.max(interval1[0], interval2[0]));
        // }

        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1])
                return false;
        }
        return true;
    }
};