// is the interval sorted?
// any constraints on the numbers in the intervals?
// we sort the intervals by start
// check the ends
// if coverered, remove
// if not, update to new interval and keeps compare
// only need to counts
// time: O(n)
// space: O(1)

// edge cases: []
// [[0, 1]]

// intervals = [[1,4],[3,6],[2,8]]
// [[1,4], [2,8], [3,6]]

// intervals = [[1,4],[2,3]]

// [[1,4], [2,8], [3,6], [4,7]]
// 4
// 8

// [[3,10],[4,10],[5,11]]

// [[1,2],[1,4],[3,4]]

// [[1,4],[2,8],[2,9],[3,6],[3,7]]

class Solution {
  public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    // If two intervals share the same start point,
    // put the longer one to be the first.
    sort(intervals.begin(), intervals.end(),
      [](const vector<int> &o1, const vector<int> &o2) {
      return o1[0] == o2[0] ? o2[1] < o1[1] : o1[0] < o2[0];
    });

    int count = 0;
    int end, prev_end = 0;
    for (auto curr : intervals) {
      end = curr[1];
      // if current interval is not covered
      // by the previous one
      if (prev_end < end) {
        ++count;
        prev_end = end;
      }
    }
    return count;
  }
};



// class Solution {
// public:
//     int removeCoveredIntervals(vector<vector<int>>& intervals) {

//         int n = intervals.size();
//         sort(intervals.begin(), intervals.end());
//         int ans = n;
//         int currStart = intervals[0][0];
//         int currEnd = intervals[0][1];

//         for (int i = 1; i < n; i++) {
//             if (intervals[i][1] <= currEnd) {
//                 ans--;
//             } else {
//                 if (currStart == intervals[i][0]) {
//                     ans--;
//                 }
//                 currStart = intervals[i][0];
//                 currEnd = intervals[i][1];
//             }
//         }
        
//         return ans;
//     }
// };