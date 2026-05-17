// Return the minimum possible value for maximum distance 
// between any two points by removing exactly one point.

// so we will have n*n distance
// maximum distance will be the minimum

// Input: points = [[3,10],[5,15],[10,2],[4,4]]
// Output: 12

// 7 15 7 18 12 8
//0,1
//0,2
//0,3
//1,2
//1,3
//3,4

// brute force
// remove each element n
// chekc the maximum n
// so n*2

// do we have to always remove the one that cause the maximum distance
// that can gurantee we will be smaller in the maximum distance
// 1,2 so we either remove 1 or remove 2
// but if you think about maybe multiple maxDist
// after the removal we chekc the minimum one then we get the ans
// O(2*n)
// can we make it faster to be log n?
// use a list and related the value using a unorder map and binary search on it


// the Manhattan distance between two points [xi, yi] and [xj, yj] is  max({xi - xj + yi - yj, xi - xj - yi + yj, - xi + xj + yi - yj, - xi + xj - yi + yj}).
// if we view xi - yi, xi + yi


// class Solution {
// public:

//     // int mDist(const vector<int>& a, const vector<int>& b) {
//     //     return abs(a[0]-b[0]) + abs(a[1] - b[1]);
//     // }

//     int minimumDistance(vector<vector<int>>& points) {

//         // int n = points.size();
//         // // total c n takes 2 pair
//         // int pairSize = n * (n-1)/2;

//         // // calculate point2point manhattan dist
//         // vector<tuple<int,int,int>> mDists(pairSize, 0);
//         // int k = 0;
//         // for (int i = 0; i < points.size(); i++) {
//         //     for (int j = i+1; j < points.size(); j++) {
//         //         mDists[k] = {mDist(points[i], points[j]), i, j};
//         //         k++;
//         //     }
//         // }

//         // // sort mDists
//         // sort(mDists.begin(), mDists.end())



        
//     }
// };

class Solution {
private:
    int manhattan(vector<vector<int>>& points, int i, int j) {
        return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
    }
    
    pair<int, int> maxManhattanDistance(vector<vector<int>>& points, int remove = -1) {
        int n = points.size();
        int maxSum = INT_MIN, minSum = INT_MAX, maxDiff = INT_MIN, minDiff = INT_MAX;
        int maxSumIndex, minSumIndex, maxDiffIndex, minDiffIndex;
        for (int i = 0; i < n; i++) {
            if (i != remove) {
                int sum = points[i][0] + points[i][1],
                    diff = points[i][0] - points[i][1];
                if (sum > maxSum) {
                    maxSumIndex = i;
                    maxSum = sum;
                }
                if (sum < minSum) {
                    minSumIndex = i;
                    minSum = sum;
                }
                if (diff > maxDiff) {
                    maxDiffIndex = i;
                    maxDiff = diff;
                }
                if (diff < minDiff) {
                    minDiffIndex = i;
                    minDiff = diff;
                }
            }
        }
        return max(maxSum - minSum, maxDiff - minDiff) == maxSum - minSum
            ? make_pair(maxSumIndex, minSumIndex)
            : make_pair(maxDiffIndex, minDiffIndex);
    }
    
public:
    int minimumDistance(vector<vector<int>>& points) {
        auto [mi, mj] = maxManhattanDistance(points);
        auto [mi1, mj1] = maxManhattanDistance(points, mi); // remove mi
        auto [mi2, mj2] = maxManhattanDistance(points, mj); // remove mj
        return min(
            manhattan(points, mi1, mj1),
            manhattan(points, mi2, mj2)
        );
    }
};