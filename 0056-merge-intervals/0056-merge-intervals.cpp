
// we need to find overlapping intervals
// the intervals are unsorted, it will be greate to first sort the intervals
// now we can view the intervals by pair

// [[1,3],[2,6],[8,10],[15,18]]
// we check i1 and i0
// 1. case i1[0] > i0[1]
// no overlapping
// 2. case i1[0] <= i0[1]
// then we compare i1[1] and i0[1]
// if i0[1] >= i1[1]
// create new interval i0[0] i0[1]
// else
// create new interval i0[0] i1[1]

// we only push into ans when we know there is no overlapping otherwise we keep compare

// some edge cases
// only one interval
// we simply return

class Solution {
public:

    // [[1,3],[2,6],[8,10],[15,18]]
    // a = 1, 3
    // i = 1
    // b = 2, 6


    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};