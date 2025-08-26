class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {

        // max diagonal
        // diagonal sqrt(d1^2, d2^2)

        int ans = 0;
        int curMaxDiagSquare = 0;
        for (auto dimension : dimensions) {
            int curDiagSquare = dimension[0] * dimension[0] + dimension[1] * dimension[1];
            if (curDiagSquare > curMaxDiagSquare) {
                curMaxDiagSquare = curDiagSquare;
                ans = dimension[0] * dimension[1];
            } else if (curDiagSquare == curMaxDiagSquare) {
                ans = max(ans, dimension[0] * dimension[1]);
            }
        }
        return ans;
    }
};