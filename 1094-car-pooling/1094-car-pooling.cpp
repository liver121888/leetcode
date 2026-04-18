

// 1 5
// 3 7

// keep an array of 1000
// so as we traverse

// or it's better to use a map to represent the segment
// 1:{2}, 3:{3}, 6:{-2}, 8:{-3}

// and then we traverse the set
// 2 -> 5 return false directly

// time: O(nlog(n)), n trips, we traverse the trip and put in the set
// space: O(n), save up to 2*n points in the set

// class Solution {
// public:

//     bool carPooling(vector<vector<int>>& trips, int capacity) {
        
//         map<int,int> segments;

//         for (const auto& trip : trips) {
//             int num = trip[0];
//             int from = trip[1];
//             int to = trip[2];
//             segments[from] += num;
//             segments[to] -= num;
//         }

//         // traverse the segments
//         int peopleNum = 0;
//         for (const auto& [stop, num] : segments) {
//             peopleNum += num;
//             if (peopleNum > capacity)
//                 return false;
//         }

//         return true;

//     }
// };

// Approach 2: Bucket Sort
// Intuition
// Note that in the problem there is a interesting constraint:
// We can use it instead of the normal sorting in this method.
// What we do is initial 1001 buckets, and put the number of passengers changed 
// in corresponding buckets, and collect the buckets one by one.

// 0 <= trips[i][1] < trips[i][2] <= 1000

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> timestamp(1001);
        for (const auto& trip : trips) {
            timestamp[trip[1]] += trip[0];
            timestamp[trip[2]] -= trip[0];
        }
        int usedCapacity = 0;
        for (int number : timestamp) {
            usedCapacity += number;
            if (usedCapacity > capacity) {
                return false;
            }
        }
        return true;
    }
};