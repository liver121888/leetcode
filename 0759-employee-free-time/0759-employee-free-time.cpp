/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

// Each employee ha a list of non-overlapping Intervals, and these intervals are in sorted order.
// common, positive-length free time for all employees, also in sorted order.
//  Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.

// the start and end are non-negative
// common free time
// the values and the size might be very long
// we can sort all the intervals
// [1 2] [ 1 3] [4 10] [ 5 6]
// We discard any intervals that contain inf as they aren't finite.
// the interval is [ ) not include the end
// after we sort the interval
// we check curr interval and next interval
// if no overlap, we have one freetime
// time: O(nlog(n)), where n is the number of the total number of intervals

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        
        vector<Interval> allInterval;
        for (const auto& s : schedule) {
            for (const auto& i : s) {
                allInterval.push_back(i);
            }
        }

        // sort the intervals, from small to large
        sort(allInterval.begin(), allInterval.end(), [](const Interval& a, const Interval& b) {
            if (a.start != b.start)
                return a.start < b.start;
            return a.end < b.end;
        });

        // why this won't work?
        // vector<Interval> ans;
        // for (int i = 0; i < allInterval.size() - 1; i++) {
        //     if (allInterval[i].end < allInterval[i+1].start) {
        //         ans.push_back(Interval(allInterval[i].end, allInterval[i+1].start));
        //     }
        // }

        vector<Interval> ans;

        int prevEnd = allInterval[0].end;
        for (int i = 1; i < allInterval.size(); i++) {
            // 有 gap，代表所有人都有空
            if (prevEnd < allInterval[i].start) {
                ans.push_back(Interval(prevEnd, allInterval[i].start));
            }

            // 合併 busy interval
            prevEnd = max(prevEnd, allInterval[i].end);
        }

        return ans;
        
        return ans;
    }
};