
// let's say the interval are not sorted
// we first need to sort the interval by start
// then we can find where does the interval overlaps
// create an ans array does not count toward the space complexity
// if we find the intersect
// then we keep merging until no overlap
// time: O(n)
// space: O(1)

// assume intervals.size() can fit in int

// edge case size 0
// size 1

// some cases

// 1,3 6,9
// 2,5

// define non overlap
// max(start1, start2) >  min(end1, end2)
// overlap
// max(start1, start2) <=  min(end1, end2)

// [[1,3],[6,9]], newInterval = [2,5]
// i = 0, n = 2
// [1, 5], [6, 9]
// intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// 1,2, 3, 10, 12,16

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();

        // if (n == 0) {
        //     ans.push_back(newInterval);
        //     return ans;
        // }

        while (i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        // means intervals[i][1] >= newInterval[0]

        // start merging
        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        while (i < n && intervals[i][0] <= newEnd) {

            newStart = min(intervals[i][0], newStart);
            newEnd = max(intervals[i][1], newEnd);
            i++;
        }

        // means intervals[i][1] > newInterval[0]
        ans.push_back({newStart, newEnd});

        // no overlap, we simply push
        while (i < n) {
           ans.push_back(intervals[i]);
           i++;
        }

        return ans;

        
    }
};