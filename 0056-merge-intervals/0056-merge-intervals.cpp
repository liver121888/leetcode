

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

// w = 0, t = 1
// [[1,6],[2,6],[8,10],[15,18]]
// w = 0, t = 2
// [[1,6],[2,6],[8,10],[15,18]]
// w = 1, t = 2
// [[1,6],[8,10],[8,10],[15,18]]
// w = 1, t = 3
// [[1,6],[8,10],[15,18],[15,18]]
// w = 2, t = 4
// w = 3
// [[1,6],[8,10],[15,18]

// [[1,4],[4,5]]
// [1, 5]
// w = 1
// [1, 5]

// intervals = [[1,4],[4,5]]
// Intervals [1,4] and [4,5] are considered overlapping.

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]

// sort the interval according to the start
// we can easily check if they overlap from interval[i+1][0] <= interval[i][1]
// interval[i] interval[i+1]

// we need to merge the interval
// interval[i+1][0] >= interval[i][0]
// the merged interval will start with interval[i][0]
// merged interval will have max(interval[i], interval[i+1]) as the end
// time O(nlogn)
// space O(n) -> O(1)


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int takePtr = 1;
        int writePtr = 0;
        while (takePtr < intervals.size()) {
            // check if overlap
            if (intervals[takePtr][0] <= intervals[writePtr][1]) {
               intervals[writePtr][1] = max(intervals[writePtr][1], intervals[takePtr][1]);
               // merged a interval, move the takePtr
               takePtr++;
            } else {
                writePtr++;
                intervals[writePtr][0] = intervals[takePtr][0];
                intervals[writePtr][1] = intervals[takePtr][1];
                takePtr++;
            }
        }


        // the final size of the array
        writePtr++;
        while (intervals.size() != writePtr) {
            intervals.pop_back();
        }
        
        return intervals;
    }
};