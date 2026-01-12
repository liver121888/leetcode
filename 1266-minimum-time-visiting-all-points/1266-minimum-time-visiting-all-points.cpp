// we need to visit the points by order
// we can move diagonally or horizontally or vertically
// we should move diagonally until we have to move horizontal or vertical
// we don't need to simulate, there is a defined solution for this question
// [[1,1],[3,4],[-1,0]]

// abs(3 - 1) = 2, abs(4 - 1) = 3
// we take the max = 3
// abs(-1 - 3) = 4, 0 - 4 = 4
// we take the max = 4

// 3 + 4 = 7
// [[3,2],[-2,2]]
// 5

// what are some edge cases?
// if n == 1
// ans = 0

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 1)
            return 0;
        
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans += max(abs(points[i][0] - points[i-1][0]), 
                abs(points[i][1] - points[i-1][1]));
        }
        return ans;
    }
};