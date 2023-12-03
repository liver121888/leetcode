class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        int diffx = 0;
        int diffy = 0;
        for (int i = 1; i < n; i++) {
            diffx = points[i][0] - points[i - 1][0];
            diffy = points[i][1] - points[i - 1][1];
            while ((abs(diffx) + abs(diffy)) > 0) {
                if (abs(diffx) > 0 && abs(diffy) > 0) {
                    // take diagonal
                    diffx += signbit(diffx) ? 1 : -1;                    
                    diffy += signbit(diffy) ? 1 : -1;
                } else {
                    if (abs(diffx) == 0)
                        diffy += signbit(diffy) ? 1 : -1;  
                    else
                        diffx += signbit(diffx) ? 1 : -1;  
                }                
                ans += 1;
            }
        }
        return ans;
    }
};