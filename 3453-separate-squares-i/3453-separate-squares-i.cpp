// might be multiple squares
// the ans is a double
// what's the area of a square?
// l^2
// a line will separate it as multiple triangle
// how do we represent the area above as a 
// equation and the area below as a equation

// for a square
// x, y, l
// [x, y], [x+l, y], [x, y+l], [x + l, y+l]

// I think we can try binary search
// find min, max, cal mid, calculate the area
// if any part is larger
// we move the line
// when do we want to end?

// we found two int
// 1 and 2 for example 1

// we calculate each square

// think of WHAT'S not changing here!
// the total square area is not changing
//  Let the area of squares below y be area_y

// class Solution {
// public:
//     double total_area = 0;

//     bool check(const vector<vector<int>>& squares, double limit_y) {
//         double area = 0;
//         for (auto& sq : squares) {
//             int y = sq[1], l = sq[2];
//             // only calculate the area below limit
//             if (y < limit_y) {
//                 area += l * min(limit_y - y, (double)l);
//             }

//         }
//         return area >= total_area / 2;
//     }

//     double separateSquares(vector<vector<int>>& squares) {

//         double max_y = 0;
//         for (auto& sq : squares) {
//             int y = sq[1], l = sq[2];
//             total_area += (double)l * l;
//             max_y = max(max_y, (double)(y + l));
//         }

//         double lo = 0;
//         double hi = max_y;
//         double eps = 1e-5;
//         while(abs(hi-lo) > eps) {
//             double mid = (hi + lo) / 2;
//             if (check(squares, mid)) {
//                 hi = mid;
//             } else {
//                 lo = mid;
//             }
//         }
//         return hi;
//     }
// };



// 桌上放一堆正方形蛋糕，蛋糕两边与桌子两边平行，你可以横着来一刀，问在哪切可以保证上下两部分的总面积相等。
// 切的刀should be the minimum
// 重叠区域重复算假设每个正方形给你：x_i, y_i, side_i, (x_i y_i) is the bottom-left corner

// the ans doulbe will be in between max(y_i + side_i) min(y_i)
// binary search
// get total area first, the ovelap area can be calculate reapeatedly
// so we don't have to deal with overlap problem 
// define bottom area
// if y_i < cut and [y_i, y_i+side_i] no overlap
// area = side_i^2 else if overlap area = side_i * h - y_i
// time: O(n*log(range))
// space: O(1)

// [[0 0 1]] -> ans 0.5
// [] -> 0.0

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double calculateBottomArea(const vector<vector<int>>& squares, double cut) {
        double bottomArea = 0.0;
        for (const auto& square : squares) {
            int y_i = square[1];
            int side_i = square[2];
            // if square is below the line
            if (y_i < cut) {
                double sqArea = (double)side_i * side_i;
                if (y_i < cut && y_i + side_i > cut) {
                    // overlap
                    sqArea = side_i * (cut - y_i);
                }
                bottomArea += sqArea;
            }
        }
        return bottomArea;
    }

    double separateSquares(vector<vector<int>>& squares) {

        if (squares.size() == 0)
            return 0.0;
        // we don't need tol
        // double tol = 1e-3;

        // get total area first
        // get min(y_i) and max(y_i + side_i)
        int l = INT_MAX/2;
        int r = INT_MIN/2;
        long long total_area = 0;
        for (const auto& square : squares) {
            int y_i = square[1];
            int side_i = square[2];
            l = min(y_i, l);
            r = max(y_i + side_i, r);
            total_area += (long long)side_i * side_i;
        }

        double target_area = total_area/2.0;

        double lBound = (double)l;
        double rBound = (double)r;
        double mid = lBound;
        // a better way is to use tol
        double tol = 1e-5;
        // use for loop without tol is TLE
        // because it will always try to compare two numbers
        // for (int i = 0; i < 10000; i++) {
        while (abs(lBound - rBound) > tol) {
            mid = (lBound + rBound)/2.0;
            double bottomArea = calculateBottomArea(squares, mid);
            // cout << "mid: " << mid << " bottomArea: " << bottomArea << endl;
            // double currResult = total_area - 2.0 * bottomArea;
            // if equal we can still move lower
            if (bottomArea < target_area) {
                // move the line higher
                lBound = mid;
            } else {
                // move the line lower
                rBound = mid;
            }
        }
        return mid;

    }
};

